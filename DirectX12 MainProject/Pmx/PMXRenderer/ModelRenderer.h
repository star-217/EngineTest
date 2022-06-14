#pragma once

/*
-------------------------------------------------------------------------------------
	インクルード
-------------------------------------------------------------------------------------
*/
#include "Base/pch.h"
#include "Base/dxtk.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ConstantBuffer.h"
#include "../StructList.h"
#include "Pmx/PmxLoader.h"

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

class ModelRenderer {
public:
	void Init(const char* fileName);
	void Draw();

private:

	VertexBuffer m_vBuff;
	IndexBuffer m_iBuff;
	ConstantBuffer m_cBuff;
	PmxLoader m_pmxLoader;

	PmxData m_modelData;

	unique_ptr<DescriptorHeap> descHeaps;
};

#define PMX ModelRenderer;