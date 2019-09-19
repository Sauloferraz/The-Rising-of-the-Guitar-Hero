#include "Dummy.h"
#include "MainGame.h"
#include "iostream"


Dummy::Dummy(float x, float y) {
	
	bbox = new Rect(-50, -100, 50, 100);
	type = ENEMY;
	MoveTo(x, y);
}

Dummy::~Dummy() {
	delete bbox;

	delete dura, dula;
}

void Dummy::Update() {

	MainGame::VelX(0);

	Gravity();						// Executa a força da gravidade
	StateMachine();					// Realiza a escolha das animações	
	Translate(0, velY * gameTime);	// Realiza o movimento
	// -------------------------------------------------------

	grounded = false;
	upped = false;
	righted = false;
	lefted = false;

}

void Dummy::Draw() {
	switch (dumState) {

	case DummyR:
		dura->Draw(x, y - 25);
		dura->NextFrame();
		break;

	case DummyL:
		dula->Draw(x, y - 25);
		dula->NextFrame();
		break;

	default:
		break;

	}
}

void Dummy::Gravity() {
	// Se não estiver no chão executa a gravidade
	if (!grounded) {
		velY += gravity;
	}
	// ------------------------------------------
}

void Dummy::StateMachine() {
	uint previousState = dumState;	// Para detectar mudança no estado

	if (MainGame::VelX() < 0) {			// Vê se o player está virado para a direita
		facingRight = true;
	}
	else if (MainGame::VelX() > 0) {
		facingRight = false;
	}

	if (dumState != previousState) {	// Reseta as animações caso o estado mude
		ResetAnimation();
	}
}

void Dummy::ResetAnimation() {
	dura->Restart();
	dula->Restart();
}







