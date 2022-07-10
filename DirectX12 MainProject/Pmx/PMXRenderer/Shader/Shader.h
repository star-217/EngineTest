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

class Shader {

public:
	HRESULT Init(const std::wstring& fileName, const std::wstring& profile, ComPtr<ID3DBlob>& shaderBlob, ComPtr<ID3DBlob>& errorBlob);

private:

};