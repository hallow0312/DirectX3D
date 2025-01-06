#include "pch.h"
#include "10.GlobalShaderDemo.h"
#include "GeometryHelper.h"
#include "Camera.h"
#include "GameObject.h"
#include "CameraScript.h"
#include"MeshRenderer.h"
#include"Mesh.h"

void GlobalShaderDemo::Init()
{
	auto shader = make_shared<Shader>(L"08.GlobalTest.fx");
	
	_camera = make_shared<GameObject>();
	_camera->GetOrAddTransform();
	_camera->AddComponent(make_shared<Camera>());
	_camera->AddComponent(make_shared<CameraScript>());
	_camera->GetTransform()->SetLocalPosition(Vec3(0.f, 0.f, -2.f));
	_obj = make_shared<GameObject>();
	_obj->GetOrAddTransform();

	_obj->AddComponent(make_shared<MeshRenderer>());
	{
		_obj->GetMeshRenderer()->SetShader(shader);
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
	RENDER->Init(shader);
}

void GlobalShaderDemo::Update()
{
	_camera->Update();
	RENDER->Update();
	_obj->Update();
}

void GlobalShaderDemo::Render()
{
	
}
