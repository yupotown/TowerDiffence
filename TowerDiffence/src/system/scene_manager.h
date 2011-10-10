
#pragma once

#include "scene_base.h"
#include <boost/shared_ptr.hpp>

namespace Scene {

class Manager {
public:
	Manager(Base *first_scene);
	~Manager();

	void Update();
	bool HasFinished();

private:
	Manager(const Manager& rhs);
	const Manager& operator =(const Manager& rhs);

	boost::shared_ptr< Base > scene;
};

}
