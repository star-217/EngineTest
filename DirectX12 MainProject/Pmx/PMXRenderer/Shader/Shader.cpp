#include "Shader.h"
#include <d3dcompiler.h>
#pragma comment(lib,"d3dcompiler.lib")

void Shader::Init()
{
	HRESULT result;

	ComPtr<ID3DBlob> errorBlob;
	result = D3DCompileFromFile(
		L"VS.hlsl",
		nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
		"BasicVS", "vs_5_0",
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, 0,
		vsBlob.ReleaseAndGetAddressOf(),
		errorBlob.ReleaseAndGetAddressOf()
	);
	DX::ThrowIfFailed(result);

	result = D3DCompileFromFile(
		L"PS.hlsl",
		nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
		"BasicPS", "ps_5_0",
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, 0,
		psBlob.ReleaseAndGetAddressOf(),
		errorBlob.ReleaseAndGetAddressOf()
	);
	DX::ThrowIfFailed(result);
}

