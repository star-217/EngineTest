#include "ModelRenderer.h"

void ModelRenderer::Init(const char* fileName)
{
	m_pmxLoader.Init(fileName);

	m_modelData = m_pmxLoader.GetModelData();

	m_vBuff.Init(m_modelData.numVertex, 4);
	m_iBuff.Init(m_modelData.numSurfaces, 4);
	m_cBuff.Init()
}
