#ifndef Super_h
#define Super_h

// Inclusões ---------
#include "Object.h"
#include "Animation.h"
// -------------------

// Super ---------------------
class Super : public Object {
private:
	TileSet* tileSet;
public:
	Super(float percent);
	~Super();
	void Update();
	void Draw();
	void WorldMoving();
};
// ----------------------------

#endif 
