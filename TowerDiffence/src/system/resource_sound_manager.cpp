
#include "resource_sound_manager.h"

#include <DxLib.h>

namespace Resource {

SoundManager::SoundManager() {
}

SoundManager::~SoundManager() {
}

int SoundManager::GetHandle(const std::string& filename) {
	HandlesMap::iterator found = ManagerBase::Find(filename);
	if (found != handles.end()) {
		// found
		ManagerBase::IncrementCount(found);
		return found->second.handle;
	} else {
		// not found
		int temp_handle = DxLib::LoadSoundMem(filename.c_str());
		ManagerBase::Add(filename, temp_handle);
		return temp_handle;
	}
}

void SoundManager::Reuse(int handle) {
	ManagerBase::IncrementCount(handle);
}

void SoundManager::Release(int handle) {
	int count = ManagerBase::DecrementCount(handle);
	if (count == 0) {
		HandlesMap::iterator found = ManagerBase::FindHandle(handle);
		DxLib::DeleteSoundMem(found->second.handle);
		ManagerBase::DeleteHandle(found);
	}
}

}
