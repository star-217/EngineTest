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

class VertexBuffer {
public:
	VertexBuffer() {};
	virtual ~VertexBuffer() {};

	void Init(int size,int stride);
	void Copy(void* data);

private:

	ComPtr<ID3D12Resource>		m_vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW	m_vertexBufferView;
};