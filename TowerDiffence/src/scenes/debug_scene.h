
#pragma once

#include "../system/scene_base.h"
#include "../system/resource.h"

namespace Scene {

class DebugScene : public Base {
public:
	DebugScene();
	~DebugScene();

	Base *Update();
	void Draw();

	void Initialize();

private:
	int x, y;
	double n, m;
	double t;

	Resource::Graphic graph_debug;
};

}
