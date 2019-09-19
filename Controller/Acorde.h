#ifndef Acorde_h
#define Acorde_h

// Includes ----------
#include "Object.h"
#include "Animation.h"
// -------------------

// Objeto do personagem principal ---------------------------------------------------------------------------------------------------
class Acorde : public Object {
private:
	
	enum states { RIGHT, LEFT };		// Estados possíveis da bala
	uint state;						   // Estado atual

	enum GUITAR { U, I, O };
	uint guitar;

	TileSet* note = new TileSet("Resources/Note/Note.png", 1, 4);				// Sprite do tiro carregado
	Animation* notea = new Animation(note, 1.0 / 12.0, true);				// Animação do tiro carregado

	TileSet* note2 = new TileSet("Resources/Life.png", 1, 1);				// Sprite do tiro carregado
	Animation* noteb = new Animation(note2, 1.0 / 10.0, true);

	TileSet* note3 = new TileSet("Resources/Life.png", 1, 1);				// Sprite do tiro carregado
	Animation* notec = new Animation(note3, 1.0 / 10.0, true);

	float velX = 0;			// Velocidade do player no eixo X
	float vel = 0;			// Velocidade do player no eixo X

public:
	Acorde(int startX, int startY, int vel, uint gn);		// Construtor
	~Acorde();																					// Destrutor

	void OnCollision(Object* obj);	// Detecta as colisões do player
	void Update();					// Atualiza lógica do jogo
	void Draw();					// Desenha os quadros do jogo

	void Left();					// Bala para a esquerda
	void Right();					// Bala para a direita
	void Delete(Object* obj);		// Deleta objeto selecionado ("this" para deletar a própia bala)
};
// ----------------------------------------------------------------------------------------------------------------------------------

#endif

