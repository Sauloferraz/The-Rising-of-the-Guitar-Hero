// Inclusões ------
#include "Player.h"
#include "MainGame.h"
#include "Enemy.h"
#include "Acorde.h"
#include "GameOver.h"
#include "Engine.h"
#include "Level2.h"
#include "Menu.h"
#include "EndGame.h"
#include <iostream>
#include <iomanip>
// ----------------

Player::Player(float x, float y) {
	xinput = controller->InitializeXbox(PLAYER1);

	bbox = new Rect(-50, -100, 50, 100);
	type = PLAYER;
	MoveTo(x, y);
	MainGame::scene->Add(life, STATIC);
}

Player::~Player() {
	delete bbox;

	MainGame::audio->Stop(YELLOW);
	MainGame::audio->Stop(ORANGE);
	MainGame::audio->Stop(BLUE);

	delete ir, il, rr, rl, gro, glo, dr, dl, jr, jl, dmgr, dmgl;
	delete gry, gly, grb, glb;
}

void Player::Update() {
	controller->XboxUpdateState(PLAYER1);

	if (window->KeyDown('Z')) {
		Engine::Next<GameOver>();
	}

	// Reafirma os estados
	if (grounded) {
		bbox = new Rect(-50, -100, 50, 100);
		type = PLAYER;
		MoveTo(x, y);
	}

	Damage();

	MainGame::VelX(0);
	dodge = false;
	playingY = false;
	playingB = false;
	playingO = false;
	keyCtrl = false;
	// -------------------

	// Teste de dano --------
	if (window->KeyCtrl('R')) {

		/*Acorde* seila;

		if (facingRight) {
			seila = new Acorde(x + 50, y, 700);
			seila->Right();
			MainGame::scene->Add(seila, MOVING);
		}
		else {
			seila = new Acorde(x - 50, y, 700);
			seila->Left();
			MainGame::scene->Add(seila, MOVING);
		}*/
	}
	// ----------------------

	// Inputs -----------------------------------------
	// Walk Right ---------------
	if ((window->KeyDown('D') || controller->XboxButton(DpadDown) || (controller->XboxAnalog(ThumbLX) > 0)) && !righted) {
		if (window->KeyDown(VK_SHIFT) || controller->XboxTrigger(RightTrigger)) {
			MainGame::VelX(-walkVelocity * 2);
		}
		else MainGame::VelX(-walkVelocity);
	}

	// Walk Left ---------------
	if ((window->KeyDown('A') || controller->XboxButton(DpadUp) || (controller->XboxAnalog(ThumbLX) < 0)) && !lefted) {
		if (window->KeyDown(VK_SHIFT) || controller->XboxTrigger(RightTrigger)) {
			MainGame::VelX(walkVelocity * 2);
		}
		else MainGame::VelX(walkVelocity);
	}

	// Jump --------------------------------
	if ((window->KeyCtrl(VK_SPACE) || controller->XboxButton(ButtonA)) && grounded) {
		velY = -jumpHeight;
		grounded = false;

		bbox = new Rect(-50, -100, 50, 50);
		type = PLAYER;
		MoveTo(x, y);
	}

	//Dodge
	if ((window->KeyDown('S') || controller->XboxTrigger(LeftTrigger) || controller->XboxButton(ButtonB)) && grounded) {
		damage = false;
		dodge = true;
		if (facingRight) {
			MainGame::VelX(-walkVelocity * 2);
			bbox = new Rect(-50, -50, 50, 100);
			type = PLAYER;
			MoveTo(x, y);
		}
		else MainGame::VelX(walkVelocity * 2);
		bbox = new Rect(-50, -50, 50, 100);
		type = PLAYER;
		MoveTo(x, y);
	}

	// Add Blue Music
	if ((window->KeyCtrl('I') || controller->XboxButton(ButtonX))) {
			MainGame::audio = new Audio();
			MainGame::audio->Add(BLUE, "Resources/OST/Blue.wav");
	}

	// Play Guitar Blue
	if ((window->KeyDown('I') || controller->XboxButton(ButtonX)) && grounded) {
		MainGame::VelX(0);
		playingB = true;

		Acorde* seila;
		if (fireTime < 0) {
			if (facingRight) {
				MainGame::audio->Play(BLUE, false);
				seila = new Acorde(x + 50, y, 700, 1);
				seila->Right();
				MainGame::scene->Add(seila, MOVING);
				//fireTime = -1;
			}
			else {
				MainGame::audio->Play(BLUE, false);
				seila = new Acorde(x - 50, y, 700, 1);
				seila->Left();
				MainGame::scene->Add(seila, MOVING);
				//fireTime = -1;
			}
		}
		
		if (fireTime < 0) {
			fireTime = 0.5;
			//MainGame::audio->Stop(BLUE);
		}
			
	}

	//Add Orange Music
	if ((window->KeyCtrl('O') || controller->XboxButton(LeftBumper))) {
			MainGame::audio = new Audio();
			MainGame::audio->Add(ORANGE, "Resources/OST/Orange.wav");
	}

	//Play Guitar Orange
	if ((window->KeyDown('O') || controller->XboxButton(LeftBumper)) && grounded) {
		MainGame::VelX(0);
		playingO = true;

		Acorde* seila;

		if (fireTime < 0) {
			if (facingRight) {
				MainGame::audio->Play(ORANGE, false);
				seila = new Acorde(x + 50, y, 700, 2);
				seila->Right();
				MainGame::scene->Add(seila, MOVING);
				//fireTime = -1;
			}
			else {
				MainGame::audio->Play(ORANGE, false);
				seila = new Acorde(x - 50, y, 700, 2);
				seila->Left();
				MainGame::scene->Add(seila, MOVING);
				//fireTime = -1;
			}
		}

		if (fireTime < 0) {
			fireTime = 0.5;
		}
	}

	//Add Yellow Music
	if ((window->KeyCtrl('U')|| controller->XboxButton(ButtonY))) {
			MainGame::audio = new Audio();
			MainGame::audio->Add(YELLOW, "Resources/OST/Yellow.wav");
	}

	//Play Guitar Yellow
	if ((window->KeyDown('U') || controller->XboxButton(ButtonY)) && grounded) {
		MainGame::VelX(0);
		playingY = true;

		Acorde* seila;

		if (fireTime < 0) {
			if (facingRight) {
				MainGame::audio->Play(YELLOW, false);
				seila = new Acorde(x + 50, y, 700, 0);
				seila->Right();
				MainGame::scene->Add(seila, MOVING);
				//fireTime = -1;
			}
			else {
				MainGame::audio->Play(YELLOW, false);
				seila = new Acorde(x - 50, y, 700, 0);
				seila->Left();
				MainGame::scene->Add(seila, MOVING);
				//fireTime = -1;
			}
		}

		if (fireTime < 0) {
			fireTime = 0.5;
		}
	}

	// Movimentação ------------------------------------------------------------------
	Gravity();						// Executa a força da gravidade
	StateMachine();					// Realiza a escolha das animações	
	Translate(0, velY * gameTime);  // Realiza o movimento
	Damage();	

	if (dead) {
		Engine::Next<GameOver>();
	}

	if (fireTime > -1) {
		fireTime -= gameTime;
	}
	// -------------------------------------------------------------------------------
	
	// Reafirma os estados
	grounded = false;
	upped = false;
	righted = false;
	lefted = false;
	//playing = false;
	damage = false;
	// -------------------
}

