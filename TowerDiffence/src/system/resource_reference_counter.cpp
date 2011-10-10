
#include "resource_reference_counter.h"

namespace Resource {

ReferenceCounter::ReferenceCounter()
	:handle(-1),
	count(0)
{
}

ReferenceCounter::ReferenceCounter(int handle)
	:handle(handle),
	count(1)
{
}

}
