
#pragma once

#include <string>
#include "resource_reference_counter.h"
#include <map>

namespace Resource {

class ManagerBase {
public:
	typedef std::map< std::string, ReferenceCounter > HandlesMap;

	ManagerBase();
	virtual ~ManagerBase();

	virtual int GetHandle(const std::string& filename) = 0;
	virtual void Reuse(int handle) = 0;
	virtual void Release(int handle) = 0;

	void Add(const std::string& filename, int handle);
	HandlesMap::iterator Find(const std::string& filename);
	HandlesMap::iterator FindHandle(int handle);
	int DeleteHandle(int handle);
	int DeleteHandle(const HandlesMap::iterator& it);
	int IncrementCount(int handle);
	int DecrementCount(int handle);
	int GetCount(int handle);
	int IncrementCount(const HandlesMap::iterator& it);
	int DecrementCount(const HandlesMap::iterator& it);
	int GetCount(const HandlesMap::iterator& it);

protected:
	HandlesMap handles;

private:
	ManagerBase(const ManagerBase& rhs);
	const ManagerBase& operator =(const ManagerBase& rhs);
};

}
