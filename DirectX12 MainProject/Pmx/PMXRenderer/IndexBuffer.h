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

class IndexBuffer {
public:
	IndexBuffer() {};
	virtual ~IndexBuffer() {};

	void Init(int size);
	void Copy(void* data);
	D3D12_INDEX_BUFFER_VIEW GetView() { return m_indexBufferView; }
	UINT GetCount() { return m_indexCount; }

private:

	ComPtr<ID3D12Resource>		m_indexBuffer;
	D3D12_INDEX_BUFFER_VIEW		m_indexBufferView;
	UINT m_indexCount;
};