#ifndef _GLOBAL_FX_
#define _GLOBAL_FX_
//////////////////
//ConstantBuffer//
//////////////////

cbuffer GlobalBuffer
{
    matrix V;  //view 
    matrix P;  // projection
    matrix VP; //view projection
    matrix Vinv; //view inverse  
};

cbuffer TransformBuffer
{
    matrix W;
};

//////////////////
// Vertex Data  //
//////////////////

struct Vertex
{
    float4 position : POSITION;
};
struct VertexTexture
{
    float4 position : POSITION;
    float2 uv : TEXCOORD;
};
struct VertexColor
{
    float4 position : POSITION;
    float2 Color : COLOR;
};
struct VertexTextureNormal
{
    float4 position : POSITION;
    float2 uv : TEXCOORD;
    float3 normal : MNORMAL;
};
struct VertexTextureNormalTangent
{
    float4 position : POSITION;
    float2 uv : TEXCOORD;
    float3 normal : MNORMAL;
    float3 tangent : TANGENT;
};
//////////////////
// VertexOutput //
//////////////////
struct VertexOutput
{
    float4 position : SV_Position;
    float2 uv : TEXCOORD;
    float3 normal : NORMAL;
};
struct MeshOutput
{
    float4 position : SV_Position;
    float3 worldPosition : POSITION1; //조명과 관련
    float2 uv : TEXCOORD;
    float3 normal : NORMAL;
    float3 tangent : TANGENT;
};
//////////////////
// SamplerState //
//////////////////
SamplerState LinearSampler
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Wrap;
    AddressV = Wrap;
};
SamplerState PointSampler
{
    Filter = MIN_MAG_MIP_POINT;
    AddressU = Wrap;
    AddressV = Wrap;
};
/////////////////////
// RasterizerState //
/////////////////////
RasterizerState FillModeWireFrame
{
    FillMode = Wireframe;
};
////////////
// Macro  //
////////////
#define PASS_VP(name,vs,ps)                             \
 pass name                                              \
 {                                                      \
        SetVertexShader(CompileShader(vs_5_0, VS()));   \
        SetPixelShader(CompileShader(ps_5_0, PS()));    \
 }
///////////////
// Function  //
///////////////
float3 CameraPosition()
{
    return Vinv._41_42_43;
}
#endif

