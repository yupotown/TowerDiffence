
#include "tdGame.h"
#include <boost/shared_ptr.hpp>

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR cmdLine, int cmdShow) {
	boost::shared_ptr<Game> game(new TowerDiffence::Game(instance, cmdLine, cmdShow));
	return game->Run();
}
