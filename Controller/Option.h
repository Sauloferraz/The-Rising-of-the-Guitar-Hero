#ifndef Option_h
#define Option_h

// Inclusões ---------
#include "Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "Types.h"
#include "Image.h"
// -------------------

enum menuTypes { START, SCORE, HELP, ABOUT, EXIT };

// Option --------------------------------
class Option : public Object {
private:
	TileSet* tileset;	// Folha de sprites da animação
	Animation* animation;	// Animação do menu
	Image* image;		// Image

	uint menuType;

	bool selected = false;

public:
	Option(float x, float y, uint menuType, string img, int lines, int collumns);
	~Option();
	void Update();					// Atualiza o objeto
	void OnCollision(Object* obj);	// Colisão do objeto
	void Draw();					// Desenha o objeto
	uint MenuType();
};

// ---------------------------------------------------------------------------------

#endif