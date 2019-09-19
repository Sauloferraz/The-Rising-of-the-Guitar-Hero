#ifndef DoorFinal_h
#define DoorFinal_h

// Inclusões ------
#include "Object.h"
#include "Animation.h"
// ----------------

// Ground --------------------
class DoorFinal : public Object {
private:
public:
	DoorFinal(float x, float y, float sizeX, float sizeY);
	~DoorFinal();
	void Update();
	void Draw();
	void WorldMoving();
};
// ----------------------------

#endif 