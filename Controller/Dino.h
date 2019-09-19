#ifndef Dino_h
#define Dino_h

#include "Object.h"
#include "Animation.h"

class Dino : public Object {
private:

	uint currentState = IR;							// Estado atual do player
	enum STATE { IR, IL, WR, WL, AR, AL };	// Estados possíveis
	enum note { U, I, O };
	uint note;

	// Coleção de animação do player -----------------------------------------------

	TileSet* ir = new TileSet("Resources/Dino/IdleR.png", 6, 1);
	Animation* ira = new Animation(ir, 1.0 / 12.0, true);

	TileSet* il = new TileSet("Resources/Dino/IdleL.png", 6, 1);
	Animation* ila = new Animation(il, 1.0 / 12.0, true);

	TileSet* wr = new TileSet("Resources/Dino/WalkR.png", 6, 1);
	Animation* wra = new Animation(wr, 1.0 / 12.0, true);

	TileSet* wl = new TileSet("Resources/Dino/WalkL.png", 6, 1);
	Animation* wla = new Animation(wl, 1.0 / 12.0, true);

	TileSet* ar = new TileSet("Resources/Dino/AtkR.png", 6, 1);
	Animation* ara = new Animation(ar, 1.0 / 13.0, true);

	TileSet* al = new TileSet("Resources/Dino/AtkL.png", 6, 1);
	Animation* ala = new Animation(al, 1.0 / 13.0, true);

	bool facingRight = true;
	// Colisores -------------------------------
	bool grounded = false;			// Chão
	bool lefted = false;			// Parede a esquerda
	bool righted = false;			// Parede a direita
	bool upped = false;				// Teto
	bool atk = false;

	bool moving = false;
	// -----------------------------------------
	float gravity = 35.0;			// Força da gravidade
	float walkVelocity = 10.0;		// Velocidade de movimento
	float velX = 0;					// Eixo X
	float velY = 0;					// Eixo Y

public:
	Dino(float x, float, uint note); // Construtor
	~Dino();						  // Destrutor

	void Update();					  // Atualiza a lógica
	void OnCollision(Object* obj);	  // Colisor
	void Draw();					  // Desenha o objeto		
	void Gravity();					  // Ativa a gravidade
	void StateMachine();			  // Define animação de acordo com o movimento
	void ResetAnimation();			  // Reseta animações
	void WorldMoving();				  // Move em conjunto com o mundo
	uint EnemyNote();
};

#endif 