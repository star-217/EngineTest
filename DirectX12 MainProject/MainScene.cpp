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
	const float k = 1.0f;
	const DirectX::XMFLOAT4 red(1.0f, 0.0f, 0.0f, 1.0f);
	const DirectX::XMFLOAT4 green(0.0f, 1.0f, 0.0f, 1.0f);
	const DirectX::XMFLOAT4 blue(0.0f, 0.0f, 1.0f, 1.0);
	const DirectX::XMFLOAT4 white(1.0f, 1.0f, 1.0f, 1.0f);
	const DirectX::XMFLOAT4 black(0.0f, 0.0f, 0.0f, 1.0f);
	const DirectX::XMFLOAT4 yellow(1.0f, 1.0f, 0.0f, 1.0f);
	const DirectX::XMFLOAT4 magenta(1.0f, 0.0f, 1.0f, 1.0f);
	const DirectX::XMFLOAT4 cyan(0.0f, 1.0f, 1.0f, 1.0f);


	Vertex triangleVertices[] = {
		// ����
		  { {-k,-k,-k}, red, { 0.0f, 1.0f} },
		  { {-k, k,-k}, yellow, { 0.0f, 0.0f} },
		  { { k, k,-k}, white, { 1.0f, 0.0f} },
		  { { k,-k,-k}, magenta, { 1.0f, 1.0f} },
		  // �E
		  { { k,-k,-k}, magenta, { 0.0f, 1.0f} },
		  { { k, k,-k}, white, { 0.0f, 0.0f} },
		  { { k, k, k}, cyan, { 1.0f, 0.0f} },
		  { { k,-k, k}, blue, { 1.0f, 1.0f} },
		  // ��
		  { {-k,-k, k}, black, { 0.0f, 1.0f} },
		  { {-k, k, k}, green, { 0.0f, 0.0f} },
		  { {-k, k,-k}, yellow, { 1.0f, 0.0f} },
		  { {-k,-k,-k}, red, { 1.0f, 1.0f} },
		  // ��
		  { { k,-k, k}, blue, { 0.0f, 1.0f} },
		  { { k, k, k}, cyan, { 0.0f, 0.0f} },
		  { {-k, k, k}, green, { 1.0f, 0.0f} },
		  { {-k,-k, k}, black, { 1.0f, 1.0f} },
		  // ��
		  { {-k, k,-k}, yellow, { 0.0f, 1.0f} },
		  { {-k, k, k}, green, { 0.0f, 0.0f} },
		  { { k, k, k}, cyan, { 1.0f, 0.0f} },
		  { { k, k,-k}, white, { 1.0f, 1.0f} },
		  // ��
		  { {-k,-k, k}, red, { 0.0f, 1.0f} },
		  { {-k,-k,-k}, red, { 0.0f, 0.0f} },
		  { { k,-k,-k}, magenta, { 1.0f, 0.0f} },
		  { { k,-k, k}, blue, { 1.0f, 1.0f} },
	};

	uint32_t indices[] = {
	0, 1, 2, 2, 3,0,
	4, 5, 6, 6, 7,4,
	8, 9, 10, 10, 11, 8,
	12,13,14, 14,15,12,
	16,17,18, 18,19,16,
	20,21,22, 22,23,20,
	};

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

	m_resourceDescriptors = make_unique<DescriptorHeap>(DXTK->Device, 1);

	m_vertexBuff.Init(sizeof(triangleVertices), sizeof(Vertex));
	m_vertexBuff.Copy(triangleVertices);
	m_indexBuff.Init(sizeof(indices));
	m_indexBuff.Copy(indices);


	//�f�X�N���v�^�[�����W
	CD3DX12_DESCRIPTOR_RANGE cbv, srv, sampler;
	cbv.Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0);//RangeType,NumDesc,ShaderRagister b0���W�X�^
	srv.Init(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1, 0);//t0 ���W�X�^
	sampler.Init(D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER, 1, 0);//s0 ���W�X�^

	//���[�g�p�����[�^�[
	CD3DX12_ROOT_PARAMETER rootParam[3] = {};
	rootParam[0].InitAsDescriptorTable(1, &cbv,D3D12_SHADER_VISIBILITY_VERTEX);// NumDescRange,pDescRange
	rootParam[1].InitAsDescriptorTable(1, &srv, D3D12_SHADER_VISIBILITY_PIXEL);
	rootParam[2].InitAsDescriptorTable(1, &sampler, D3D12_SHADER_VISIBILITY_PIXEL);

	//�T���v���[
	CD3DX12_STATIC_SAMPLER_DESC samplerDesc = {};
	samplerDesc.Init(0);

	//���[�g�V�O�l�`���̍\�z
	CD3DX12_ROOT_SIGNATURE_DESC rootSigDesc{};
	rootSigDesc.Init(
		_countof(rootParam), rootParam, //pParameters
		1, &samplerDesc, //pStaticSamplers
		D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT
	);
	ComPtr<ID3DBlob> signature;
	hr = D3D12SerializeRootSignature(&rootSigDesc, D3D_ROOT_SIGNATURE_VERSION_1_0, &signature, &errBlob);
	if (FAILED(hr))
	{
		throw std::runtime_error("D3D12SerializeRootSignature faild");
	}
	//RootSignature�̐���
	hr = DirectX::CreateRootSignature(
		DXTK->Device,
		&rootSigDesc,
		m_rootSignature.ReleaseAndGetAddressOf()
	);
	if (FAILED(hr))
	{
		throw std::runtime_error("CreateRootSignature failed");
	}
	// �C���v�b�g���C�A�E�g
	D3D12_INPUT_ELEMENT_DESC inputElementDesc[] = {
		{"POSITION",0,DXGI_FORMAT_R32G32B32A32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0},
		{"COLOR",0,DXGI_FORMAT_R32G32B32A32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0},
		{"TEXCOORD",0,DXGI_FORMAT_R32G32B32A32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0}
	};
	// �p�C�v���C���X�e�[�g�I�u�W�F�N�g�̐���
	D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc{};
	//�����_�[�^�[�Q�b�g�u�����h����
	D3D12_RENDER_TARGET_BLEND_DESC renderTargetBlendDesc = {};
	renderTargetBlendDesc.BlendEnable = false;
	renderTargetBlendDesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
	renderTargetBlendDesc.LogicOpEnable = false;
	//�p�C�v���C�������_�[�^�[�Q�b�g
	psoDesc.BlendState.RenderTarget[0] = renderTargetBlendDesc;
	//�V�F�[�_�[�̃Z�b�g
	psoDesc.VS = CD3DX12_SHADER_BYTECODE(m_vs.Get());
	psoDesc.PS = CD3DX12_SHADER_BYTECODE(m_ps.Get());
	//�u�����h�X�e�[�g�ݒ�
	psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
	//���X�^���C�U�[�X�e�[�g
	psoDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
	//�o�͐ݒ�
	psoDesc.NumRenderTargets = 1;
	psoDesc.RTVFormats[0] = DXGI_FORMAT_B8G8R8A8_UNORM;
	//�f�v�X�o�b�t�@�̃t�H�[�}�b�g�ݒ�
	psoDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;
	psoDesc.InputLayout = { inputElementDesc,_countof(inputElementDesc) };
	psoDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
	//���[�g�V�O�l�`���̃Z�b�g
	psoDesc.pRootSignature = m_rootSignature.Get();
	psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	//�}���`�T���v���ݒ�
	psoDesc.SampleDesc = { 1,0 };
	psoDesc.SampleMask = UINT_MAX;
	hr = DXTK->Device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(m_pipeline.ReleaseAndGetAddressOf()));
	if (FAILED(hr))
	{
		throw std::runtime_error("CreateGraphicsPipelineState failed");
	}
	//�R���X�^���g�o�b�t�@�[
	m_constantBuff.Init(sizeof(VSOUT));
	auto descAddr = m_resourceDescriptors->GetCpuHandle(0);
	m_constantBuff.RegistConstantBufferView(descAddr);

	m_resourceDescriptors = make_unique<DescriptorHeap>(DXTK->Device, 1);
	m_textureDescriptors = make_unique<DescriptorHeap>(DXTK->Device, 1);

	//�e�N�X�`��
	ResourceUploadBatch resourceUpload(DXTK->Device);
	resourceUpload.Begin();
	DX12::CreateTextureSRV(
		DXTK->Device, L"texture.tga",
		resourceUpload, m_textureDescriptors.get(),
		1, m_tex.ReleaseAndGetAddressOf()
	);

	auto uploadResourcesFinished = resourceUpload.End(DXTK->CommandQueue);
	uploadResourcesFinished.wait();

	// �e�s��̃Z�b�g.
	VSOUT shaderParams;
	XMStoreFloat4x4(&shaderParams.mtxWorld, XMMatrixRotationAxis(XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f), XMConvertToRadians(45.0f)));
	auto mtxView = XMMatrixLookAtLH(
		XMVectorSet(0.0f, 3.0f, -5.0f, 0.0f),
		XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f),
		XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f)
	);
	auto mtxProj = XMMatrixPerspectiveFovLH(XMConvertToRadians(45.0f), 1280 / 720, 0.1f, 100.0f);
	XMStoreFloat4x4(&shaderParams.mtxView, XMMatrixTranspose(mtxView));
	XMStoreFloat4x4(&shaderParams.mtxProj, XMMatrixTranspose(mtxProj));

	VSOUT* mapBuffer = nullptr;
	m_constantBuffer->Map(0, nullptr, (void**)&mapBuffer);
	memcpy(mapBuffer, &shaderParams, sizeof(shaderParams));
	m_constantBuffer->Unmap(0, nullptr);

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
	//���Ƃŗ��ɉ�
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
	//�p�C�v���C���X�e�[�g�Z�b�g
	DXTK->CommandList->SetPipelineState(m_pipeline.Get());
	//���[�g�V�O�l�`���Z�b�g
	DXTK->CommandList->SetGraphicsRootSignature(m_rootSignature.Get());
	// �v���~�e�B�u�^�C�v�A���_�E�C���f�b�N�X�o�b�t�@�̃Z�b�g
	DXTK->CommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	auto b = m_vertexBuff.GetView();
	DXTK->CommandList->IASetVertexBuffers(0, 1, &b);
	auto a = m_indexBuff.GetView();
	DXTK->CommandList->IASetIndexBuffer(&a);
	//�`�施��
	DXTK->CommandList->DrawIndexedInstanced(m_indexBuff.GetCount(), 1, 0, 0, 0);

	DXTK->ExecuteCommandList();
}
