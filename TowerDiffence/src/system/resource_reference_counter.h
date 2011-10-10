
#pragma once

namespace Resource {

struct ReferenceCounter {
	ReferenceCounter();
	ReferenceCounter(int handle);

	int handle;
	int count;
};

}
