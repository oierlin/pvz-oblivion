#ifndef PlantingSpot_HPP
#define PlantingSpot_HPP
#include "GameObject.hpp"
class PlantingSpot :public GameObject{
private:
public:
	PlantingSpot(int x,int y);
	void Update() override{};
	void OnClick() override;
	tp type()override { return tp::other; }
};
#endif // !PlantingSpot_HPP
