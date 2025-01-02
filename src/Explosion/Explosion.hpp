#ifndef Explosion_HPP
#define Explosion_HPP
#include "GameObject.hpp"
class Explosion :public GameObject{
private:
	int time = 3;
public:
	Explosion(int x, int y) :
		GameObject(IMGID_EXPLOSION, x, y, LAYER_PROJECTILES, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT, ANIMID_NO_ANIMATION) {};
	void Update() override;
	void OnClick() override {};
	tp type()override { return tp::explosion; }
};
#endif // !Explosion_HPP
