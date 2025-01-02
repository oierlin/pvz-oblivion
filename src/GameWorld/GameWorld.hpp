#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"
#include "utils.hpp"
#include <GameObject.hpp>


class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this".
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;
  void PlantSeed(int x,int y);
  void Sethand(hand_type);
  int GetTick();
  hand_type Gethand();
  void GenerateSun(int, int);
  void SetMask(int,int,int);
  bool HaveZomie(int);
  void GeneratePea(int, int);
  void GenerateExplosion(int, int);
  std::shared_ptr <GameObject> Crash(std::shared_ptr<GameObject>);
private:
  std::list<std::shared_ptr<GameObject>> Object_list;
  hand_type hand=hand_type::none;
  int tick = 0;
  int wave_tick=0;
  bool IsCrash(std::shared_ptr<GameObject>, std::shared_ptr<GameObject>);
  int abs(int);
  void CheckCrash();
};

#endif // !GAMEWORLD_HPP__
