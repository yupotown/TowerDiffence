
#include "resource_manager.h"
#include <DxLib.h>
#include <algorithm>

namespace Resource {

Manager& Manager::GetInstance() {
	return instance;
}

int Manager::GetGraphic(const std::string& filename) {
	return graphic_manager.GetHandle(filename);
}

void Manager::ReuseGraphic(int handle) {
	graphic_manager.Reuse(handle);
}

void Manager::ReleaseGraphic(int handle) {
	graphic_manager.Release(handle);
}

int Manager::GetSound(const std::string& filename) {
	return sound_manager.GetHandle(filename);
}

void Manager::ReuseSound(int handle) {
	sound_manager.Reuse(handle);
}

void Manager::ReleaseSound(int handle) {
	sound_manager.Release(handle);
}

Manager::Manager() {
}

Manager::~Manager() {
}

Manager Manager::instance;

}
