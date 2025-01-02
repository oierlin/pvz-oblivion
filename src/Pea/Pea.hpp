#ifndef Pea_HPP
#define Pea_HPP
#include "GameObject.hpp"
class Pea :public GameObject{
private:
public:
	Pea(int x, int y) :
		GameObject(IMGID_PEA, x, y, LAYER_PROJECTILES, 28, 28, ANIMID_NO_ANIMATION) {};
	void Update() override;
	void OnClick() override {};
	tp type()override { return tp::pea; }
};
#endif // !Pea_HPP
