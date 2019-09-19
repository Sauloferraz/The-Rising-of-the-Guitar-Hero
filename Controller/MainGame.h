#ifndef MainGame_h
#define MainGame_h

// Inclusões -----
#include "Scene.h"
#include "Audio.h"
#include "Player.h"
// ---------------

// Listagem de objetos do jogo 
enum types {GROUND, PLAYER, ENEMY,
			OPTION, MOUSE, ACORDE, DOOR, DFINAL};

enum audios { BLUE, YELLOW, ORANGE, MENU, LV1, LV2, TT, GO, EG };

// Raiz do Jogo -------------------------------------
class MainGame {
private:
	// Velocidade ---------------------------------
	static float velX;	// Velocidade do mundo em X
	static float velY;	// Velocidade do mundo em Y
	static bool viewBbox;
						// --------------------------------------------
public:
	// X ---------------------------------------------
	static float VelX() { return velX; }		// Get
	static void VelX(float vel) { velX = vel; }	// Set
	// -----------------------------------------------

	// Y ---------------------------------------------
	static float VelY() { return velY; }		// Get
	static void VelY(float vel) { velY = vel; }	// Set
	// -----------------------------------------------

	// ViewBbox --------------------------------------------------
	static bool isViewingBbox() { return viewBbox; }		// Get
	static void ViewBbox() { viewBbox = !viewBbox; }	// Set
	// -----------------------------------------------------------

	static Scene* scene;
	static Player* player;
	static Audio* audio;
};
// ---------------------------------------------------

#endif
