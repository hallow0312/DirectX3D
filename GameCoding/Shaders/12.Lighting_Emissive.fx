#include"00.Global.fx"


float4 MaterialEmmisive;


Texture2D DiffuseMap;
MeshOutput VS(VertexTextureNormal input)
{
    // (VP)
   MeshOutput output;
    output.position = mul(input.position, W);
    output.worldPosition = input.position;
    output.position = mul(output.position, VP);
   
    output.uv = input.uv;
    output.normal = mul(input.normal, (float3x3) W);
    return output;
    
}

//Emissive
//외각선 구할때 사용 
//림라이트 


float4 PS(MeshOutput input) : SV_TARGET
{
    float3 cameraPosition = -V._41_42_43;
    float3 E = normalize(cameraPosition - input.worldPosition);
    
    float value = saturate(dot(E, input.normal));
    float emissive = 1.0f - value;
    emissive = smoothstep(0.0f, 1.0f, emissive);
    emissive = pow(emissive, 2);
    float4 color = MaterialEmmisive * emissive;
    
    return color;
}
technique11 TO
{
   PASS_VP(P0, VS, PS)
};
