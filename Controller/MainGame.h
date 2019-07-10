#ifndef MainGame_h
#define MainGame_h

// Inclusões -----
#include "Scene.h"
// ---------------

// Listagem de objetos do jogo 
enum types {GROUND, PLAYER};


// Raiz do Jogo -------------------------------------
class MainGame {
private:
	// Velocidade ---------------------------------
	static float velX;	// Velocidade do mundo em X
	static float velY;	// Velocidade do mundo em Y
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

	static Scene* scene;
};
// ---------------------------------------------------

#endif
