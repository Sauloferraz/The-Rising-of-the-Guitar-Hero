// Includes ------------
#include "Engine.h"
#include "Tutorial.h"
#include "Menu.h"
#include "Player.h"
#include "MainGame.h"
#include "Ground.h"
#include "Object.h"
#include "Acorde.h"
#include "Enemy.h"
#include "Door.h"
#include <iostream>
#include "Gostosa.h"
#include "GameOver.h"
#include "Player.h"
// ---------------------

void Tutorial::Init() {
	MainGame::scene = new Scene();
	
	background = new Sprite("Resources/Backgrounds/TutorialBG.png");
	gameCtrl = new Controller();

	MainGame::audio = new Audio();
	MainGame::audio->Add(TT, "Resources/OST/Warriors(Level2).wav");

	MainGame::audio->Play(TT, true);

	gameCtrl->InitializeXbox(PLAYER1);

	Player* player = new Player(window->CenterX() - 300, 100);
	MainGame::scene->Add(player, MOVING);

	Ground* ground = new Ground(window->CenterX(), 720, 5000, 120);
	MainGame::scene->Add(ground, MOVING);

	//Ground* leftborder = new Ground(-1280, 1280, 100, 4000);
	//MainGame::scene->Add(leftborder, STATIC);

	//Ground* rightborder = new Ground(1000, 1280, 100, 4000);
	//MainGame::scene->Add(rightborder, STATIC);

}

void Tutorial::Finalize() {
	delete background;
	MainGame::audio->Stop(TT);
}

void Tutorial::Update() {
	gameCtrl->XboxUpdateState(PLAYER1);

	MainGame::scene->Update();
	MainGame::scene->CollisionDetection();
	window->CenterX();
	
	if (window->KeyCtrl('B'))
		viewBbox = !viewBbox;

	// Sai do jogo com a tecla ESC ---
	//if (window->KeyDown(VK_ESCAPE) || gameCtrl->XboxButton(ButtonBack)) {
		//window->Close();
	//}

	if (window->KeyDown(VK_RETURN) || gameCtrl->XboxButton(ButtonBack)) {
		Engine::Next<Menu>();
	}
	// -------------------------------
}

void Tutorial::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);

	MainGame::scene->Draw();

	if (viewBbox) {
		ViewBBox();
	}
}

void Tutorial::ViewBBox() {
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


