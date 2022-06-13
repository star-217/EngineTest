#include "IndexBuffer.h"

void IndexBuffer::Init(int size, int stride)
{
	//IndexBuffer‚Ì¶¬
	HRESULT result;
	auto heapProp = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	auto rDesc = CD3DX12_RESOURCE_DESC::Buffer(size);

	result = DXTK->Device->CreateCommittedResource(
		&heapProp,
		D3D12_HEAP_FLAG_NONE,
		&rDesc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(m_indexBuffer.ReleaseAndGetAddressOf()));
	DX::ThrowIfFailed(result);

	m_indexBufferView.BufferLocation = m_indexBuffer->GetGPUVirtualAddress();
	m_indexBufferView.Format = DXGI_FORMAT_R32_UINT;
	m_indexBufferView.SizeInBytes = size;

}

void IndexBuffer::Copy(void* data)
{
	//IndexBuffer‚Ì‘‚«o‚µ
	void* map_addr = nullptr;
	m_indexBuffer->Map(0, nullptr, &map_addr);
	memcpy(map_addr, data, m_indexBufferView.SizeInBytes);
	m_indexBuffer->Unmap(0, nullptr);
}
