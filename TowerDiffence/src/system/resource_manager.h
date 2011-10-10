
#pragma once

#include <map>
#include <string>
#include "resource_graphic_manager.h"
#include "resource_sound_manager.h"

namespace Resource {

class Manager {
public:
	static Manager& GetInstance();

	int GetGraphic(const std::string& filename);
	void ReuseGraphic(int handle);
	void ReleaseGraphic(int handle);

	int GetSound(const std::string& filename);
	void ReuseSound(int handle);
	void ReleaseSound(int handle);

private:
	Manager();
	Manager(const Manager& rhs);
	~Manager();
	const Manager& operator =(const Manager& rhs);

	static Manager instance;

	GraphicManager graphic_manager;
	SoundManager sound_manager;
};

}
