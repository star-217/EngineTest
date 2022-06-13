/**
 * @file PmxLoader.h
 * @brief PMX読み込み＆描画
 * @author hoshi hirofumi
 * @date 2021/10/11
 */

#pragma once

 /*
 -------------------------------------------------------------------------------------
	 インクルード
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

	//モデル情報ロード
	void Header(FILE* fp);
	void Vertex(FILE* fp);
	void Surface(FILE* fp);
	void Texture(FILE* fp);
	void Material(FILE* fp);
	void Born(FILE* fp);

	//ファイル名修正
	bool GetPMXStringUTF16(FILE* file, std::wstring& output);

	//! ファイルパス
	std::wstring m_ps;

	//!PMXファイルデータ
	PmxData m_data;
};