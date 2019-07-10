// Inclusões ------
#include "Player.h"
#include "MainGame.h"
#include "iostream"
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
}

void Player::Update() {
	controller->XboxUpdateState(PLAYER1);

	// Reafirma os estados
	MainGame::VelX(0);
	// -------------------

	// Teste de dano --------
	if (window->KeyCtrl('R'))
		life->Damage(20);
	// ----------------------

	// Inputs -----------------------------------------
	// Right Arrow ---------------
	if ((window->KeyDown(VK_RIGHT) || controller->XboxAnalog(ThumbLX) > 0) && !righted)
		MainGame::VelX(-walkVelocity);
	// ---------------------------
	
	// Left Arrow ---------------
	if ((window->KeyDown(VK_LEFT) || controller->XboxAnalog(ThumbLX) < 0) && !lefted)
		MainGame::VelX(walkVelocity);
	// --------------------------
	
	// Space --------------------------------
	if ((window->KeyCtrl(VK_SPACE) || controller->XboxButton(ButtonA)) && grounded) {
		velY = -jumpHeight;
		grounded = false;
	}
	// --------------------------------------
	// -------------------------------------------------

	// Movimentação ------------------------------------------------------------------
	Gravity();						// Executa a força da gravidade
	StateMachine();					// Realiza a escolha das animações	
	Translate(0, velY * gameTime);	// Realiza o movimento
	// -------------------------------------------------------------------------------
	
	// Reafirma os estados
	grounded = false;
	upped = false;
	righted = false;
	lefted = false;
	// -------------------
}

void Player::OnCollision(Object* obj) {
	if (obj->Type() == GROUND){
		Rect* object = (Rect*)obj->bbox;
		Rect* player = (Rect*)bbox;

		if (player->Right() > object->Left() + 6 && player->Left() < object->Right() - 6) {
			if (y < obj->Y()) {
				grounded = true;
				MoveTo(x, object->Top() - 100);
			} else {
				upped = true;
				MoveTo(x, object->Bottom() + 100);
			}
		} else {
			if (x > obj->X() && y != object->Top() - 50) {
				lefted = true;
			} else if (x < obj->X() && y != object->Top() - 50) {
				righted = true;
			}
		}
	}
}

void Player::Draw() {
	switch (currentState) {
		case R:
			ra->Draw(x, y - 25);
			ra->NextFrame();
			if (ra->Frame() == 30) {	// Repete a animação sem o dash
				ra->Frame(15);
			}
			break;
		
		case L:
			la->Draw(x, y - 25);
			la->NextFrame();
			if (la->Frame() == 30) {	// Repete a animação sem o dash
				la->Frame(15);
			}
			break;
		
		case SR:
			sra->Draw(x, y - 25);
			sra->NextFrame();
			break;
		
		case SL:
			sla->Draw(x, y - 25);
			sla->NextFrame();
			break;
		
		case P:
			pa->Draw(x, y - 25);
			pa->NextFrame();
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
	
	if (MainGame::VelX() < 0) {			// State Machine
		currentState = R;
	} else if (MainGame::VelX() > 0) {
		currentState = L;
	} else {
		if (facingRight) {
			currentState = SR;
		} else {
			currentState = SL;
		}
	}

	if (currentState != previousState) {	// Reseta as animações caso o estado mude
		ResetAnimation();
	}
}

void Player::ResetAnimation() {
	ra->Restart();
	la->Restart();
	sra->Restart();
	sla->Restart();
}
