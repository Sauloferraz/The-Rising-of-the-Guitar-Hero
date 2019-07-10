#ifndef Level2_h
#define Level2_h

// Inclusões ------
#include "Game.h"
#include "Sprite.h"
// ----------------

// Level 2 -----------------
class Level2 : public Game {
private:
	bool viewBbox; // Ativa a visualização da bbox
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
	void ViewBBox();
};
// -------------------------

#endif