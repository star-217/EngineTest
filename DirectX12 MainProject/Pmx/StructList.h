#pragma once

#include "Base/pch.h"
#include "Base/dxtk.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

/*
-------------------------------------------------------------------------------------
	�\����
-------------------------------------------------------------------------------------
*/
struct PmxData {
	//���ꂼ��̃^�C�v�ۑ�
	byte encord;
	byte addUv;
	byte verticesIndex;
	byte textureIndex;
	byte materialIndex;
	byte boneIndex;
	byte morphIndex;
	byte rigidbodyIndex;
	byte weightType;

	//�e�f�[�^�̐�
	int numVertex;
	int numSurfaces;
	int numTexture;
	int numMaterial;
	int numBone;
	int numLinks;

	//���_�f�[�^�\����
	struct Vertex
	{
		XMFLOAT3 pos;
		XMFLOAT3 normal;
		XMFLOAT2 uv;
		//std::vector<XMFLOAT4> addUv;

		struct Weight {
			enum Type
			{
				BDEF,
				BDEF1,
				BDEF4,
				SDEF
			};

			//Type type;
			int born1;
			int born2;
			int born3;
			int born4;
			float weight1;
			float weight2;
			float weight3;
			float weight4;
			XMFLOAT3 c;
			XMFLOAT3 r0;
			XMFLOAT3 r1;


		}weight;
		float edge;
	};

	//�ʃf�[�^
	struct Surface
	{
		int vertexIndex;
	};

	//�}�e���A���f�[�^
	struct Material
	{
		std::wstring materialPaths;
		XMFLOAT4 diffuse;
		XMFLOAT4 specular;
		XMFLOAT3 ambient;

		byte bitFlag;

		XMFLOAT4 edgeColor;
		float edgeSize;

		byte sphereMode;
		byte toonFlag;

		int colorMapTextureIndex;
		int mapTextureIndex;
		int toonTextureIndex;
		int toonTexture;

		int vertexNum;
	};

	//�V�F�[�_���ɓ�������}�e���A���f�[�^
	struct MaterialForHlsl {
		XMFLOAT4 diffuse; //�f�B�t���[�Y�F
		XMFLOAT4 specular; //�X�y�L�����F
		XMFLOAT3 ambient; //�A���r�G���g�F
	};
	//����ȊO�̃}�e���A���f�[�^
	struct AdditionalMaterial {
		std::string texPath;//�e�N�X�`���t�@�C���p�X
		int toonIdx; //�g�D�[���ԍ�
		bool edgeFlg;//�}�e���A�����̗֊s���t���O
	};
	//�܂Ƃ߂�����
	struct Materials {
		unsigned int indicesNum;//�C���f�b�N�X��
		MaterialForHlsl material;
		AdditionalMaterial additional;
	};

	//�{�[��
	struct Bone
	{
		//�{�[����
		std::wstring name;
		std::wstring nameEnglish;

		XMFLOAT3 pos;
		int parentNo;
		int transformationHierarchy;
		unsigned short flag;

		XMFLOAT3 posOffSet;
		int boneIndexSize;

		int parentBoneIndexSize;
		float grantRate;

		XMFLOAT3 axisvVector;

		XMFLOAT3 xAxisVector;
		XMFLOAT3 zAxizVector;

		int keyIndex;

		//IK
		int ikBoneIndexSize;
		int numLoop;
		float axizLimits;


		struct IKLink
		{
			int linkBoneIndexSize;;
			byte limitFlag;
			XMFLOAT3 lowerLimit;
			XMFLOAT3 higherLimit;
		};
		std::vector<IKLink> ikLinks;

	};

	// �{�[���̏��
	enum boneFlag
	{
		ACCESS_POINT = 0x0001,
		IK = 0x0020,
		IMPART_TRANSLATION = 0x0100,
		IMPART_ROTATION = 0x0200,
		AXIS_FIXING = 0x0400,
		LOCAL_AXIS = 0x0800,
		EXTERNAL_PARENT_TRANS = 0x2000,
	};

	//�e�{�[���f�[�^
	struct BoneNode
	{
		int boneIndex;
		XMFLOAT3 startPos;
		XMFLOAT3 endPos;
		std::vector<BoneNode*> children;
	};

	std::vector<PmxData::Materials> materials;								//�}�e���A���f�[�^
	std::vector<PmxData::MaterialForHlsl> shaderData;						//�V�F�[�_�[�f�[�^						//�{�[���̐ڑ��f�[�^
	std::vector<Vertex> vertices;											//���_�f�[�^
	std::vector<Surface> surfaces;											//�ʃf�[�^
	std::wstring modelName[4];												//���f����
	std::vector<std::wstring> texturePaths;									//�e�N�X�`����
	std::vector<Material> material;											//�}�e���A���f�[�^
	std::vector<Bone> bones;												//�{�[���f�[�^
};

struct VSOUT
{
	XMMATRIX world;
	XMMATRIX view;
	XMMATRIX proj;
};