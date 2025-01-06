#pragma once
#include "IExecute.h"
#include "Geometry.h"

class LightingDemo : public IExecute
{
public:
	void Init() override;
	void Update() override;
	void Render() override;
	shared_ptr<Shader> _shader;
	shared_ptr<GameObject> _obj;
	shared_ptr<GameObject> _camera;
	shared_ptr<GameObject> _obj2;
	Vec3 _lightDir = Vec3(0.f, -1.f, 0.f);
};
	


