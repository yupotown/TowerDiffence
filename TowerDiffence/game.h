
#pragma once

class Game {
public:
	Game();
	virtual ~Game();

	virtual int Run() = 0;

private:
	Game(const Game& rhs);
	const Game& operator =(const Game& rhs);
};
