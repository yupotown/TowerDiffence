
#include "tdGame.h"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/bind.hpp>

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR cmd_line, int cmd_show) {
	boost::shared_ptr<Game> game(
		boost::make_shared<TowerDiffence::Game>(instance, cmd_line, cmd_show)
		);
	return game->Run();
}
