#ifndef Door_h
#define Door_h

// Inclusões ------
#include "Object.h"
#include "Animation.h"
// ----------------

// Ground --------------------
class Door : public Object {
private:
public:
	Door(float x, float y, float sizeX, float sizeY);
	~Door();
	void Update();
	void Draw();
	void WorldMoving();
};
// ----------------------------

#endif 