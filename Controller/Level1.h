#ifndef Level1_h
#define Level1_h

// Inclusões -----
#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"
// ----------------

// Level 1 -----------------
class Level1 : public Game {
private:
	bool viewBbox; // Ativa a visualização da bbox
	Sprite* lifeSuper;
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
	void ViewBBox();
	bool keyCtrl = false;
};
// -------------------------

#endif
