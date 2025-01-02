#include "GameObject.hpp"
void GameObject::SetWorld(std::shared_ptr<GameWorld> World) {
	World_ptr = World;
}
std::shared_ptr<GameWorld> GameObject::GetWorld() {
	return World_ptr;
}
std::shared_ptr<GameWorld> GameObject::World_ptr = nullptr;
void GameObject::Die() {deth = true;}
bool GameObject::Dying() { return deth; }
int GameObject::GetHP() { return hp; }
void GameObject::SetHP(int x) { hp = x; }