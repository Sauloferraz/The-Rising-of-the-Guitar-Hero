#include "Menu.h"
#include "MainGame.h"
#include "Mouse.h"
#include "Option.h"
#include "Engine.h"
#include "Level1.h"
#include "Object.h"

void Menu::Init() {
	MainGame::scene = new Scene();
	
	gameCtrl = new Controller();

	gameCtrl->InitializeXbox(PLAYER1);

	MainGame::audio = new Audio();
	MainGame::audio->Add(MENU, "Resources/OST/Zero(Menu).wav");

	MainGame::audio->Play(MENU, true);

	background = new Sprite("Resources/Scenes/Menu/BG.png");

	Mouse* mouse = new Mouse();
	MainGame::scene->Add(mouse, MOVING);

	Option* option = new Option(820, 310, START, "Resources/Scenes/Menu/StartGame.png", 2, 1);
	MainGame::scene->Add(option, STATIC);
	//Option* option2 = new Option(920, 360, SCORE, "Resources/Scenes/Menu/MultiPlayer.png", 3, 1);
	//MainGame::scene->Add(option2, STATIC);
	
	Option* option3 = new Option(820, 415, HELP, "Resources/Scenes/Menu/Tutorial.png", 2, 1);
	MainGame::scene->Add(option3, STATIC);
	
	//Option* option4 = new Option(620, 470, ABOUT, "Resources/Scenes/Menu/menuChar.png", 1, 3);
	//MainGame::scene->Add(option4, STATIC);
		
	Option* option5 = new Option(820, 525, EXIT, "Resources/Scenes/Menu/ExitGame.png", 2, 1);
	MainGame::scene->Add(option5, STATIC);
}

void Menu::Update() {
	
	gameCtrl->XboxUpdateState(PLAYER1);
	// Visualizar a BBox ----
#if defined(_DEBUG)
	if (window->KeyCtrl('B'))
		MainGame::ViewBbox();
#endif
	// ----------------------

	if (gameCtrl->XboxButton(ButtonStart)) {
		Engine::Next<Level1>();
		MainGame::audio->Stop(MENU);
	}

	if (gameCtrl->XboxButton(ButtonBack)) {
		window->Close();
	}


	MainGame::scene->Update();
	MainGame::scene->CollisionDetection();
}

void Menu::Draw() {
	MainGame::scene->Draw();
	background->Draw(window->CenterX(), window->CenterY(), 0.99);

	if (MainGame::isViewingBbox()) {
		Engine::renderer->BeginPixels();
		// Cor compactada em 32 bits
		ulong magenta = (255 << 24) + (255 << 16) + (0 << 8) + 255;
		MainGame::scene->Begin();
		Object* obj = nullptr;
		while (obj = MainGame::scene->Next()) {
			if (obj->bbox)
				Engine::renderer->Draw(obj->bbox, magenta);
		}
		Engine::renderer->EndPixels();
	}
}

void Menu::Finalize() {
	MainGame::audio->Stop(MENU);
}
