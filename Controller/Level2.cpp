// Inclusões --------
#include "Level2.h"
#include "MainGame.h"
#include "Background.h"
#include "Player.h"
#include "Ground.h"
#include "Engine.h"
#include "Level1.h"
#include "Object.h"
#include "Gostosa.h"
#include "Enemy.h"
#include "Dino.h"
#include "DoorFinal.h"
// ------------------

void Level2::Init() {
	MainGame::scene = new Scene();

	Background* background = new Background("Resources/Backgrounds/level2teste.png", "", "");
	MainGame::scene->Add(background, STATIC);
	
	//MainGame::audio = new Audio();
	//MainGame::audio->Add(LV2, "Resources/OST/Roots(Level1).wav");

	//MainGame::audio->Play(LV2, true);

	Player* player = new Player(window->CenterX() - 300, 100);
	MainGame::scene->Add(player, MOVING);
	
	Ground* ground = new Ground(window->CenterX(), 780, 5500, 200);
	MainGame::scene->Add(ground, MOVING);

	Ground* leftborder = new Ground(-2000, 1280, 100, 4000);
	MainGame::scene->Add(leftborder, STATIC);

	Ground* rightborder = new Ground(3200, 1280, 100, 4000);
	MainGame::scene->Add(rightborder, STATIC);

	DoorFinal* finaldoor = new DoorFinal(3200, 1280, 100, 4000);
	MainGame::scene->Add(finaldoor, STATIC);

	Enemy* enemy = new Enemy(window->CenterX() - 300, 100, 0);
	MainGame::scene->Add(enemy, MOVING);

	Gostosa* gostosa = new Gostosa(window->CenterX() + 100, 100, 1);
	MainGame::scene->Add(gostosa, MOVING);

	Dino* dino = new Dino(window->CenterX() - 100, 100, 2);
	MainGame::scene->Add(dino, MOVING);

}

void Level2::Finalize() {
	MainGame::audio->Stop(LV2);
}

void Level2::Update() {
	// Level anterior ---------
	if (window->KeyDown('M')) 
		Engine::Next<Level1>();
	// ------------------------

	// Visualizar a BBox ----
	if (window->KeyCtrl('B'))
		viewBbox = !viewBbox;
	// ----------------------

	// Atualizações da cena ----
	MainGame::scene->Update();
	MainGame::scene->CollisionDetection();
	// -------------------------
}

void Level2::Draw() {
	MainGame::scene->Draw();

	if (viewBbox) {
		ViewBBox();
	}
}

void Level2::ViewBBox() {
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