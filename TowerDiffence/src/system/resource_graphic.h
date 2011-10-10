
#pragma once

#include "resource_base.h"
#include "resource_manager.h"
#include <string>

namespace Resource {

class Graphic : public Base {
public:
	Graphic();
	Graphic(const std::string& filename);
	Graphic(const Graphic& rhs);
	virtual ~Graphic();
	const Graphic& operator =(const Graphic& rhs);

	int Load(const std::string& filename);
	int GetHandle() const;

private:
	Manager& manager;
	int handle;
};

}
