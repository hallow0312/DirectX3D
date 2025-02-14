#pragma once

using VertexType = VertexTextureNormalTangentBlendData;

struct asBone
{
	string name;
	int32 index = -1;
	int32 parent = -1;
	Matrix transform;

};
struct asMesh
{
	string name;
	aiMesh* mesh;
	vector<VertexType> vertices;
	vector<uint32> indices;

	int32 boneindex;
	string materialName;

};
struct asMaterial
{
	string name;
	Color ambient;
	Color diffuse;
	Color specular;
	Color emissive;
	string diffuseFile;
	string specularFile;
	string normalFile;
};
//Animation 
struct asBlendWeight
{
	void Set(uint32 index, uint32 boneIndex, float weight)
	{
		float i = (float)boneIndex;
		float w = weight;
		switch (index)
		{
			case 0: indices.x = i; weights.x = w; break;
			case 1: indices.y = i; weights.y = w; break;
			case 2: indices.z = i; weights.z = w; break;
			case 3: indices.w = i; weights.w = w; break;

		}
	}
	Vec4 indices = Vec4(0, 0, 0, 0);
	Vec4 weights = Vec4(0, 0, 0, 0);

};
//정점마다 -> {뼈번호 , 가중치 } 

struct asBoneWeights
{
	//가중치가 높은애들을 우선으로 배치하기 위함  
	void AddWeights(uint32 boneIndex, float weight)
	{
		if (weight <= 0.0f)return;
		auto findit = std::find_if(boneWeights.begin(), boneWeights.end(),
			[weight](const Pair& p)
			{
				return weight > p.second;
			});
		boneWeights.insert(findit, Pair{ boneIndex,weight });
	}
	asBlendWeight GetBlendWeights()
	{
		asBlendWeight blendWeights;
		for (uint32 i = 0; i < boneWeights.size(); i++)
		{
			if (i >= 4)break;
			blendWeights.Set(i, boneWeights[i].first, boneWeights[i].second);

		}
		return blendWeights;
	}
	//최종가중치가 1로 구해주기위함 
	//비율의 합은 percentage라고 생각하면 무조건 1이되야함 
	void Normalize()
	{
		if (boneWeights.size() >= 4)boneWeights.resize(4);
		float totalWeight = 0.f;
		for (const auto& item : boneWeights)totalWeight += item.second;

		float scale = 1.f / totalWeight;
		for (auto& item : boneWeights)item.second *= scale;
	}
	using Pair = pair<int32, float>;
	vector<Pair> boneWeights;

};
struct asKeyFrameData
{
	float time;
	Vec3 scale;
	Quaternion rotation;
	Vec3 translation;
};
struct asKeyFrame
{
	string boneName;
	vector<asKeyFrameData>transforms;
};
struct asAnimation
{
	string name;
	uint32  frameCount;
	float frameRate;
	float duration;
	vector<shared_ptr<asKeyFrame>>keyframes; 
};

struct asAnimationNode
{
	aiString name;
	vector < asKeyFrameData> keyframe;
};