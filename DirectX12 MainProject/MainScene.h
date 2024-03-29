//
// MainScene.h
//

#pragma once

#include "Scene.h"
#include "Pmx/PMXRenderer/ModelRenderer.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class MainScene final : public Scene {
public:
	MainScene();
	virtual ~MainScene() { Terminate(); }

	MainScene(MainScene&&) = default;
	MainScene& operator= (MainScene&&) = default;

	MainScene(MainScene const&) = delete;
	MainScene& operator= (MainScene const&) = delete;

	// These are the functions you will implement.
	void Initialize() override;
	void LoadAssets() override;

	void Terminate() override;

	void OnDeviceLost() override;
	void OnRestartSound() override;

	NextScene Update(const float deltaTime) override;
	void Render() override;

private:
	ModelRenderer reimu;

	struct Vertex
	{
		DirectX::XMFLOAT3 Pos;
		DirectX::XMFLOAT4 Color;
		DirectX::XMFLOAT2 UV;
	};
	struct VSOUT
	{
		DirectX::XMFLOAT4X4 mtxWorld;
		DirectX::XMFLOAT4X4 mtxView;
		DirectX::XMFLOAT4X4 mtxProj;
	};
	VertexBuffer m_vertexBuff;
	IndexBuffer  m_indexBuff;
	ConstantBuffer m_constantBuff;
	Shader	     m_shader;

	ComPtr<ID3DBlob>  m_vs, m_ps;
	ComPtr<ID3D12RootSignature> m_rootSignature;
	ComPtr<ID3D12PipelineState> m_pipeline;

	unique_ptr<DescriptorHeap>  m_heapSrvCbv;
	unique_ptr<DescriptorHeap>  m_heapSampler;

	//! コンスタントバッファー
	ComPtr<ID3D12Resource> m_constantBuffer;
	//! テクスチャ
	ComPtr<ID3D12Resource> m_tex;
};