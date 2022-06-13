struct VSOUT
{
	float4 svpos : SV_POSITION;
	float4 normal : NORMAL;
	float2 uv     : TEXCOORD;
};

cbuffer cbuff: register(b0) {

	matrix world;
	matrix view;
	matrix proj;
}

VSOUT BasicVS(float4 pos : POSITION, float2 uv : TEXCOORD)
{
	VSOUT vsout;
	vsout.svpos = mul(world, pos);
	vsout.svpos = mul(view, vsout.svpos);
	vsout.svpos = mul(proj, vsout.svpos);

	//vsout.normal = mul(world, normal);
	vsout.uv = uv;

	return vsout;
}