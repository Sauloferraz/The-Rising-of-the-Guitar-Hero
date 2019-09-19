#ifndef Menu_h
#define Menu_h

// Inclusoes ---------
#include "Game.h"
#include "Sprite.h"
#include "Controller.h"
// -------------------

class Menu : public Game {
private:
	Sprite* background = nullptr;
	Controller* gameCtrl = nullptr;	// controle de jogo
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};
#endif