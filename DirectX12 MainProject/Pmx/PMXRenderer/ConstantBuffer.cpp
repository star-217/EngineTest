#include "ConstantBuffer.h"

void ConstantBuffer::Init(int size)
{
	//ConstantBuffer‚Ì¶¬
	HRESULT result;
	auto heapProp = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	auto rDesc = CD3DX12_RESOURCE_DESC::Buffer(size);

	result = DXTK->Device->CreateCommittedResource(
		&heapProp,
		D3D12_HEAP_FLAG_NONE,
		&rDesc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(m_constantBuffer.ReleaseAndGetAddressOf())
	);
	DX::ThrowIfFailed(result);


}

void ConstantBuffer::Copy()
{
}

void ConstantBuffer::RegistConstantBufferView(D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle)
{
	//ConstantBufferView‚Ì¶¬
	auto desc_addr = cpuHandle;

	D3D12_CONSTANT_BUFFER_VIEW_DESC cbv_desc{};
	cbv_desc.BufferLocation = m_constantBuffer->GetGPUVirtualAddress();
	cbv_desc.SizeInBytes = (UINT)m_constantBuffer->GetDesc().Width;
	DXTK->Device->CreateConstantBufferView(&cbv_desc, desc_addr);
}
