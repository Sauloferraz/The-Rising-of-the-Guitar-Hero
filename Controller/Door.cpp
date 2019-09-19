#include "Door.h"
#include "MainGame.h"

Door::Door(float x, float y, float sizeX, float sizeY) {
	bbox = new Rect(-sizeX / 2, -sizeY / 2, sizeX / 2, sizeY / 2);
	type = DOOR;
	MoveTo(x, y);
}

Door::~Door() {
	delete bbox;
}

void Door::Update() {
	WorldMoving();
}

void Door::Draw() {}

void Door::WorldMoving() {
	Translate(MainGame::VelX(), MainGame::VelY());
}
