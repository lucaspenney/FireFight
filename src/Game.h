#ifndef GAME_H
#define	GAME_H
#include "Level.h"
#include "Renderer.h"
#include "Player.h"

class Game {
public:
	Game();
	~Game();
	Level level;
	void update();
	void render(Renderer* renderer);
	Player player;
private:

};

#endif	/* GAME_H */

