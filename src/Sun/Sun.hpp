#ifndef Sun_HPP
#define Sun_HPP
#include "GameObject.hpp"
#define natural false
#define flower true
class Sun :public GameObject{
private:
	int time = 0;
	bool sun_type;
	int a=4;
public:
	Sun(int,int,bool);
	void Update() override;
	void OnClick() override;
	tp type()override { return tp::other; }
};
#endif // !Sun_HPP
