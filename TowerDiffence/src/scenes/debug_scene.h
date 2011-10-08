
#include "../system/scene/base.h"

namespace Scene {

class DebugScene : public Base {
public:
	DebugScene();
	~DebugScene();

	Base *Update();
	void Draw();
};

}
