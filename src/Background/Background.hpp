#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include "GameObject.hpp"
class Background :public GameObject{
private:
public:
	Background(std::shared_ptr<GameWorld>);
	void Update() override{};
	void OnClick() override{};
	tp type()override { return tp::other; }
};
#endif // !BACKGROUND_HPP
