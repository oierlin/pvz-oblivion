#ifndef Shovel_HPP
#define Shovel_HPP
#include "GameObject.hpp"
class Shovel :public GameObject{
private:
public:
	Shovel();
	void Update() override {};
	void OnClick() override;
	tp type()override { return tp::shovel; }
};
#endif // !Shovel_HPP
