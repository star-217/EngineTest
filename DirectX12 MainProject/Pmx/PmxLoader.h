/**
 * @file PmxLoader.h
 * @brief PMX�ǂݍ��݁��`��
 * @author hoshi hirofumi
 * @date 2021/10/11
 */

#pragma once

 /*
 -------------------------------------------------------------------------------------
	 �C���N���[�h
 -------------------------------------------------------------------------------------
 */
#include "Base/pch.h"
#include "Base/dxtk.h"
#include "StructList.h"

 /*
 -------------------------------------------------------------------------------------
	 using
 -------------------------------------------------------------------------------------
 */
using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;
using namespace DirectX::SimpleMath;

class PmxLoader {
public:
	PmxLoader() {};
	virtual ~PmxLoader() {}

	void Init(const char* fileName);
	PmxData GetModelData() { return m_data; };

private:

	//���f����񃍁[�h
	void Header(FILE* fp);
	void Vertex(FILE* fp);
	void Surface(FILE* fp);
	void Texture(FILE* fp);
	void Material(FILE* fp);
	void Born(FILE* fp);

	//�t�@�C�����C��
	bool GetPMXStringUTF16(FILE* file, std::wstring& output);

	//! �t�@�C���p�X
	std::wstring m_ps;

	//!PMX�t�@�C���f�[�^
	PmxData m_data;
};