void Player::OnCollision(Object* obj) {
	
	Enemy* enemy = (Enemy*)obj;

	if (obj->Type() == GROUND) {
		Rect* object = (Rect*)obj->bbox;
		Rect* player = (Rect*)bbox;

		if (player->Right() > object->Left() + 20 && player->Left() < object->Right() - 20) {
			if (y < obj->Y()) {
				if (gravity > 0) {
					grounded = true;
					if (grounded) {
						MainGame::VelY(0);
					}
				}
				else {
					upped = true;
					if (MainGame::VelY() < 0) {
						MainGame::VelY(0);
					}
				}

				MoveTo(x, object->Top() - 100);
			}
			else {
				if (gravity < 0) {
					grounded = true;
					if (grounded) {
						MainGame::VelY(0);
					}
				}
				else {
					upped = true;
					if (MainGame::VelY() > 0) {
						MainGame::VelY(0);
					}
				}

				MoveTo(x, object->Bottom() + 100);
			}
		}
		else {
			if (x > obj->X() && y != object->Top() - 50 && (int)player->Bottom() != (int)object->Top()) {
				lefted = true;
				//MoveTo(object->Right() + 50, y);
			}
			else if (x < obj->X() && y != object->Top() - 50 && (int)player->Bottom() != (int)object->Top()) {
				righted = true;
				//MoveTo(object->Left() - 50, y);
			}

		}
	}

	if ((obj->Type() == ENEMY) && (!dodge) && (!playingY) && (!playingB) && (!playingO)){
		Rect* object = (Rect*)obj->bbox;
		Rect* player = (Rect*)bbox;

 		if (player->Right() > object->Left() + 6 && player->Left() < object->Right() - 6) {
			if (y < obj->Y()) {
				grounded = true;
				MoveTo(x, object->Top() - 100);
			}
			else {
				//upped = true;
				//MoveTo(x, object->Bottom() + 100);
			}
		}
		else {
			if (x > obj->X() && y != object->Top() - 50) {
				lefted = true;
			}
			else if (x < obj->X() && y != object->Top() - 50) {
				righted = true;
			}
		}		
		damage = true;
	}

	if (obj->Type() == DOOR) {
		door = true;
		Engine::Next<Level2>();
	}

	if (obj->Type() == DFINAL) {
		Engine::Next<EndGame>();
	}
}

