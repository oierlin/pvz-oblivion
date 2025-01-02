#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"
// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;
enum class tp {plant,pea,zombie,other,shovel,explosion};
enum class hand_type {sunflower,peashooter,wallnut,cherry,repeater,shovel,none};
class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".
  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
    :ObjectBase(imageID, x, y, layer, width, height, animID) {};
  void SetWorld(std::shared_ptr<GameWorld>);
  std::shared_ptr<GameWorld> GetWorld();
  virtual void Update() =0;
  virtual void OnClick() =0;
  void Die();
  bool Dying();
  virtual tp type()=0;
  int GetHP();
  void SetHP(int);
private:
  static std::shared_ptr<GameWorld> World_ptr;
  bool deth = false;
  int hp=0;
};


#endif // !GAMEOBJECT_HPP__
