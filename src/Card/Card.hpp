#ifndef Card_HPP
#define Card_HPP
#include "GameObject.hpp"
#include "Plant.hpp"
class Card :public GameObject{
private:
  int cd=0;
  int price=0;
public:
  Card(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,int cd,int price):
    GameObject(imageID, x, y, layer, width, height, animID),
  cd(cd),price(price){};
  void Update() override {};
  void Click(hand_type);
  tp type()override { return tp::other; }
};
class SunflowerSeed :public Card{
private:
public:
  SunflowerSeed() :
    Card(IMGID_SEED_SUNFLOWER,130,WINDOW_HEIGHT-44, LAYER_UI,50,70, ANIMID_NO_ANIMATION,240,50){};
  void OnClick();
};
class PeashooterSeed :public Card {
private:
public:
  PeashooterSeed() :
    Card(IMGID_SEED_PEASHOOTER, 190, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 240, 100) {};
  void OnClick();
};
class WallnutSeed :public Card {
private:
public:
  WallnutSeed() :
    Card(IMGID_SEED_WALLNUT, 250, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 900, 50) {};
  void OnClick();
};
class CherryBombSeed :public Card {
private:
public:
  CherryBombSeed() :
    Card(IMGID_SEED_CHERRY_BOMB, 310, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 1200, 150) {};
  void OnClick();
};
class RepeaterSeed :public Card {
private:
public:
  RepeaterSeed() :
    Card(IMGID_SEED_REPEATER, 370, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 240, 200) {};
  void OnClick();
};
#endif // !Card_HPP
