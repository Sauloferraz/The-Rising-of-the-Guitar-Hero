// Inclusões ----------
#include "Background.h"
#include "MainGame.h"
// --------------------

Background::Background(string imageFront, string imageBack, string imageSky) {
	backgF	= new Sprite(imageFront);		
	backgB	= new Sprite(imageBack);
	sky		= new Sprite(imageSky);
	
	MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
}

Background::~Background() {
	delete backgF;
	delete backgB;
	delete sky;
}

void Background::Update() {
	WorldMoving();
}

void Background::Draw() {
	sky->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	backgB->Draw(x, y, Layer::BACK);
	backgF->Draw(x, y, Layer::MIDBACK);
}

void Background::WorldMoving() {
	Translate(MainGame::VelX(), MainGame::VelY());
}