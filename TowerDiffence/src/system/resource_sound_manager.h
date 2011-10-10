
#pragma once

#include "resource_manager_base.h"

namespace Resource {

class SoundManager : public ManagerBase {
public:
	SoundManager();
	virtual ~SoundManager();

	int GetHandle(const std::string& filename);
	void Reuse(int handle);
	void Release(int handle);

private:
	SoundManager(const SoundManager& rhs);
	const SoundManager& operator =(const SoundManager& rhs);
};

}
