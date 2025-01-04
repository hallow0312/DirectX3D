
struct VertexInput
{
    float4 position : POSITION;
    float4 color : COLOR;
};
struct VertexOutput
{
    float4 position : SV_Position;
    float4 color : COLOR;
};

VertexOutput VS(VertexInput input)
{
    VertexOutput output;
    output.position = input.position;
    output.color = input.color;
    return output;
    
}

RasterizerState FillModeWireFrame
{
    FillMode = Wireframe;
};

float4 PS(VertexOutput input) : SV_TARGET
{
    return input.color;
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
