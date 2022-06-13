/**
 * @file PmxLoader.cpp
 * @brief PMX読み込み＆描画
 * @author hoshi hirofumi
 * @date 2021/12/14
 */

#include "PmxLoader.h"

#include <array>
#include <d3dcompiler.h>
#include <filesystem>

void PmxLoader::Init(const char* fileName)
{
	std::filesystem::path ps = fileName;
	ps.remove_filename();

	m_ps = ps;

	//ファイルを開く
	FILE* fp;
	fp = fopen(fileName, "rb");

	Header(fp);
	Vertex(fp);
	Surface(fp);
	Texture(fp);
	Material(fp);
	Born(fp);

}

void PmxLoader::Header(FILE* fp)
{
	// ヘッダーチェック
	BYTE header[4];
	fread(header, 4, 1, fp);
	if (memcmp(header, "PMX ", 4) != 0)
		DX::ThrowIfFailed(E_FAIL);

	float ver;
	fread(&ver, sizeof(ver), 1, fp);
	if (ver < 2.0f)
		DX::ThrowIfFailed(E_FAIL);

	fseek(fp, 1, SEEK_CUR);
	fread(&m_data.encord, 1, 1, fp);
	fread(&m_data.addUv, 1, 1, fp);
	fread(&m_data.verticesIndex, 1, 1, fp);
	fread(&m_data.textureIndex, 1, 1, fp);
	fread(&m_data.materialIndex, 1, 1, fp);
	fread(&m_data.boneIndex, 1, 1, fp);
	fread(&m_data.morphIndex, 1, 1, fp);
	fread(&m_data.rigidbodyIndex, 1, 1, fp);

	//モデル情報
	std::wstring m_name;
	for (int i = 0; i < 4; i++)
	{
		GetPMXStringUTF16(fp, m_name);
		m_data.modelName[i] = m_name;
	}
}

void PmxLoader::Vertex(FILE* fp)
{
	// 頂点数を読み込む
	fread(&m_data.numVertex, sizeof(int), 1, fp);

	// 配列を確保する
	m_data.vertices.resize(m_data.numVertex);

	// ファイルから頂点データを取得
	for (int i = 0; i < m_data.numVertex; ++i) {
		fread(&m_data.vertices[i].pos, sizeof(XMFLOAT3), 1, fp);
		fread(&m_data.vertices[i].normal, sizeof(XMFLOAT3), 1, fp);
		fread(&m_data.vertices[i].uv, sizeof(XMFLOAT2), 1, fp);

		byte weighttype;
		fread(&weighttype, 1, 1, fp);

		switch (weighttype) {
		case PmxData::Vertex::Weight::BDEF:
			//_data.vertices[i].weight.type = PmxData::Vertex::Weight::BDEF;
			fread(&m_data.vertices[i].weight.born1, m_data.boneIndex, 1, fp);
			m_data.vertices[i].weight.born2 = -1;
			m_data.vertices[i].weight.born3 = -1;
			m_data.vertices[i].weight.born4 = -1;
			m_data.vertices[i].weight.weight1 = 1.0f;
			break;

		case PmxData::Vertex::Weight::BDEF1:
			//_data.vertices[i].weight.type = PmxData::Vertex::Weight::BDEF1;
			fread(&m_data.vertices[i].weight.born1, m_data.boneIndex, 1, fp);
			fread(&m_data.vertices[i].weight.born2, m_data.boneIndex, 1, fp);
			m_data.vertices[i].weight.born3 = -1;
			m_data.vertices[i].weight.born4 = -1;
			fread(&m_data.vertices[i].weight.weight1, 4, 1, fp);
			m_data.vertices[i].weight.weight2 = 1.0f - m_data.vertices[i].weight.weight1;
			break;

		case PmxData::Vertex::Weight::BDEF4:
			//_data.vertices[i].weight.type = PmxData::Vertex::Weight::BDEF4;
			fread(&m_data.vertices[i].weight.born1, m_data.boneIndex, 1, fp);
			fread(&m_data.vertices[i].weight.born2, m_data.boneIndex, 1, fp);
			fread(&m_data.vertices[i].weight.born3, m_data.boneIndex, 1, fp);
			fread(&m_data.vertices[i].weight.born4, m_data.boneIndex, 1, fp);
			fread(&m_data.vertices[i].weight.weight1, 4, 1, fp);
			fread(&m_data.vertices[i].weight.weight2, 4, 1, fp);
			fread(&m_data.vertices[i].weight.weight3, 4, 1, fp);
			fread(&m_data.vertices[i].weight.weight4, 4, 1, fp);
			break;

		case PmxData::Vertex::Weight::SDEF:
			//_data.vertices[i].weight.type = PmxData::Vertex::Weight::SDEF;
			fread(&m_data.vertices[i].weight.born1, m_data.boneIndex, 1, fp);
			fread(&m_data.vertices[i].weight.born2, m_data.boneIndex, 1, fp);
			fread(&m_data.vertices[i].weight.weight1, 4, 1, fp);
			m_data.vertices[i].weight.weight2 = 1.0f - m_data.vertices[i].weight.weight1;
			fread(&m_data.vertices[i].weight.c, 12, 1, fp);
			fread(&m_data.vertices[i].weight.r0, 12, 1, fp);
			fread(&m_data.vertices[i].weight.r1, 12, 1, fp);
			break;

		}
		fread(&m_data.vertices[i].edge, 4, 1, fp);
	}
}

void PmxLoader::Surface(FILE* fp)
{
	//面
	fread(&m_data.numSurfaces, 4, 1, fp);
	m_data.surfaces.resize(m_data.numSurfaces);
	for (int i = 0; i < m_data.numSurfaces; i++)
		fread(&m_data.surfaces[i].vertexIndex, m_data.verticesIndex, 1, fp);
}

