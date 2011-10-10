
#include "resource_graphic_manager.h"
#include <DxLib.h>

namespace Resource {

GraphicManager::GraphicManager() {
}

GraphicManager::~GraphicManager() {
}

int GraphicManager::GetHandle(const std::string& filename) {
	HandlesMap::iterator found = ManagerBase::Find(filename);
	if (found != handles.end()) {
		// found
		ManagerBase::IncrementCount(found);
		return found->second.handle;
	} else {
		// not found
		int temp_handle = DxLib::LoadGraph(filename.c_str());
		ManagerBase::Add(filename, temp_handle);
		return temp_handle;
	}
}

void GraphicManager::Reuse(int handle) {
	ManagerBase::IncrementCount(handle);
}

void GraphicManager::Release(int handle) {
	int count = ManagerBase::DecrementCount(handle);
	if (count == 0) {
		HandlesMap::iterator found = ManagerBase::FindHandle(handle);
		DxLib::DeleteGraph(found->second.handle);
		ManagerBase::DeleteHandle(found);
	}
}

}
