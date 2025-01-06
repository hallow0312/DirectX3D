#include "pch.h"
#include "14.SpecularDemo.h"
#include "Camera.h"
#include "CameraScript.h"
#include "GameObject.h"
#include "GeometryHelper.h"
#include"Mesh.h"
#include"MeshRenderer.h"

void SpecularDemo::Init()
{
	_shader = make_shared<Shader>(L"11.Lighting_Specular.fx");
	
	_camera = make_shared<GameObject>();
	_camera->GetOrAddTransform();
	_camera->AddComponent(make_shared<Camera>());
	_camera->AddComponent(make_shared<CameraScript>());
	_camera->GetTransform()->SetLocalPosition(Vec3(0.f, 0.f, -10.f));

	//Object
	_obj = make_shared<GameObject>();
	_obj->GetOrAddTransform();

	_obj->AddComponent(make_shared<MeshRenderer>());
	{
		_obj->GetMeshRenderer()->SetShader(_shader);
	}
	{
		RESOURCES->Init();
		auto mesh = RESOURCES->Get<Mesh>(L"Sphere");
		_obj->GetMeshRenderer()->SetMesh(mesh);
	}
	{
		auto texture = RESOURCES->Load<Texture>(L"Veigar", L"..\\Resources\\Textures\\veigar.jpg");
		_obj->GetMeshRenderer()->SetTexture(texture);
	}


	//Object2
	_obj2 = make_shared<GameObject>();
	_obj2->GetOrAddTransform()->SetPosition(Vec3{ 0.5f,0.f,2.f });

	_obj2->AddComponent(make_shared<MeshRenderer>());
	{
		_obj2->GetMeshRenderer()->SetShader(_shader);
	}
	{
		RESOURCES->Init();
		auto mesh = RESOURCES->Get<Mesh>(L"Cube");
		_obj2->GetMeshRenderer()->SetMesh(mesh);
	}
	{
		auto texture = RESOURCES->Load<Texture>(L"Veigar", L"..\\Resources\\Textures\\veigar.jpg");
		_obj2->GetMeshRenderer()->SetTexture(texture);
	}
	RENDER->Init(_shader);
}

void SpecularDemo::Update()
{
	_camera->Update();
	RENDER->Update();
	Vec4 light{1.f};
	_shader->GetVector("LightSpecular")->SetFloatVector((float*)&light);
	Vec3 lightDir{ 1.f,-1.f,0.f };
	lightDir.Normalize();

	_shader->GetVector("LightDir")->SetFloatVector((float*)&lightDir );
	{
		Vec4 materialAmbient(1.f);
		_shader->GetVector("MaterialSpecular")->SetFloatVector((float*)&materialAmbient);
		_obj->Update();
	}
	{
		Vec4 materialAmbient(1.f);
		_shader->GetVector("MaterialSpecular")->SetFloatVector((float*)&materialAmbient); 

		_obj2->Update();
	}
}

void SpecularDemo::Render()
{
	
}
