// Inclus�es --------
#include "Enemy.h"
#include "MainGame.h"
#include "Player.h"
#include <iostream>

Enemy::Enemy(float x, float y, uint note) {

	bbox = new Rect(-30, -120, 50, 100);	// Inicializa a Bounding Box
	type = ENEMY;							// Tipo do objeto
	MoveTo(x, y);
	Enemy::note = note;
}

Enemy::~Enemy() {
	delete bbox;

	delete ira, ila, wr, wl, ar, al;
	delete ir, il, wra, wla, ara, ala;
}

void Enemy::Update() {
	Gravity();										// Executa a for�a da gravidade			
	StateMachine();									// Realiza a escolha das anima��es		
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

void Enemy::OnCollision(Object* obj) {

	Player* player = (Player*)obj;

	if (obj->Type() == GROUND) {
		Rect* object = (Rect*)obj->bbox;
		Rect* enemy = (Rect*)bbox;

		if (enemy->Right() > object->Left() + 6 && enemy->Left() < object->Right() - 6) {
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
		Rect* enemy = (Rect*)bbox;
		
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

void Enemy::Draw() {

	Color* color = new Color(0.97, 1, 0.29, 1);

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

void Enemy::Gravity() {
	if (!grounded) velY += gravity; // Se n�o estiver no ch�o executa a gravidade
}

void Enemy::StateMachine() {
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

	if (currentState != previousState)	// Reseta as anima��es caso o estado mude
		ResetAnimation();
}

void Enemy::ResetAnimation() {
	ira->Restart();
	ila->Restart();
	wla->Restart();
	wra->Restart();
	ara->Restart();
	ala->Restart();
}

void Enemy::WorldMoving() {
	Translate(MainGame::VelX(), MainGame::VelY());
}

uint Enemy::EnemyNote(){
	return note;
}