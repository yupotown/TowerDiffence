
#pragma once

#include "resource_base.h"
#include "resource_manager.h"
#include <string>

namespace Resource {

class Sound : public Base {
public:
	Sound();
	Sound(const std::string& filename);
	Sound(const Sound& rhs);
	virtual ~Sound();
	const Sound& operator =(const Sound& rhs);

	int Load(const std::string& filename);
	int GetHandle() const;

private:
	Manager& manager;
	int handle;
};

}
