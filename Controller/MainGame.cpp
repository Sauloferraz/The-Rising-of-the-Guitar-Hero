// Inclusões --------
#include "Engine.h"
#include "Resources.h"
#include "Level1.h"
#include "MainGame.h"
#include "Menu.h"
// ------------------

// Declarações Static
float MainGame::velX;
float MainGame::velY;
bool  MainGame::viewBbox;
Scene* MainGame::scene;
Audio* MainGame::audio = nullptr;
// ------------------

// Main -------------------------------------------------------------------------------------------------------------------                                  
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	// Inicializa a engine -------
	Engine* engine = new Engine();
	// ---------------------------

	// Configura a janela do jogo ----
	Engine::window->Mode(WINDOWED);
	Engine::window->Size(1280, 720);
	Engine::window->Color(25, 25, 25);
	Engine::window->Title("The Rising of the Guitar Hero");
	Engine::window->Icon(IDI_ICON);
	// -------------------------------

	// Ativa o console --------------------
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	// ------------------------------------

	// Habilita a sincronização de quadros
	engine->graphics->VSync(true);
	// -----------------------------------

	#if defined(_DEBUG) 
		int status = engine->Start(new Menu());
	#endif

	// Inicia o jogo ------------------------
	 // int status2 = engine->Start(new Level1());
	// --------------------------------------

	// Finaliza a engine
	delete engine;

	// -----------------

	return status;
}
// ------------------------------------------------------------------------------------------------------------------------
