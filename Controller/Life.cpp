// Incluclões ---
#include "Life.h"
// --------------

Life::Life() {

	life = new TileSet("Resources/Life.png", lifeSize, 16, 1, 1);
	lifeAnim = new Animation(life, 1, true);
	MoveTo(230, 40);
}

Life::~Life() {
	delete life;
}

void Life::Update() {

}

void Life::Draw() {
	lifeAnim->Draw(x, y, Layer::MIDBACK);
}

void Life::Damage(float damage) {
	lifeSize -= damage;
	if (lifeSize < 0) {
		lifeSize = 0;
	}

	life = new TileSet("Resources/Life.png", lifeSize, 16, 1, 1);
	lifeAnim = new Animation(life, 1, true);
	MoveTo(x - damage/2, 40);
}
