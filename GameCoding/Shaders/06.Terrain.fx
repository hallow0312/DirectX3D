matrix World;
matrix View;
matrix Projection;
Texture2D Texture0;


struct VertexInput
{
    float4 position : POSITION;
    float2 uv : TEXCOORD;
};
struct VertexOutput
{
    float4 position : SV_Position;
    float2 uv : TEXCOORD;
};

VertexOutput VS(VertexInput input)
{
    VertexOutput output;
    output.position = mul(input.position, World);
    output.position = mul(output.position, View);
    output.position = mul(output.position, Projection);
    
    
    output.uv = input.uv;
    return output;
    
}
SamplerState Sample0
{
    AddressU = Wrap;
    AddressV = Wrap;
};
RasterizerState FillModeWireFrame
{
    FillMode = Wireframe;
};

float4 PS(VertexOutput input) : SV_TARGET
{
    return Texture0.Sample(Sample0, input.uv);
}
technique11 TO
{
    pass PO
    {
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS())); 
    }
    pass P1
    {
        SetRasterizerState(FillModeWireFrame);
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS()));
    }
};
