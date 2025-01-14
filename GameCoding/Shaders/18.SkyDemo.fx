#include "00.Global.fx"
#include "00.Light.fx"


struct VS_OUT
{
    float4 position : SV_Position;

    float2 uv : TEXCORRD;
};


VS_OUT VS(VertexTextureNormalTangent input)
{
    VS_OUT output;
    //local -> world ->view ->proj
   
    float4 viewPos = mul(float4(input.position.xyz, 0), V);
    float4 clipPos = mul(viewPos, P);
    output.position = clipPos.xyzw;
    output.position.z = output.position.w*0.999999f;
    output.uv = input.uv;
    //xy[0~1] z[0~1]
    
    return output;
}

float4 PS(VS_OUT input) : SV_TARGET
{
	
    float4 color = DiffuseMap.Sample(LinearSampler, input.uv);
    return color;
}


technique11 T0
{
    pass P0
    {
        SetRasterizerState(FrontCounterClockwiseTrue);
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS()));
        
    }
    
};
