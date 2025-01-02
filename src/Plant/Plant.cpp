#include "Plant.hpp"
#include "GameWorld.hpp"
void Plant::OnClick() {
	if (GetWorld()->Gethand() == hand_type::shovel) {
		Die();
		GetWorld()->Sethand(hand_type::none);
	}
}
void Sunflower::Update() {
	if (GetHP() <= 0) Die();
	if (cd > 0) cd--;
	else{
		GetWorld()->GenerateSun(GetX(), GetY());
		cd = 600;
	}
}
void Peashooter::Update() {
	if (GetHP() <= 0) Die();
	if (cd > 0) cd--;
	else if (GetWorld()->HaveZomie(GetY()) && cd == 0){
		GetWorld()->GeneratePea(GetX() + 30, GetY() + 20);
		cd = 30;
	}
}
void Wallnut::Update() {
	if (GetHP() <= 0) Die();
	if (GetHP() < 4000 / 3) ChangeImage(IMGID_WALLNUT_CRACKED);
}
void CherryBomb::Update() {
	if (GetHP() <= 0) Die();
	if (time > 0) time--;
	else {
		Die();
		GetWorld()->GenerateExplosion(GetX(),GetY());
	}
}
void Repeater::Update() {
	if (GetHP() <= 0) Die();
	if (cd > 0) cd--;
	else if (GetWorld()->HaveZomie(GetY()) && cd == 0) {
		GetWorld()->GeneratePea(GetX() + 30, GetY() + 20);
		cd = 30; scd = 5;
	}
	if (scd > 0) scd--;
	else if (scd == 0) {
		GetWorld()->GeneratePea(GetX() + 30, GetY() + 20);
		scd = -1;
	}
}