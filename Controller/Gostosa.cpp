// Inclusões --------
#include "Gostosa.h"
#include "MainGame.h"
#include "Player.h"
#include <iostream>

Gostosa::Gostosa(float x, float y, uint note) {

	bbox = new Rect(-50, -130, 50, 80);	// Inicializa a Bounding Box
	type = ENEMY;							// Tipo do objeto
	MoveTo(x, y);
	Gostosa::note = note;
}

Gostosa::~Gostosa() {
	delete bbox;

	delete ira, ila, wr, wl, ar, al;
	delete ir, il, wra, wla, ara, ala;
}

void Gostosa::Update() {
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

void Gostosa::OnCollision(Object* obj) {

	Player* player = (Player*)obj;

	if (obj->Type() == GROUND) {
		Rect* object = (Rect*)obj->bbox;
		Rect* gostosa = (Rect*)bbox;

		if (gostosa->Right() > object->Left() + 6 && gostosa->Left() < object->Right() - 6) {
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
		Rect* gostosa = (Rect*)bbox;

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

void Gostosa::Draw() {


	//1.0, 0.96, 0.40, 0.95);

	Color* color = new Color(0.26, 0.59, 1.07, 1);


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

void Gostosa::Gravity() {
	if (!grounded) velY += gravity; // Se não estiver no chão executa a gravidade
}

void Gostosa::StateMachine() {
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

void Gostosa::ResetAnimation() {
	ira->Restart();
	ila->Restart();
	wla->Restart();
	wra->Restart();
	ara->Restart();
	ala->Restart();
}

void Gostosa::WorldMoving() {
	Translate(MainGame::VelX(), MainGame::VelY());
}

uint Gostosa::EnemyNote() {
	return note;
}