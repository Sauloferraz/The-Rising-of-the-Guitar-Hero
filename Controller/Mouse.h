#ifndef Mouse_h
#define Mouse_h

// Inclus�o -------
#include "Object.h"		
#include "Types.h"		
// ----------------

class Mouse : public Object {
public:
	Mouse();							// Construtor
	~Mouse();							// Destrutor

	bool Clicked();						// Click do mouse
	void Update();						// Atualiza o objeto
	void OnCollision(Object* obj);		// Detecta Colis�o
	void Draw();						// Desenha o objeto
};

// ---------------------------------------------------------------------------------

#endif
