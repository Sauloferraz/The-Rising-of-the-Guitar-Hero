#ifndef Enemy_h
#define Enemy_h

#include "Object.h"
#include "Animation.h"

class Enemy : public Object {
private:

	uint currentState = IR;							// Estado atual do player
	enum STATE { IR, IL, WR, WL, AR, AL };	// Estados poss�veis
	enum note { U, I, O };
	uint note;

	// Cole��o de anima��o do player -----------------------------------------------

	TileSet* ir = new TileSet("Resources/Enemy/IdleR.png", 4, 1);
	Animation* ira = new Animation(ir, 1.0 / 12.0, true);

	TileSet* il = new TileSet("Resources/Enemy/IdleL.png", 4, 1);
	Animation* ila = new Animation(il, 1.0 / 12.0, true);

	TileSet* wr = new TileSet("Resources/Enemy/WalkR.png", 8, 1);
	Animation* wra = new Animation(wr, 1.0 / 12.0, true);

	TileSet* wl = new TileSet("Resources/Enemy/WalkL.png", 8, 1);
	Animation* wla = new Animation(wl, 1.0 / 12.0, true);

	TileSet* ar = new TileSet("Resources/Enemy/AttackR.png", 4, 1);
	Animation* ara = new Animation(ar, 1.0 / 13.0, true);

	TileSet* al = new TileSet("Resources/Enemy/AttackL.png", 4, 1);
	Animation* ala = new Animation(al, 1.0 / 13.0, true);
	   
	bool facingRight = true;
	// Colisores -------------------------------
	bool grounded = false;			// Ch�o
	bool lefted = false;			// Parede a esquerda
	bool righted = false;			// Parede a direita
	bool upped = false;				// Teto
	bool atk = false;
	
	bool moving = false;
	// -----------------------------------------
	float gravity = 35.0;			// For�a da gravidade
	float walkVelocity = 10.0;		// Velocidade de movimento
	float velX = 0;					// Eixo X
	float velY = 0;					// Eixo Y

public:
	Enemy(float x, float, uint note); // Construtor
	~Enemy();						  // Destrutor
	
	void Update();					  // Atualiza a l�gica
	void OnCollision(Object* obj);	  // Colisor
	void Draw();					  // Desenha o objeto		
	void Gravity();					  // Ativa a gravidade
	void StateMachine();			  // Define anima��o de acordo com o movimento
	void ResetAnimation();			  // Reseta anima��es
	void WorldMoving();				  // Move em conjunto com o mundo
	uint EnemyNote();
};

#endif 