struct VSInput
{
	float3 Position : POSITION;	//座標
	float4 Color    : COLOR;    //頂点カラー
};

struct VSOutput
{
	float4 Position : SV_POSITION;
	float4 Color    : COLOR;
};

cbuffer Transform : register(b0)
{
	matrix World : packoffset(c0);
	matrix View  : packoffset(c4);
	matrix Proj  : packoffset(c8);
}
//-----------------------------------------------------------------------------
//			頂点シェーダーのエントリーポイント
//-----------------------------------------------------------------------------
VSOutput main(VSInput input)
{
	VSOutput output = (VSOutput)0;

	float4  localPos = float4(input.Position, 1.0f);
	float4  worldPos = mul(World, localPos);
	float4  viewPos = mul(View, worldPos);
	float4  projPos = mul(Proj, viewPos);

	output.Position = projPos;
	output.Color = input.Color;

	return output;
}