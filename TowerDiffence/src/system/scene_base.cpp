
#include "scene_base.h"

namespace Scene {

Base::Base()
:finished(false),
killed(false)
{
}

Base::~Base() {
}

void Base::Initialize() {
}

void Base::Finalize() {
}

bool Base::Stop() {
	this->finished = true;
	return this->finished;
}

bool Base::Kill() {
	this->finished = true;
	return this->finished;
}

bool Base::HasFinished() {
	if (this->killed)
		return true;
	return this->finished;
}

}
