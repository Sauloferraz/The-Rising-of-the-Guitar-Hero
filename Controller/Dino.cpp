// Inclusões --------
#include "Dino.h"
#include "MainGame.h"
#include "Player.h"
#include <iostream>

Dino::Dino(float x, float y, uint note) {

	bbox = new Rect(-50, -130, 50, 80);	// Inicializa a Bounding Box
	type = ENEMY;							// Tipo do objeto
	MoveTo(x, y);
	Dino::note = note;
}

Dino::~Dino() {
	delete bbox;

	delete ira, ila, wr, wl, ar, al;
	delete ir, il, wra, wla, ara, ala;
}

void Dino::Update() {
	Gravity();										// Executa a força da gravidade			
	StateMachine();									// Realiza a escolha das animações		
	Translate(velX * gameTime, velY * gameTime);
	WorldMoving();


	if (window->KeyDown(VK_SHIFT)) {
		moving = true;
	}


	Translate(velX * gameTime, velY * gameTime);
	bbox->MoveTo(x, y);


	atk = false;
	grounded = false;
	upped = false;
	righted = false;
	lefted = false;
}

void Dino::OnCollision(Object* obj) {

	Player* player = (Player*)obj;

	if (obj->Type() == GROUND) {
		Rect* object = (Rect*)obj->bbox;
		Rect* dino = (Rect*)bbox;

		if (dino->Right() > object->Left() + 6 && dino->Left() < object->Right() - 6) {
			if (y < obj->Y()) {
				grounded = true;
				MoveTo(x, object->Top() - 100);
			}
			else {
				upped = true;
				MoveTo(x, object->Bottom() + 100);
			}
		}
		else {
			if (x > obj->X() && y != object->Top() - 50) {
				lefted = true;
			}
			else if (x < obj->X() && y != object->Top() - 50) {
				righted = true;
			}
		}
	}

	if ((obj->Type() == PLAYER)) {
		Rect* object = (Rect*)obj->bbox;
		Rect* dino = (Rect*)bbox;

		if (x > obj->X() && y != object->Top() - 50) {
			lefted = true;
			atk = true;
			facingRight = false;
		}
		else if (x < obj->X() && y != object->Top() - 50) {
			righted = true;
			facingRight = true;
			atk = true;
		}
	}

}

void Dino::Draw() {


	Color* color = new Color(0.85, 0.52, 0, 1);
	
	switch (currentState) {
	case IR:
		ira->Draw(x, y - 25, z, *color);
		ira->NextFrame();
		break;

	case IL:
		ila->Draw(x, y - 25, z, *color);
		ila->NextFrame();
		break;

	case WR:
		wra->Draw(x, y - 25, z, *color);
		wra->NextFrame();
		break;

	case WL:
		wla->Draw(x, y - 25, z, *color);
		wla->NextFrame();
		break;

	case AR:
		ara->Draw(x, y - 25, z, *color);
		ara->NextFrame();
		break;

	case AL:
		ala->Draw(x, y - 25, z, *color);
		ala->NextFrame();
		break;

	default:
		break;

	}
}

void Dino::Gravity() {
	if (!grounded) velY += gravity; // Se não estiver no chão executa a gravidade
}

void Dino::StateMachine() {
	uint previousState = currentState;

	if (velX < 0)
		facingRight = true;
	else if (velX > 0)
		facingRight = false;

	if (facingRight) {
		if (grounded) {
			if (velX == 0) {
				currentState = IR;
			}
			else {
				currentState = WR;
			}if (atk && facingRight) {
				currentState = AR;
			}
		}
	}
	else {
		if (grounded) {
			if (velX == 0) {
				currentState = IL;
			}
			else {
				currentState = WL;
			}if (atk && !facingRight) {
				currentState = AL;
			}
		}
	}

	if (currentState != previousState)	// Reseta as animações caso o estado mude
		ResetAnimation();
}

void Dino::ResetAnimation() {
	ira->Restart();
	ila->Restart();
	wla->Restart();
	wra->Restart();
	ara->Restart();
	ala->Restart();
}

void Dino::WorldMoving() {
	Translate(MainGame::VelX(), MainGame::VelY());
}

uint Dino::EnemyNote() {
	return note;
}