
#pragma once

#include "resource_manager_base.h"

namespace Resource {

class GraphicManager : public ManagerBase {
public:
	GraphicManager();
	virtual ~GraphicManager();

	int GetHandle(const std::string& filename);
	void Reuse(int handle);
	void Release(int handle);

private:
	GraphicManager(const GraphicManager& rhs);
	const GraphicManager& operator =(const GraphicManager& rhs);
};

}
