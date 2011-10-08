
#pragma once

#include "../system/scene/base.h"

namespace Scene {

class DebugScene2 : public Base {
public:
	DebugScene2();
	~DebugScene2();

	Base *Update();
	void Draw();

private:
	DebugScene2(const DebugScene2& rhs);
	const DebugScene2& operator =(const DebugScene2& rhs);
};

}
