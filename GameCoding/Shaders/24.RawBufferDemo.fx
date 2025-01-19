
RWByteAddressBuffer Output; //UAV

struct ComputeInput
{
    uint3 groupID : SV_GroupID;
    uint3 groupThreadID : SV_GroupThreadID;
    uint3 dispathThreadID : SV_DispatchThreadID;
    uint gropuIndex : SV_GroupIndex;
};
[numthreads(10,8,3)]// 10*8*3 =240 --> 240����ŭ�ǽ����� ��� 
void  CS(ComputeInput input )
{
    uint index = input.gropuIndex;
    uint outAddress = index * 10 * 4;//ComputInput ũ�Ⱑ 40
    
    Output.Store3(outAddress + 0, input.groupID); 
    Output.Store3(outAddress + 12, input.groupThreadID); //uint3 ũ�� :12
    Output.Store3(outAddress + 24,input.dispathThreadID);
    Output.Store(outAddress + 36, input.gropuIndex); //uint �̴� Store3�̾ƴ�Store
    
}

technique11 T0
{
    Pass P0
    {
        SetVertexShader(NULL);
        SetPixelShader(NULL);
        SetComputeShader(CompileShader(cs_5_0, CS())); 
    }
};
