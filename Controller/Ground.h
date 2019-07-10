#ifndef Ground_h
#define Ground_h

// Inclusões ------
#include "Object.h"
#include "Animation.h"
// ----------------

// Ground --------------------
class Ground : public Object {
private:
public:
	Ground(float x, float y, float sizeX, float sizeY);
	~Ground();
	void Update();
	void Draw();
	void WorldMoving();
};
// ----------------------------

#endif 