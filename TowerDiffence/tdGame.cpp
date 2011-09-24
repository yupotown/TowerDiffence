
#include "tdGame.h"
#include <memory>

namespace TowerDiffence {

Game::Game(HINSTANCE instance, LPSTR cmdLine, int cmdShow)
:instance( instance ),
cmdLine( cmdLine),
cmdShow( cmdShow ) {
}
Game::~Game() {
}

int Game::Run() {
	return 0;
}

}
