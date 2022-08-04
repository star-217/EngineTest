//
// MainScene.cpp
//

#include "Base/pch.h"
#include "Base/dxtk.h"
#include "SceneFactory.h"

// Initialize member variables.
MainScene::MainScene()
{

}

// Initialize a variable and audio resources.
void MainScene::Initialize()
{

	Vertex triangleVertices[] = {
  { {  0.0f, 0.25f, 0.5f }, { 1.0f, 0.0f,0.0f,1.0f} },
  { { 0.25f,-0.25f, 0.5f }, { 0.0f, 1.0f,0.0f,1.0f} },
  { {-0.25f,-0.25f, 0.5f }, { 0.0f, 0.0f,1.0f,1.0f} },
	};

	uint32_t indices[] = { 0, 1, 2 };

	m_resourceDescriptors = make_unique<DescriptorHeap>(DXTK->Device, 1);

	m_vertexBuff.Init(sizeof(triangleVertices), sizeof(Vertex));
	m_vertexBuff.Copy(triangleVertices);
	m_indexBuff.Init(sizeof(indices));
	m_indexBuff.Copy(indices);


	HRESULT hr;
	ComPtr<ID3DBlob> errBlob;
	hr = m_shader.Init(L"Shader/test2cubeTex/VS.hlsl", L"vs_6_0", m_vs, errBlob);
	if (FAILED(hr))
	{
		OutputDebugStringA((const char*)errBlob->GetBufferPointer());
	}
	hr = m_shader.Init(L"Shader/test2cubeTex/PS.hlsl", L"ps_6_0", m_ps, errBlob);
	if (FAILED(hr))
	{
		OutputDebugStringA((const char*)errBlob->GetBufferPointer());
	}
	//デスクリプターレンジ
	CD3DX12_DESCRIPTOR_RANGE descRange = {};
	descRange.Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0);//RangeType,NumDesc,ShaderRagister

	//ルートパラメーター
	CD3DX12_ROOT_PARAMETER rootParam = {};
	rootParam.InitAsDescriptorTable(1, &descRange);// NumDescRange,pDescRange

	//サンプラー
	CD3DX12_STATIC_SAMPLER_DESC samplerDesc = {};
	samplerDesc.Init(0);

	//ルートシグネチャの構築
	CD3DX12_ROOT_SIGNATURE_DESC rootSigDesc{};
	rootSigDesc.Init(
		1, &rootParam, //pParameters
		1, &samplerDesc, //pStaticSamplers
		D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT
	);
	ComPtr<ID3DBlob> signature;
	hr = D3D12SerializeRootSignature(&rootSigDesc, D3D_ROOT_SIGNATURE_VERSION_1_0, &signature, &errBlob);
	if (FAILED(hr))
	{
		throw std::runtime_error("D3D12SerializeRootSignature faild");
	}
	//RootSignatureの生成
	hr = DirectX::CreateRootSignature(
		DXTK->Device,
		&rootSigDesc,
		m_rootSignature.ReleaseAndGetAddressOf()
	);
	if (FAILED(hr))
	{
		throw std::runtime_error("CreateRootSignature failed");
	}
	// インプットレイアウト
	D3D12_INPUT_ELEMENT_DESC inputElementDesc[] = {
		{"POSITION",0,DXGI_FORMAT_R32G32B32A32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0},
		{"COLOR",0,DXGI_FORMAT_R32G32B32A32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0}
	};
	// パイプラインステートオブジェクトの生成
	D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc{};
	//レンダーターゲットブレンド生成
	D3D12_RENDER_TARGET_BLEND_DESC renderTargetBlendDesc = {};
	renderTargetBlendDesc.BlendEnable = false;
	renderTargetBlendDesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
	renderTargetBlendDesc.LogicOpEnable = false;
	//パイプラインレンダーターゲット
	psoDesc.BlendState.RenderTarget[0] = renderTargetBlendDesc;
	//シェーダーのセット
	psoDesc.VS = CD3DX12_SHADER_BYTECODE(m_vs.Get());
	psoDesc.PS = CD3DX12_SHADER_BYTECODE(m_ps.Get());
	//ブレンドステート設定
	psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
	//ラスタライザーステート
	psoDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
	//出力設定
	psoDesc.NumRenderTargets = 1;
	psoDesc.RTVFormats[0] = DXGI_FORMAT_B8G8R8A8_UNORM;
	//デプスバッファのフォーマット設定
	psoDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;
	psoDesc.InputLayout = { inputElementDesc,_countof(inputElementDesc) };
	psoDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
	//ルートシグネチャのセット
	psoDesc.pRootSignature = m_rootSignature.Get();
	psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	//マルチサンプル設定
	psoDesc.SampleDesc = { 1,0 };
	psoDesc.SampleMask = UINT_MAX;
	hr = DXTK->Device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(m_pipeline.ReleaseAndGetAddressOf()));
	if (FAILED(hr))
	{
		throw std::runtime_error("CreateGraphicsPipelineState failed");
	}
}

// Allocate all memory the Direct3D and Direct2D resources.
void MainScene::LoadAssets()
{

}

// Releasing resources required for termination.
void MainScene::Terminate()
{
	DXTK->ResetAudioEngine();
	DXTK->WaitForGpu();

	// TODO: Add your Termination logic here.

}

// Direct3D resource cleanup.
void MainScene::OnDeviceLost()
{

}

// Restart any looped sounds here
void MainScene::OnRestartSound()
{

}

// Updates the scene.
NextScene MainScene::Update(const float deltaTime)
{
	//あとで裏に回す
#if defined(DEBUG) || defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif//defined(DEBUG) || defined(_DEBUG)

	// If you use 'deltaTime', remove it.
	UNREFERENCED_PARAMETER(deltaTime);
	// TODO: Add your game logic here.



	return NextScene::Continue;
}

// Draws the scene.
void MainScene::Render()
{
	// TODO: Add your rendering code here.
	DXTK->ResetCommand();
	DXTK->ClearRenderTarget(Colors::CornflowerBlue);
	//パイプラインステートセット
	DXTK->CommandList->SetPipelineState(m_pipeline.Get());
	//ルートシグネチャセット
	DXTK->CommandList->SetGraphicsRootSignature(m_rootSignature.Get());
	// プリミティブタイプ、頂点・インデックスバッファのセット
	DXTK->CommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	auto b = m_vertexBuff.GetView();
	DXTK->CommandList->IASetVertexBuffers(0, 1, &b);
	auto a = m_indexBuff.GetView();
	DXTK->CommandList->IASetIndexBuffer(&a);
	//描画命令
	DXTK->CommandList->DrawIndexedInstanced(m_indexBuff.GetCount(), 1, 0, 0, 0);

	DXTK->ExecuteCommandList();
}
