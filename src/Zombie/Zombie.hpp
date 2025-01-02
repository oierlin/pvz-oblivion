#ifndef Zombie_HPP
#define Zombie_HPP
#include "GameObject.hpp"
class Zombie :public GameObject{
private:
  bool eat = 0;
public:
  Zombie(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID):
    GameObject(imageID, x, y, layer, width, height, animID){};
  tp type()override { return tp::zombie; }
  void OnClick() override {};
  void Update() override;
  bool Iseating();
  void Walk();
  void Eat();
};
class Regular :public Zombie {
public:
  Regular(int x,int y):
    Zombie(IMGID_REGULAR_ZOMBIE, x, y, LAYER_ZOMBIES, 20, 80, ANIMID_WALK_ANIM) {
    SetHP(200);
  };
};
class BucketHead :public Zombie {
public:
  BucketHead(int x, int y) :
    Zombie(IMGID_BUCKET_HEAD_ZOMBIE, x, y, LAYER_ZOMBIES, 20, 80, ANIMID_WALK_ANIM) {
    SetHP(1300);
  };
  void Update() override;
};
class PoleVaulting :public Zombie {
private:
  bool run = 1;
  int jump = 0;
public:
  PoleVaulting(int x, int y) :
    Zombie(IMGID_POLE_VAULTING_ZOMBIE, x, y, LAYER_ZOMBIES, 20, 80, ANIMID_RUN_ANIM) {
    SetHP(340);
  };
  void Update() override;
};
#endif // !Zombie_HPP
