#include "pch.h"
#include "AssimpTool.h"
#include"Converter.h"
void AssimpTool::Init()
{
	{
		shared_ptr<Converter> converter = make_shared<Converter>();
		//FBX->Memory
		converter->ReadAssetFile(L"Kachujin/Mesh.fbx");

		//Memory ->CustomData
		converter->ExportMaterialData(L"Kachujin/Kachujin");
		converter->ExportModelData(L"Kachujin/Kachujin");
		//CustomData->Memory 
	}
	
}

void AssimpTool::Update()
{
}

void AssimpTool::Render()
{
}
