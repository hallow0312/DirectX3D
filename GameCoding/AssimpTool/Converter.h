#pragma once
#include "AsTypes.h"

class Converter
{
public:
	Converter();
	~Converter();

public:
	void ReadAssetFile(wstring file);
	void  ExportModelData(wstring  savePath);
	void  ExportMaterialData(wstring savePath);
	void ExportAnimationData(wstring savePath,uint32 index=0);
private:
	void ReadModelData(aiNode*node ,int32 index ,int32 parent);
	void ReadMeshData(aiNode* node, int32 bone);
	void ReadSkinData();
	void ReadMaterialData();

private:
	void WriteModelFile(wstring finalPath);
	void WriteMaterialData(wstring finalPath);
	string WriteTexture(string saveFolder, string file);
private:
	shared_ptr<asAnimation> ReadAnimationData(aiAnimation* srcAnimation);
	void WriteAnimationData(shared_ptr<asAnimation> animation, wstring finalPath);
	shared_ptr<asAnimationNode>ParseAnimationNode(shared_ptr<asAnimation> animation, aiNodeAnim* srcNode);
	void ReadKeyFrameData(shared_ptr<asAnimation> animation, aiNode*srcNode ,map<string,shared_ptr<asAnimationNode>>&cache);
	void WrtieKeyFrameData(shared_ptr<asAnimation>animation, wstring finalPath);
private:

	uint32 GetBoneIndex(const string& name);

private:

	wstring _assetPath = L"../Resources/Assets/";
	wstring _modelPath = L"../Resources/Models/";
	wstring _texturePath = L"../Resources/Textures/";

private:

	shared_ptr<Assimp::Importer>_importer;
	const aiScene* _scene;

private:
	vector<shared_ptr<asBone>>_bones;
	vector<shared_ptr<asMesh>>_meshes;
	vector<shared_ptr<asMaterial>>_materials;
};

