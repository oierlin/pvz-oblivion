#ifndef Plant_HPP
#define Plant_HPP
#include "GameObject.hpp"
class Plant :public GameObject{
private:
public:
  Plant(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID):
    GameObject(imageID, x, y, layer, width, height, animID){};
  tp type()override { return tp::plant; }
  void OnClick() override;
};
class Sunflower :public Plant {
private:
  int cd=0;
public:
  Sunflower(int x, int y) :
    Plant(IMGID_SUNFLOWER, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM),
    cd(randInt(30,600)){
    SetHP(300);
  };
  void Update() override;
};
class Peashooter :public Plant {
private:
  int cd=0;
public:
  Peashooter(int x, int y) :
    Plant(IMGID_PEASHOOTER, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM){
    SetHP(300);
  };
  void Update() override;
};
class Wallnut :public Plant {
public:
  Wallnut(int x, int y) :
    Plant(IMGID_WALLNUT, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM) {
    SetHP(4000);
  };
  void Update() override;
};
class CherryBomb :public Plant {
private:
  int time = 15;
public:
  CherryBomb(int x, int y) :
    Plant(IMGID_CHERRY_BOMB, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM) {
    SetHP(4000);
  };
  void Update() override;
};
class Repeater :public Plant {
private:
  int cd = 0,scd = -1;
public:
  Repeater(int x, int y) :
    Plant(IMGID_REPEATER, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM) {
    SetHP(300);
  };
  void Update() override;
};
#endif // !Plant_HPP
