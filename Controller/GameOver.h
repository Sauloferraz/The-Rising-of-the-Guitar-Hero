#ifndef GameOver_H_
#define GameOver_H_

// Includes -------
#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include <sstream>
#include "Controller.h"
// ----------------

// Classe da cena GameOver ----------------------------------------------
class GameOver : public Game {
private:
	Controller* gameCtrl = nullptr;	// controle de jogo
	Sprite* background = nullptr;	// Background
	bool	esc = false;	// Controla o pressionamento do ESC

public:

	void Init();		// inicializa jogo
	void Update();		// atualiza lógica do jogo
	void Draw();		// desenha jogo
	void Finalize();	// finaliza jogo
};
// --------------------------------------------------------------------

#endif