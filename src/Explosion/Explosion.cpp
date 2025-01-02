#include "Explosion.hpp"
#include "GameWorld.hpp"
void Explosion::Update() {
	if (time > 0) time--;
	else Die();
}