void PmxLoader::Texture(FILE* fp)
{
	//テクスチャ
	fread(&m_data.numTexture, 4, 1, fp);
	m_data.texturePaths.resize(m_data.numTexture);
	std::wstring texturePath{};
	for (int i = 0; i < m_data.numTexture; i++)
	{
		GetPMXStringUTF16(fp, texturePath);

		m_data.texturePaths[i] += texturePath;
	}
}

void PmxLoader::Material(FILE* fp)
{
	//マテリアル
	fread(&m_data.numMaterial, 4, 1, fp);
	m_data.material.resize(m_data.numMaterial);
	std::wstring materialPath{};
	for (int i = 0; i < m_data.numMaterial; i++)
	{
		for (int k = 0; k < 2; k++) {
			GetPMXStringUTF16(fp, materialPath);
			m_data.material[i].materialPaths += materialPath;
		}

		fread(&m_data.material[i].diffuse, 16, 1, fp);
		fread(&m_data.material[i].specular, 16, 1, fp);
		fread(&m_data.material[i].ambient, 12, 1, fp);

		fread(&m_data.material[i].bitFlag, 1, 1, fp);
		fread(&m_data.material[i].edgeColor, 16, 1, fp);
		fread(&m_data.material[i].edgeSize, 4, 1, fp);
		fread(&m_data.material[i].colorMapTextureIndex, m_data.textureIndex, 1, fp);
		fread(&m_data.material[i].mapTextureIndex, m_data.textureIndex, 1, fp);

		fread(&m_data.material[i].sphereMode, 1, 1, fp);

		fread(&m_data.material[i].toonFlag, 1, 1, fp);

		if (m_data.material[i].toonFlag)
			fread(&m_data.material[i].toonTextureIndex, 1, 1, fp);
		else {
			fread(&m_data.material[i].toonTexture, m_data.textureIndex, 1, fp);
		}
		int memo;
		fread(&memo, 4, 1, fp);
		fseek(fp, memo, SEEK_CUR);
		fread(&m_data.material[i].vertexNum, 4, 1, fp);
	}
}

void PmxLoader::Born(FILE* fp)
{
	//ボーン
	fread(&m_data.numBone, 4, 1, fp);
	m_data.bones.resize(m_data.numBone);
	std::wstring mate_name;
	for (int i = 0; i < m_data.numBone; i++)
	{
		GetPMXStringUTF16(fp, mate_name);
		m_data.bones[i].name += mate_name;

		GetPMXStringUTF16(fp, mate_name);
		m_data.bones[i].nameEnglish += mate_name;

		fread(&m_data.bones[i].pos, 12, 1, fp);
		fread(&m_data.bones[i].parentNo, m_data.boneIndex, 1, fp);
		fread(&m_data.bones[i].transformationHierarchy, 4, 1, fp);
		fread(&m_data.bones[i].flag, 2, 1, fp);

		if (m_data.bones[i].flag & PmxData::ACCESS_POINT)
		{
			fread(&m_data.bones[i].boneIndexSize, m_data.boneIndex, 1, fp);
		}
		else
		{
			m_data.bones[i].boneIndexSize = -1;
			fread(&m_data.bones[i].posOffSet, 12, 1, fp);
		}

		if ((m_data.bones[i].flag & PmxData::IMPART_TRANSLATION) || (m_data.bones[i].flag & PmxData::IMPART_ROTATION))
		{
			fread(&m_data.bones[i].parentBoneIndexSize, m_data.boneIndex, 1, fp);
			fread(&m_data.bones[i].grantRate, 4, 1, fp);
		}

		if (m_data.bones[i].flag & PmxData::AXIS_FIXING)
			fread(&m_data.bones[i].axisvVector, 12, 1, fp);

		if (m_data.bones[i].flag & PmxData::LOCAL_AXIS) {
			fread(&m_data.bones[i].xAxisVector, 12, 1, fp);
			fread(&m_data.bones[i].zAxizVector, 12, 1, fp);
		}

		if (m_data.bones[i].flag & PmxData::EXTERNAL_PARENT_TRANS)
			fread(&m_data.bones[i].keyIndex, 4, 1, fp);

		if (m_data.bones[i].flag & PmxData::IK)
		{
			fread(&m_data.bones[i].ikBoneIndexSize, m_data.boneIndex, 1, fp);
			fread(&m_data.bones[i].numLoop, 4, 1, fp);
			fread(&m_data.bones[i].axizLimits, 4, 1, fp);
			fread(&m_data.numLinks, 4, 1, fp);
			m_data.bones[i].ikLinks.resize(m_data.numLinks);

			for (int j = 0; j < m_data.numLinks; j++)
			{
				fread(&m_data.bones[i].ikLinks[j].linkBoneIndexSize, m_data.boneIndex, 1, fp);
				fread(&m_data.bones[i].ikLinks[j].limitFlag, 1, 1, fp);

				if (m_data.bones[i].ikLinks[j].limitFlag) {
					fread(&m_data.bones[i].ikLinks[j].lowerLimit, 12, 1, fp);
					fread(&m_data.bones[i].ikLinks[j].higherLimit, 12, 1, fp);

				}
			}
		}
	}
	fclose(fp);
	m_data.materials.resize(m_data.material.size());
}

bool PmxLoader::GetPMXStringUTF16(FILE* file, std::wstring& output)
{
	if (file == NULL)
		return false;

	std::array<wchar_t, 512> wBuffer{};
	int a;

	fread(&a, sizeof(a), 1, file);

	fread(&wBuffer, a, 1, file);

	output = std::wstring(wBuffer.data());
	wchar_t chars[] = L"\\";

	int i = output.find(chars);
	if (i != -1)
		output.replace(i, 1, L"/");

	return true;
}
