#pragma once

/*
-------------------------------------------------------------------------------------
	インクルード
-------------------------------------------------------------------------------------
*/
#include "Base/pch.h"
#include "Base/dxtk.h"

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


class ConstantBuffer {
public:

	void Init(int size);
	void Copy();
	void RegistConstantBufferView(D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle);

private:
	//! コンスタントバッファー
	ComPtr<ID3D12Resource> m_constantBuffer;

};