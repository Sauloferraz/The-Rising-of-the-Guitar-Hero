// Inclusões ----------
#include "Mouse.h"
#include "Option.h"
#include "MainGame.h"
#include "Engine.h"
#include "Controller.h"
#include "Level1.h"
#include "Tutorial.h"
// --------------------

Mouse::Mouse() {
	x = window->MouseX();
	y = window->MouseY();
	bbox = new Point(x, y);

	type = MOUSE;
}

Mouse::~Mouse() {
	delete bbox;
}

void Mouse::Update() {
	MoveTo(window->MouseX(), window->MouseY());
}

void Mouse::OnCollision(Object* obj) {
	Option* option = (Option*)obj;

	switch (obj->Type()) {
	case OPTION:
		switch (option->MenuType()) {
		case START:
			if (Clicked()) {
				Engine::Next<Level1>();
				MainGame::audio->Stop(MENU);
			}
			break;

		case HELP:
			if (Clicked()) {
				Engine::Next<Tutorial>();
			}

		case EXIT:
			if (Clicked()) {
				window->Close();
			}
			break;
		}
	}
}

void Mouse::Draw() {

}

bool Mouse::Clicked() {
	if (window->KeyCtrl(VK_LBUTTON))
		return true;
	else
		return false;
}