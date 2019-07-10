#ifndef Player_h
#define Player_h

// Inclusões ------
#include "Object.h"
#include "Controller.h"
#include "Animation.h"
#include "Life.h"
// ----------------

// Player --------------------
class Player : public Object {
private:
	Controller* controller = new Controller();
	bool xinput;
	bool dinput;

	uint currentState = SR;			// Estado atual do player
	enum PLAYERSTATE { R, L, SR, SL, P };

	// Coleção de animação do player --------------------------------------------
	TileSet* r = new TileSet("Resources/PlayerStates/R.png", 64*4, 64*4, 1, 31);
	Animation* ra = new Animation(r, 0.075, true);
	TileSet* l = new TileSet("Resources/PlayerStates/L.png", 64*4, 64*4, 1, 31);
	Animation* la = new Animation(l, 0.075, true);
	TileSet* sr = new TileSet("Resources/PlayerStates/SR.png", 64*4, 64*4, 1, 6);
	Animation* sra = new Animation(sr, 1.0 / 6.0, true);
	TileSet* sl = new TileSet("Resources/PlayerStates/SL.png", 64*4, 64*4, 1, 6);
	Animation* sla = new Animation(sl, 1.0 / 6.0, true);
	TileSet* p = new TileSet("Resources/PlayerStates/P.png", 64*4, 64*4, 1, 6);
	Animation* pa = new Animation(p, 1.0 / 2.0, true);
	// --------------------------------------------------------------------------

	bool facingRight = true;

	// Colisores -------------------------------
	bool grounded = false;	// Chão
	bool lefted = false;	// Parede a esquerda
	bool righted = false;	// Parede a direita
	bool upped = false;		// Teto
	// -----------------------------------------

	Life* life = new Life();

	// Variáveis ---------------------------------------------
	float gravity		= 30.0;		// Força da gravidade
	float jumpHeight	= 1000.0;	// Altura do pulo
	float walkVelocity	= 10.0;		// Velocidade de movimento
	// Velocidade -----------------------
	float velY			= 0;	// Eixo Y
	// ----------------------------------
	// -----------------------------------------------

public:
	Player(float x, float y);
	~Player();

	void Update();
	void OnCollision(Object* obj);
	void Draw();
	void Gravity();
	void StateMachine();
	void ResetAnimation();
};
// ----------------------------

#endif 

