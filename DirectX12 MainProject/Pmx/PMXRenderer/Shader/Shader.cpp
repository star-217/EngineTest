#include "Shader.h"
#include <dxcapi.h>
#include <fstream>
#pragma comment(lib, "dxcompiler.lib")

#include <filesystem>

using namespace std::filesystem;

HRESULT Shader::Init(
    const std::wstring& fileName, const std::wstring& profile,
    ComPtr<ID3DBlob>& shaderBlob, ComPtr<ID3DBlob>& errorBlob)
{


    path filePath(fileName);
    std::ifstream infile(filePath);
    std::vector<char> srcData;
    if (!infile)
        throw std::runtime_error("shader not found");
    srcData.resize(uint32_t(infile.seekg(0, infile.end).tellg()));
    infile.seekg(0, infile.beg).read(srcData.data(), srcData.size());

    // DXC によるコンパイル処理
    ComPtr<IDxcLibrary> library;
    ComPtr<IDxcCompiler> compiler;
    ComPtr<IDxcBlobEncoding> source;
    ComPtr<IDxcOperationResult> dxcResult;

    DxcCreateInstance(CLSID_DxcLibrary, IID_PPV_ARGS(&library));
    library->CreateBlobWithEncodingFromPinned(srcData.data(), UINT(srcData.size()), CP_ACP, &source);
    DxcCreateInstance(CLSID_DxcCompiler, IID_PPV_ARGS(&compiler));

    LPCWSTR compilerFlags[] = {
  #if _DEBUG
      L"/Zi", L"/O0",
  #else
      L"/O2" // リリースビルドでは最適化
  #endif
    };
    compiler->Compile(source.Get(), filePath.wstring().c_str(),
        L"main", profile.c_str(),
        compilerFlags, _countof(compilerFlags),
        nullptr, 0, // Defines
        nullptr,
        &dxcResult);

    HRESULT hr;
    dxcResult->GetStatus(&hr);
    if (SUCCEEDED(hr))
    {
        dxcResult->GetResult(
            reinterpret_cast<IDxcBlob**>(shaderBlob.GetAddressOf())
        );
    }
    else
    {
        dxcResult->GetErrorBuffer(
            reinterpret_cast<IDxcBlobEncoding**>(errorBlob.GetAddressOf())
        );
    }
    return hr;

}

