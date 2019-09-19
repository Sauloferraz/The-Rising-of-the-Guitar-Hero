// Includes ------------
#include "Engine.h"
#include "EndGame.h"
#include "Menu.h"
#include "MainGame.h"
// ---------------------

void EndGame::Init() {
	background = new Sprite("Resources/Scenes/Menu/EndGame.png");
	gameCtrl = new Controller();

	MainGame::audio = new Audio();
	MainGame::audio->Add(EG, "Resources/OST/Shots(EndGame).wav");

	MainGame::audio->Play(EG, true);

	gameCtrl->InitializeXbox(PLAYER1);
}

void EndGame::Finalize() {
	delete background;
	MainGame::audio->Stop(EG);
}

void EndGame::Update() {

	gameCtrl->XboxUpdateState(PLAYER1);
	// Sai do jogo com a tecla ESC ---
	if (window->KeyDown(VK_ESCAPE) || gameCtrl->XboxButton(ButtonBack)) {
		window->Close();
	}
	if (window->KeyDown(VK_RETURN) || gameCtrl->XboxButton(ButtonStart)) {
		Engine::Next<Menu>();
	}
	// -------------------------------
}

void EndGame::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}


