// Inclusões --------
#include "Level1.h"
#include "MainGame.h"
#include "Background.h"
#include "Player.h"
#include "Ground.h"
#include "Engine.h"
#include "Level2.h"
#include "Object.h"
// ------------------

void Level1::Init() {
	MainGame::scene = new Scene();

	lifeSuper = new Sprite("Resources/lifesuper.png");

	Background* background = new Background("Resources/Backgrounds/Level1.png", "", "");
	MainGame::scene->Add(background, STATIC);
	Player* player = new Player(window->CenterX() - 100, 100);
	MainGame::scene->Add(player, MOVING);
	Ground* ground = new Ground(window->CenterX(), 780, 1280, 200);
	MainGame::scene->Add(ground, MOVING);
	Ground* ground2 = new Ground(1280, 654, 125, 200);
	MainGame::scene->Add(ground2, MOVING);
	Ground* ground3 = new Ground(0, 654, 125, 200);
	MainGame::scene->Add(ground3, MOVING);
	Ground* ground4 = new Ground(1470, 638, 260, 300);
	MainGame::scene->Add(ground4, MOVING);
	Ground* ground5 = new Ground(-190, 638, 260, 300);
	MainGame::scene->Add(ground5, MOVING);
}

void Level1::Finalize() {

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
