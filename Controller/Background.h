#ifndef _Background_h_
#define _Background_h_

// Inclus�es ------						
#include "Object.h"						
#include "Sprite.h"	
// ----------------

// Background ---------------------------------------------------------------------------------
class Background : public Object {
private:
	Sprite* backgF	= new Sprite("Resources/BG.png");		    // Layer 1
	Sprite* backgB	= new Sprite("Resources/BackgBack.png");	// Layer 2
	Sprite* sky		= new Sprite("Resources/Sky.png");			// Fundo est�tico do background

public:
	Background(string imageLocal, string imageLocal2, string imageLocal3);	// Construtor
	~Background();	// Destrutor

	void Update();		// Atualiza��o do objeto
	void Draw();		// Desenho do objeto
	void WorldMoving();	// Atualiza posi��o em realiza��o ao mundo
};
// ---------------------------------------------------------------------------------------------

#endif