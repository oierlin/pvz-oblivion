#include "CooldownMask.hpp"
#include "GameWorld.hpp"
void CooldownMask::Update() {
	cd--;
	if (cd == 0) Die();
}