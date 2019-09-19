// Inclusões --------
#include "Level1.h"
#include "MainGame.h"
#include "Background.h"
#include "Ground.h"
#include "Engine.h"
#include "Level2.h"
#include "Object.h"
#include "Acorde.h"
#include "Enemy.h"
#include "Door.h"
#include <iostream>
#include "Gostosa.h"
#include "GameOver.h"
#include "Player.h"
#include "Dino.h"
// ------------------

void Level1::Init() {
	MainGame::scene = new Scene();

	MainGame::audio = new Audio();
	//MainGame::audio->Add(LV1, "Resources/OST/Roots(Level1).wav");

	//MainGame::audio->Play(LV1, true);

	lifeSuper = new Sprite("Resources/lifesuper.png");

	Background* background = new Background("Resources/Backgrounds/teste.png", "", "");
	MainGame::scene->Add(background, STATIC);
	
	Player* player = new Player(window->CenterX() - 300, 100);
	MainGame::scene->Add(player, MOVING);

	Ground* ground = new Ground(window->CenterX(), 780, 5500, 120);
	MainGame::scene->Add(ground, MOVING);
	
	Ground* leftborder = new Ground(-2000, 1280, 100, 4000);
	MainGame::scene->Add(leftborder, STATIC);

	Ground* rightborder = new Ground(3200, 1280, 100, 4000);
	MainGame::scene->Add(rightborder, STATIC);

	Door* rightdoor = new Door(3100, 1280, 100, 4000);
	MainGame::scene->Add(rightdoor, STATIC);

	Enemy* enemy = new Enemy(window->CenterX() + 100, 100, 0);
	MainGame::scene->Add(enemy, MOVING);

	Ground* platform = new Ground(window->CenterX() + 100, window->CenterY() + 30, 500, 50);
	MainGame::scene->Add(platform, MOVING);
	//Inimigo 1

	Gostosa* enemy2 = new Gostosa(window->CenterX() + -1900, 100, 1);
	MainGame::scene->Add(enemy2, MOVING);
	
	Ground* platform2 = new Ground(window->CenterX() - 2000, window->CenterY() + 30, 500, 50);
	MainGame::scene->Add(platform2, MOVING);
	//Inimigo 2
	
	Dino* dino = new Dino(window->CenterX() + 1000, 50, 1);
	MainGame::scene->Add(dino, MOVING);

	Enemy* enemy4 = new Enemy(window->CenterX() + 2000, 50, 0);
	MainGame::scene->Add(enemy4, MOVING);

	Ground* platform3 = new Ground(window->CenterX() + 1000, window->CenterY() + 100, 500, 50);
	MainGame::scene->Add(platform3, MOVING);

	Ground* platform4 = new Ground(window->CenterX() - 800, window->CenterY() + 100, 500, 50);
	MainGame::scene->Add(platform4, MOVING);
}

void Level1::Finalize() {
//	MainGame::audio->Stop(LV1);
}

void Level1::Update() {
	// Proximo level ----------
	if (window->KeyCtrl('N'))
		Engine::Next<Level2>();
	// ------------------------

	// Visualizar a BBox ----
	if (window->KeyCtrl('B'))
		viewBbox = !viewBbox;
	// ----------------------

	// Atualizações da cena ----
	MainGame::scene->Update();
	MainGame::scene->CollisionDetection();
	window->CenterX();
	// -------------------------

	/*if (window->KeyUp('I')){
		keyCtrl = true;
	}

	if (keyCtrl && window->KeyDown('I')){
		MainGame::audio->Play(BLUE,false);	}*/

}

void Level1::Draw() {
	lifeSuper->Draw(186, 66, Layer::MIDFRONT);
	MainGame::scene->Draw();

	if (viewBbox) {
		ViewBBox();
	}
}


void Level1::ViewBBox() {
	Engine::renderer->BeginPixels();
	// cor compactada em 32 bits
	ulong magenta = (255 << 24) + (255 << 16) + (0 << 8) + 255;
	MainGame::scene->Begin();
	Object* obj = nullptr;
	while (obj = MainGame::scene->Next()) {
		if (obj->bbox)
			Engine::renderer->Draw(obj->bbox, magenta);
	}
	Engine::renderer->EndPixels();
}
