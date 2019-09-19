// Includes ------------
#include "Engine.h"
#include "GameOver.h"
#include "Menu.h"
#include "MainGame.h"
// ---------------------

void GameOver::Init() {
	background = new Sprite("Resources/Scenes/Menu/GameOver.png");
	gameCtrl = new Controller();

	MainGame::audio = new Audio();
	MainGame::audio->Add(GO, "Resources/OST/NLTS(GameOver).wav");

	MainGame::audio->Play(GO, true);

	gameCtrl->InitializeXbox(PLAYER1);

}

void GameOver::Finalize() {
	delete background;
	MainGame::audio->Stop(GO);
}

void GameOver::Update() {

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

void GameOver::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}


