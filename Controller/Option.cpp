// Inlcusões ----
#include "Option.h"
#include "MainGame.h"
// --------------

Option::Option(float x, float y, uint menuType, string img, int lines, int collumns) {
	image = new Image(img);
	tileset = new TileSet(img, lines, collumns);
	animation = new Animation(tileset, 0.200f, true);

	bbox = new Rect(-1.0f * tileset->TileWidth() / 2.0f,
		-1.0f * tileset->TileHeight() / 2.0f,
		tileset->TileWidth() / 2.0f,
		tileset->TileHeight() / 2.0f);

	MoveTo(x, y);
	Option::menuType = menuType;
	type = OPTION;
}

Option::~Option() {
	delete bbox;
	delete animation;
	delete tileset;
}

void Option::Update() {
	if (selected) {
		animation->NextFrame();
	}
	else {
		animation->Frame(0);
	}

	selected = false;
}

void Option::OnCollision(Object* obj) {
	switch (obj->Type()) {
	case MOUSE:
		selected = true;
		break;
	}

}

void Option::Draw() {
	animation->Draw(x, y, z);
}

uint Option::MenuType() {
	return menuType;
}