void Player::Draw() {
	switch (currentState) {

			case RunR:
			rra->Draw(x, y - 25);
			rra->NextFrame();
			//if (ra->Frame() == 30) {	// Repete a animação sem o dash
			//	ra->Frame(15);
			//}
			break;

		case RunL:
			rla->Draw(x, y - 25);
			rla->NextFrame();
		//	if (la->Frame() == 30) {	// Repete a animação sem o dash
			//	la->Frame(15);
		//	}
			break;

		case IdleR:
			ira->Draw(x, y - 25);
			ira->NextFrame();
			break;

		case IdleL:
			ila->Draw(x, y - 25);
			ila->NextFrame();
			break;

		case JumpR:
			jra->Draw(x, y - 25);
			jra->NextFrame();
			break;

		case JumpL:
			jla->Draw(x, y - 25);
			jla->NextFrame();
			break;

		case GuitarRB:
			grba->Draw(x, y - 25);
			grba->NextFrame();
			break;

		case GuitarLB:
			glba->Draw(x, y - 25);
			glba->NextFrame();
			break;

		case GuitarRY:
			grya->Draw(x, y - 25);
			grya->NextFrame();
			break;

		case GuitarLY:
			glya->Draw(x, y - 25);
			glya->NextFrame();
			break;

		case GuitarRO:
			groa->Draw(x, y - 25);
			groa->NextFrame();
			break;

		case GuitarLO:
			gloa->Draw(x, y - 25);
			gloa->NextFrame();
			break;

		case DodgeR:
			dra->Draw(x, y - 25);
			dra->NextFrame();
			break;

		case DodgeL:
			dla->Draw(x, y - 25);
			dla->NextFrame();
			break;

		case DamageR:
			dmgra->Draw(x, y - 25);
			dmgra->NextFrame();
			break;

		case DamageL:
			dmgla->Draw(x, y - 25);
			dmgla->NextFrame();
			break;

		default:
			break;
	}
}

void Player::Gravity() {
	// Se não estiver no chão executa a gravidade
	if (!grounded) {
		velY += gravity;
	}
	// ------------------------------------------
}

void Player::StateMachine() {
	uint previousState = currentState;	// Para detectar mudança no estado

	if (MainGame::VelX() < 0) {			// Vê se o player está virado para a direita
		facingRight = true;
	} else if (MainGame::VelX() > 0) {
		facingRight = false;
	}

	if (facingRight) {
		if (grounded) {
			if (MainGame::VelX() == 0) {
				currentState = IdleR;
			} else {
				currentState = RunR;
			}
		} else {
			currentState = JumpR;
		}if (playingY) {
			currentState = GuitarRY;
		}if (playingB) {
			currentState = GuitarRB;
		}if (playingO) {
			currentState = GuitarRO;
		}if (dodge) {
			currentState = DodgeR;
		}if (damage) {
			currentState = DamageR;
		}

	} else {
		if (grounded) {
			if (MainGame::VelX() == 0) {
				currentState = IdleL;
			} else {
				currentState = RunL;
			}
		} else {
			currentState = JumpL;
		}if (playingY) {
			currentState = GuitarLY;
		}if (playingB) {
			currentState = GuitarLB;
		}if (playingO) {
			currentState = GuitarLO;
		}if (dodge) {
			currentState = DodgeL;
		}if (damage) {
			currentState = DamageL;
		}
	}

	if (currentState != previousState) {	// Reseta as animações caso o estado mude
		ResetAnimation();
	}
}

void Player::ResetAnimation() {
	ira->Restart();
	ila->Restart();
	rra->Restart();
	rla->Restart();
	jra->Restart();
	jla->Restart();
	grba->Restart();
	glba->Restart();
	grya->Restart();
	glya->Restart();
	gloa->Restart();
	groa->Restart();
	dra->Restart();
	dla->Restart();
	dmgra->Restart();
	dmgla->Restart();
}

void Player::Damage() {
	if (damage && !dodge) {
		life->Damage(1);
	}if (life->Size() == 0) {
		dead = true;
	}
}

int Player::Playing() {
	if (playingY) {
		return 0;
	}

	if (playingB) {
		return 1;
	}

	if (playingO) {
		return 2;
	}
}

float Player::Xpos() {
	return x;
}

bool Player::IsDead() {
	if (life->Size() == 0) {
		return true;
	}	
}