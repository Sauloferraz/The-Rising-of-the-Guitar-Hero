#include "Acorde.h"
#include "MainGame.h"
#include "Enemy.h"

Acorde::Acorde(int startX, int startY, int vel, uint gn) {

	bbox = new Rect(-12, -9, 12, 9);
	type = ACORDE;
	MoveTo(startX, startY);
	state = RIGHT;
	Acorde::vel = vel;
	guitar = gn;

}

Acorde::~Acorde() {
	delete bbox;

	delete note, notea;
}

void Acorde::OnCollision(Object* obj) {
	Enemy* enemy = (Enemy*)obj;
	
	if ((obj->Type() == ENEMY) && (enemy->EnemyNote() == guitar)) {
		Delete(obj);
		Delete(this);
	}
	else if (obj->Type() == GROUND) {
		Delete(this);
	}
	else if ((obj->Type() == ENEMY) && (enemy->EnemyNote() != guitar)) {
		Delete(this);
	}

}

void Acorde::Update() {
	Translate(velX * gameTime, 0);
	bbox->MoveTo(x, y);

	if (x > window->Width() || x < 0) {
		Delete(this);
	}
}

void Acorde::Draw() {
	
	//Yellow: 
	Color* colorY = new Color(0.97, 1, 0.29, 0.95);
	
	//Blue:
	Color* colorB = new Color(0.16, 0.27, 0.86, 0.95);

	//Orange: 
	Color* colorO = new Color(0.85, 0.52, 0, 0.95);

	//	ira->Draw(x, y - 25, z, *color);

	switch (state) {
	case RIGHT:
		if (guitar == 0) {
			notea->Draw(x, y - 25, z, *colorY);
			notea->NextFrame();
			break;
		}

		if (guitar == 1) {
			notea->Draw(x, y - 25, z, *colorB);
			notea->NextFrame();
			break;
		}

		if (guitar == 2) {
			notea->Draw(x, y - 25, z, *colorO);
			notea->NextFrame();
			break;
		}
		
	case LEFT:
		if (guitar == 0) {
			notea->Draw(x, y - 25, z, *colorY);
			notea->NextFrame();
			break;
		}

		if (guitar == 1) {
			notea->Draw(x, y - 25, z, *colorB);
			notea->NextFrame();
			break;
		}

		if (guitar == 2) {
			notea->Draw(x, y - 25, z, *colorO);
			notea->NextFrame();
			break;
		}
	}
}

void Acorde::Right() {
	velX = vel;
	state = RIGHT;
}

void Acorde::Left() {
	velX = -vel;
	state = LEFT;
}

void Acorde::Delete(Object* obj) {
	uint type;
	switch (obj->Type()) {
	case ENEMY:
		MainGame::scene->Delete(obj, MOVING);
		break;

	default:
		type = MOVING;
		MainGame::scene->Delete(obj, MOVING);
		break;
	}
}
