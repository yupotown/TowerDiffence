
#include "resource_graphic.h"

namespace Resource {

Graphic::Graphic()
	:manager(Manager::GetInstance()),
	handle(-1)
{
}

Graphic::Graphic(const std::string& filename)
	:manager(Manager::GetInstance()),
	handle(manager.GetGraphic(filename))
{
}

Graphic::Graphic(const Graphic& rhs)
	:manager(Manager::GetInstance()),
	handle(rhs.handle)
{
	manager.ReuseGraphic(handle);
}

Graphic::~Graphic() {
	if (handle != -1) {
		manager.ReleaseGraphic(handle);
	}
}

const Graphic& Graphic::operator =(const Graphic& rhs) {
	handle = rhs.handle;
	manager.ReuseGraphic(handle);
	return *this;
}

int Graphic::Load(const std::string& filename) {
	if (handle != -1) {
		manager.ReleaseGraphic(handle);
	}
	handle = manager.GetGraphic(filename);
	return handle;
}

int Graphic::GetHandle() const {
	return handle;
}

}
