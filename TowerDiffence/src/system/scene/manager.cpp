
#include "manager.h"
#include <iostream>
#include <boost/make_shared.hpp>

namespace Scene {

Manager::Manager(Base *first_scene)
:scene(first_scene)
{
	scene->Initialize();
}

Manager::~Manager() {
}

void Manager::Update() {
	if (scene != NULL) {
		do {
			Base *next = scene->Update();
			if (scene->HasFinished()) {
				// quit
				scene->Finalize();
			} else if (next != scene.get()) {
				// change
				scene->Finalize();
				scene.reset(next);
				scene->Initialize();
				scene->Draw();
			} else {
				// continue
				scene->Draw();
			}
		} while (false);
	}
}

bool Manager::HasFinished() {
	if (scene == NULL)
		return true;
	else
		return false;
}

}
