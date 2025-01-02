#include "GameWorld.hpp"
#include "Background.hpp"
#include "PlantingSpot.hpp"
#include "Sun.hpp"
#include "Shovel.hpp"
#include "Card.hpp"
#include "CooldownMask.hpp"
#include "Pea.hpp"
#include "Explosion.hpp"
#include "Zombie.hpp"
#include<algorithm>
GameWorld::GameWorld(){};
GameWorld::~GameWorld() {}
void GameWorld::Init() {
  SetSun(50);
  //SetSun(5000);
  SetWave(0);
  Object_list.push_back(std::make_shared<Background>(shared_from_this()));
  Object_list.push_back(std::make_shared<Shovel>());
  Object_list.push_back(std::make_shared<SunflowerSeed>());
  Object_list.push_back(std::make_shared<PeashooterSeed>());
  Object_list.push_back(std::make_shared<WallnutSeed>());
  Object_list.push_back(std::make_shared<CherryBombSeed>());
  Object_list.push_back(std::make_shared<RepeaterSeed>());


  for (int i = 0; i < GAME_ROWS; i++)
    for (int j = 0; j < GAME_COLS; j++)
      Object_list.push_back(std::make_shared<PlantingSpot>(j,i));
  tick = 0;
}
LevelStatus GameWorld::Update() {
  if (tick % 300 == 180) Object_list.push_back(std::make_shared<Sun>(randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1, natural));
  if (tick == 1200 || (GetWave() > 0 && tick - wave_tick == std::max(150, 600 - 20 * GetWave()))){
    wave_tick = tick;
    SetWave(GetWave() + 1);
    int num = (15 + GetWave()) / 10;
    for (int j = 0; j < num; j++) {
      int p1 = 20,p2=2*std::max(GetWave()-8,0),p3=std::max(GetWave()-15,0);
      int q = randInt(1, p1 + p2 + p3);
      if (q <= p1) Object_list.push_back(std::make_shared<Regular>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + randInt(0, GAME_ROWS - 1) * LAWN_GRID_HEIGHT));
      else if (q <= p2) Object_list.push_back(std::make_shared<BucketHead>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + randInt(0, GAME_ROWS - 1) * LAWN_GRID_HEIGHT));
      else Object_list.push_back(std::make_shared<PoleVaulting>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + randInt(0, GAME_ROWS - 1) * LAWN_GRID_HEIGHT));
    }
  }
  for (auto i = Object_list.begin(); i != Object_list.end(); i++)
    (*i)->Update();
  CheckCrash();
  std::list<std::list<std::shared_ptr<GameObject>>::iterator> u;
  for (auto i = Object_list.begin(); i != Object_list.end(); i++)
    if ((*i)->Dying()) u.push_back(i);
  for (auto i = u.begin(); i != u.end(); i++)
    Object_list.erase(*i);
  for (auto i = Object_list.begin(); i != Object_list.end(); i++)
    if ((*i)->type() == tp::zombie && (*i)->GetX() < 0) return LevelStatus::LOSING;
  ++tick;
  return LevelStatus::ONGOING;
}
void GameWorld::CleanUp() {
  Object_list.clear();
}
void GameWorld::CheckCrash() {
  for (auto i = Object_list.begin(); i != Object_list.end(); i++) {
    if ((*i)->type() == tp::pea) {
      for (auto j = Object_list.begin(); j != Object_list.end(); j++)
        if ((*j)->type() == tp::zombie && IsCrash(*i, *j)) {
          (*j)->SetHP((*j)->GetHP() - 20);
          (*i)->Die();
          break;
        }
    }
    if ((*i)->type() == tp::zombie) {
      for (auto j = Object_list.begin(); j != Object_list.end(); j++)
        if ((*j)->type() == tp::explosion && IsCrash(*i, *j)) {
          (*i)->Die();
          break;
        }
    }
  }
}
void GameWorld::PlantSeed(int x,int y) {//{sunflower,peashooter,wallnut,cherry,repeater,shovel,none};
  if (hand != hand_type::none && hand!=hand_type::shovel) {
    if (hand == hand_type::sunflower) Object_list.push_back(std::make_shared<Sunflower>(x, y));
    if (hand == hand_type::peashooter) Object_list.push_back(std::make_shared<Peashooter>(x, y));
    if (hand == hand_type::wallnut) Object_list.push_back(std::make_shared<Wallnut>(x, y));
    if (hand == hand_type::cherry) Object_list.push_back(std::make_shared<CherryBomb>(x, y));
    if (hand == hand_type::repeater) Object_list.push_back(std::make_shared<Repeater>(x, y));
    hand = hand_type::none;
  }
}
int GameWorld::GetTick() { return tick; }
void GameWorld::Sethand(hand_type type) {hand = type;}
hand_type GameWorld::Gethand() { return hand; }
void GameWorld::GenerateSun(int x, int y) {Object_list.push_back(std::make_shared<Sun>(x, y, flower));}
void GameWorld::GeneratePea(int x, int y) {Object_list.push_back(std::make_shared<Pea>(x, y));}
void GameWorld::GenerateExplosion(int x, int y) {Object_list.push_back(std::make_shared<Explosion>(x, y));}
void GameWorld::SetMask(int x, int y,int cd) { Object_list.push_back(std::make_shared<CooldownMask>(x, y, cd));}
bool GameWorld::HaveZomie(int y) {
  for (auto i = Object_list.begin(); i != Object_list.end(); i++)
    if ((*i)->type() == tp::zombie && (*i)->GetY() == y) return 1;
  return 0;
}
std::shared_ptr <GameObject> GameWorld::Crash(std::shared_ptr<GameObject> zombie) {
  for (auto j = Object_list.begin(); j != Object_list.end(); j++)
    if ((*j)->type() == tp::plant && IsCrash(zombie, *j)) {
      return *j;
    }
  return nullptr;
}
bool GameWorld::IsCrash(std::shared_ptr<GameObject> a, std::shared_ptr<GameObject> b) {
  return abs(a->GetX() - b->GetX()) < (a->GetWidth() + b->GetWidth()) / 2 && abs(a->GetY() - b->GetY()) < (a->GetHeight() + b->GetHeight()) / 2;
}
int GameWorld::abs(int x) { return x >= 0 ? x : -x; }
//int GetX() const;
//int GetY() const;
//int GetWidth() const;
//int GetHeight() const;