#include "Pea.hpp"
#include "GameWorld.hpp"
void Pea::Update() {
	MoveTo(GetX() + 8, GetY());
	if (GetX() >= WINDOW_WIDTH) Die();
}