#include "Ground.h"
#include "MainGame.h"

Ground::Ground(float x, float y, float sizeX, float sizeY) {
	bbox = new Rect(-sizeX / 2, -sizeY / 2, sizeX / 2, sizeY / 2);
	type = GROUND;
	MoveTo(x, y);
}

Ground::~Ground() {
	delete bbox;
}

void Ground::Update() {
	WorldMoving();
}

void Ground::Draw() {}

void Ground::WorldMoving() {
	Translate(MainGame::VelX(), MainGame::VelY());
}
