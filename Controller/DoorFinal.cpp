#include "DoorFinal.h"
#include "MainGame.h"

DoorFinal::DoorFinal(float x, float y, float sizeX, float sizeY) {
	bbox = new Rect(-sizeX / 2, -sizeY / 2, sizeX / 2, sizeY / 2);
	type = DFINAL;
	MoveTo(x, y);
}

DoorFinal::~DoorFinal() {
	delete bbox;
}

void DoorFinal::Update() {
	WorldMoving();
}

void DoorFinal::Draw() {}

void DoorFinal::WorldMoving() {
	Translate(MainGame::VelX(), MainGame::VelY());
}
