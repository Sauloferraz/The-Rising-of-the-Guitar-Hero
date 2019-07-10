// Inclusões --------
#include "Level2.h"
#include "MainGame.h"
#include "Background.h"
#include "Player.h"
#include "Ground.h"
#include "Engine.h"
#include "Level1.h"
#include "Object.h"
// ------------------

void Level2::Init() {
	MainGame::scene = new Scene();

	Background* background = new Background("Resources/Backgrounds/Level2.png", "", "");
	MainGame::scene->Add(background, STATIC);
	Player* player = new Player(window->CenterX() - 100, 100);
	MainGame::scene->Add(player, MOVING);
	Ground* ground = new Ground(window->CenterX(), 780, 1280, 200);
	MainGame::scene->Add(ground, MOVING);
}

void Level2::Finalize() {

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