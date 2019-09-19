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

	uint currentState = IdleR;			// Estado atual do player
	enum PLAYERSTATE { IdleR, IdleL, 
					   RunR, RunL, 
					   DodgeR, DodgeL,
					   GuitarRB, GuitarLB,
					   GuitarRY, GuitarLY,
					   GuitarRO, GuitarLO,
					   JumpR, JumpL,
					   DamageR, DamageL					
	};

	//IdleR --------------------------------------------
	TileSet* ir = new TileSet("Resources/PlayerStates/IdleR.png", 1, 8); //
	Animation* ira = new Animation(ir, 1.0 / 14.0, true);
	
	//IdleL
	TileSet* il = new TileSet("Resources/PlayerStates/IdleL.png", 1, 8);
	Animation* ila = new Animation(il, 1.0 / 14.0, true);

	//RunR
	TileSet* rr = new TileSet("Resources/PlayerStates/RunR.png", 1, 8);
	Animation* rra = new Animation(rr, 1.0 / 14.0, true);
	
	//RunL
	TileSet* rl = new TileSet("Resources/PlayerStates/RunL.png", 1, 8);
	Animation* rla = new Animation(rl, 1.0 / 14.0, true);

	//DodgeR
	TileSet* dr = new TileSet("Resources/PlayerStates/DodgeR.png", 1, 6);
	Animation* dra = new Animation(dr, 1.0 / 14.0, true);

	//DodgeL
	TileSet* dl = new TileSet("Resources/PlayerStates/DodgeL.png", 1, 6);
	Animation* dla = new Animation(dl, 1.0 / 14.0, true);

	//JumpR
	TileSet* jr = new TileSet("Resources/PlayerStates/JumpR.png", 1, 13);
	Animation* jra = new Animation(jr, 1.0 / 13.0, true);

	//JumpL
	TileSet* jl = new TileSet("Resources/PlayerStates/JumpL.png", 1, 13);
	Animation* jla = new Animation(jl, 1.0 / 13.0, true);

	//GuitarR Blue
	TileSet* grb = new TileSet("Resources/PlayerStates/GuitarRBlue.png", 6, 1);
	Animation* grba = new Animation(grb, 1.0 / 14.0, true);

	//GuitarL Blue
	TileSet* glb = new TileSet("Resources/PlayerStates/GuitarLBlue.png", 6, 1);
	Animation* glba = new Animation(glb, 1.0 / 14.0, true);

	//GuitarR Yellow
	TileSet* gry = new TileSet("Resources/PlayerStates/GuitarR.png", 6, 1);
	Animation* grya = new Animation(gry, 1.0 / 14.0, true);

	//GuitarL Yellow
	TileSet* gly = new TileSet("Resources/PlayerStates/GuitarL.png", 6, 1);
	Animation* glya = new Animation(gly, 1.0 / 14.0, true);

	//GuitarR Orange
	TileSet* gro = new TileSet("Resources/PlayerStates/GuitarROrange.png", 6, 1);
	Animation* groa = new Animation(gro, 1.0 / 14.0, true);

	//GuitarL Yellow
	TileSet* glo = new TileSet("Resources/PlayerStates/GuitarLOrange.png", 6, 1);
	Animation* gloa = new Animation(glo, 1.0 / 14.0, true);



	//DamageR
	TileSet* dmgr = new TileSet("Resources/PlayerStates/DamageR.png", 3, 1);
	Animation* dmgra = new Animation(dmgr, 1.0 / 12.0, true);

	//DamageL
	TileSet* dmgl = new TileSet("Resources/PlayerStates/DamageL.png", 3, 1);
	Animation* dmgla = new Animation(dmgl, 1.0 / 12.0, true);


	bool facingRight = true;
	bool playingY = false;
	bool playingB = false;
	bool playingO = false;
	bool dodge = false;
	bool damage = false;
	bool door = false;
	float fireTime = -1;

	// Colisores -------------------------------
	bool grounded = false;	// Chão
	bool lefted = false;	// Parede a esquerda
	bool righted = false;	// Parede a direita
	bool upped = false;		// Teto
	// -----------------------------------------

	Life* life = new Life();

	// Variáveis ---------------------------------------------
	float gravity		= 40.0;		// Força da gravidade
	float jumpHeight	= 1100.0;	// Altura do pulo
	float walkVelocity	= 10.0;		// Velocidade de movimento
	// Velocidade -----------------------
	float velY			= 0;	// Eixo Y
	// ----------------------------------
	// -----------------------------------------------

public:
	Player(float x, float y);
	~Player();

	bool dead = false;
	void Update();
	void OnCollision(Object* obj);
	void Draw();
	void Gravity();
	void StateMachine();
	void ResetAnimation();
	void Damage();
	int Playing();
	float Xpos();
	bool IsDead();
	bool keyCtrl = false;
};
// ----------------------------

#endif 

