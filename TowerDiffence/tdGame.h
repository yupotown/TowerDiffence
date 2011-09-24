
#pragma once

#include "game.h"
#include <DxLib.h>

namespace TowerDiffence {

class Game : public ::Game {
public:
	Game(HINSTANCE instance, LPSTR cmdLine, int cmdShow);
	~Game();

	int Run();

private:
	HINSTANCE instance;
	LPSTR cmdLine;
	int cmdShow;
};

}
