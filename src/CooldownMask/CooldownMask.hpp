#ifndef CooldownMask_HPP
#define CooldownMask_HPP
#include "GameObject.hpp"
#include "Card.hpp"
class CooldownMask :public GameObject{
private:
  int cd = 0;
public:
  CooldownMask(int x,int y,int cd):
    GameObject(IMGID_COOLDOWN_MASK, x, y, LAYER_COOLDOWN_MASK, 50 ,70, ANIMID_NO_ANIMATION),
  cd(cd){};
  void Update() override;
  void OnClick() override {};
  tp type() { return tp::other; }
};
#endif // !Card_HPP
