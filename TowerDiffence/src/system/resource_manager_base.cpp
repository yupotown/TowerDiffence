
#include "resource_manager_base.h"
#include <algorithm>

namespace Resource {

ManagerBase::ManagerBase() {
}

ManagerBase::~ManagerBase() {
}

void ManagerBase::Add(const std::string& filename, int handle) {
	HandlesMap::iterator found = Find(filename);
	if (found != handles.end()) {
		// found
		++found->second.count;
	} else {
		// not found
		ReferenceCounter temp(handle);
		handles.insert(HandlesMap::value_type(filename, temp));
	}
}

ManagerBase::HandlesMap::iterator ManagerBase::Find(const std::string& filename) {
	return handles.find(filename);
}

ManagerBase::HandlesMap::iterator ManagerBase::FindHandle(int handle) {
	return std::find_if(
		handles.begin(), handles.end(),
		[handle](HandlesMap::value_type i) {
			return i.second.handle == handle;
		}
	);
}

int ManagerBase::DeleteHandle(int handle) {
	HandlesMap::iterator found = FindHandle(handle);
	if (found != handles.end()) {
		// found
		int temp_handle = found->second.handle;
		handles.erase(found);
		return temp_handle;
	} else {
		// not found
		return -1;
	}
}

int ManagerBase::DeleteHandle(const HandlesMap::iterator& it) {
	int temp_handle = it->second.handle;
	handles.erase(it);
	return temp_handle;
}

int ManagerBase::IncrementCount(int handle) {
	HandlesMap::iterator found = FindHandle(handle);
	if (found != handles.end()) {
		// found
		++found->second.count;
		return found->second.count;
	} else {
		// not found
		return 0;
	}
}

int ManagerBase::DecrementCount(int handle) {
	HandlesMap::iterator found = FindHandle(handle);
	if (found != handles.end()) {
		// found
		--found->second.count;
		return found->second.count;
	} else {
		// not found
		return 0;
	}
}

int ManagerBase::GetCount(int handle) {
	HandlesMap::iterator found = FindHandle(handle);
	if (found != handles.end()) {
		// found
		return found->second.count;
	} else {
		// not found
		return 0;
	}
}

int ManagerBase::IncrementCount(const HandlesMap::iterator& it) {
	if (it != handles.end()) {
		++it->second.count;
		return it->second.count;
	} else {
		return 0;
	}
}

int ManagerBase::DecrementCount(const HandlesMap::iterator& it) {
	if (it != handles.end()) {
		--it->second.count;
		return it->second.count;
	} else {
		return 0;
	}
}

int ManagerBase::GetCount(const HandlesMap::iterator& it) {
	if (it != handles.end()) {
		return it->second.count;
	} else {
		return 0;
	}
}

}
