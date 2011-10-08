
#pragma once

#include "system/game.h"
#include <DxLib.h>

namespace TowerDiffence {

class Game : public ::Game {
public:
	Game(HINSTANCE instance, LPSTR cmd_line, int cmd_show);
	~Game();

	int Run();

private:
	Game(const Game& rhs);
	const Game& operator =(const Game& rhs);
	HINSTANCE instance;
	LPSTR cmd_line;
	int cmd_show;

	int initialize();
	int finalize();
	bool initialized;
};

}
