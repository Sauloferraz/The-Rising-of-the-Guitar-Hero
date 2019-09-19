// Inclusoes ----------
#include "Intro.h"
#include "MainGame.h"
#include "Engine.h"
#include "Font.h"
#include "Menu.h"
#include <iomanip>
// --------------------

void Intro::Init() {
	MainGame::scene = new Scene();
	MainGame::audio = new Audio();

	background = new Background(window->CenterX(), window->CenterY(),
		"Resources/Scenes/Intro/Background.png",
		0, 0, "",
		0, 0, "");
	MainGame::scene->Add(background, STATIC);

	glasses = new TileSet("Resources/Scenes/Intro/Glasses.png", 8, 1);
	glassesA = new Animation(glasses, 0.75f / 8.0f, false);

	MainGame::audio->Add(GEAR, "Resources/OST/Intro.wav");
}

void Intro::Finalize() {
	MainGame::audio->Stop(GEAR);

	delete glasses;
	delete glassesA;
	delete background;
}

void Intro::Update() {
	// Passa pra próxima cena -----
	if (timer <= 0.0) {
		Engine::Next<Menu>();
	}
	// ----------------------------
	// Fade Out --------------
	else if (timer <= 2.0) {
		alpha -= gameTime / 2;
	}
	// -----------------------
	// Executa o audio da engrenagem -
	else if (timer <= 6.3 && !start) {
		MainGame::audio->Play(GEAR);
		start = true;
	}
	// -------------------------------
	// Fade In -----------------
	else if (timer > 6.3) {
		alpha += gameTime / 1.7;
	}
	// -------------------------

	timer -= gameTime;	// Reduz contador

	MainGame::scene->Update();	// Atualiza a cena
}

void Intro::Draw() {
	MainGame::scene->Draw();	// Desenha a cena

	glassesA->Draw(window->CenterX(), window->CenterY(),
		0.01f, 0.25f, 0.0f,
		*new Color(1.0f, 1.0f, 1.0f, alpha));

	// Inicia a animação junto com a música ----
	if (timer <= 6.3) {
		glassesA->NextFrame();

		if (glassesA->Frame() == 4) {
			glassesA->Restart();
		}
		else if (timer <= 2.375f && !start2) {
			glassesA->Frame(5);
			start2 = true;
		}
		else if (timer <= 2.0f) {
			glassesA->Frame(1);
		}
	}
	// -----------------------------------------
}
