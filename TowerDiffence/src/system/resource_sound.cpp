
#include "resource_sound.h"

namespace Resource {

Sound::Sound()
	:manager(Manager::GetInstance()),
	handle(-1)
{
}

Sound::Sound(const std::string& filename)
	:manager(Manager::GetInstance()),
	handle(manager.GetSound(filename))
{
}

Sound::Sound(const Sound& rhs)
	:manager(Manager::GetInstance()),
	handle(rhs.handle)
{
	manager.ReuseSound(handle);
}

Sound::~Sound() {
	if (handle != -1) {
		manager.ReleaseSound(handle);
	}
}

const Sound& Sound::operator =(const Sound& rhs) {
	handle = rhs.handle;
	manager.ReuseSound(handle);
	return *this;
}

int Sound::Load(const std::string& filename) {
	if (handle != -1) {
		manager.ReleaseSound(handle);
	}
	handle = manager.GetSound(filename);
	return handle;
}

int Sound::GetHandle() const {
	return handle;
}

}
