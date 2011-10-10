
#include "tdGame.h"
#include "system/scene_manager.h"
#include "scenes.h"
#include <boost/make_shared.hpp>
//debug
#include "system/FPSController.h"
#include <sstream>
#include <string>

namespace TowerDiffence {

Game::Game(HINSTANCE instance, LPSTR cmd_line, int cmd_show)
:instance(instance),
cmd_line(cmd_line),
cmd_show(cmd_show),
initialized(false) {
}
Game::~Game() {
}

int Game::Run() {
	{
		int res;
		if ((res = this->initialize()) != 0)
			return res;
	}

	Scene::Manager scene_manager(new Scene::DebugScene());
	FPSController fps_controller;

	while (ProcessMessage() == 0) {
		// update scene
		scene_manager.Update();

		// has ever scene finished?
		if (scene_manager.HasFinished()) {
			// quit
			break;
		}

		// draw framerate
		int fps = fps_controller.GetRealFPS();
		{
			std::stringstream ss;
			ss << fps;
			DxLib::DrawString(0, 0, ss.str().c_str(), DxLib::GetColor(255 ,0 ,0));
		}
		fps_controller.Update();

		// draw
		if (DxLib::ScreenFlip() != 0) {
			return -1;
		}
	}

	int res = 0;
	res = this->finalize();
	return res;
}

int Game::initialize() {
	// if it has been initialized, do not anything.
	if (initialized)
		return 0;
	// Window or FullScreen
	if (DxLib::ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK)
		return -1;
	if (DxLib::SetMainWindowText("") != 0)
		return -1;
	if (DxLib_Init() != 0)
		return -1;
	if (DxLib::SetDrawScreen(DX_SCREEN_BACK) != 0)
		return -1;
	return 0;
}

int Game::finalize() {
	if (!initialized)
		return 0;
	return 0;
}

}
