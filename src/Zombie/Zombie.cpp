#include "Zombie.hpp"
#include "GameWorld.hpp"
#include "Plant.hpp"
void Zombie::Update() {
	std::shared_ptr<GameObject> plant =GetWorld()->Crash(shared_from_this());
	if (plant != nullptr) {
		plant->SetHP(plant->GetHP() - 3);
		if(!Iseating()) Eat();
	}
	else {
		if(Iseating()) Walk();
		if (!Iseating())	MoveTo(GetX() - 1, GetY());
	}
	if (GetHP() <= 0) Die();
}
bool Zombie::Iseating() { return eat; }
void Zombie::Walk() { PlayAnimation(ANIMID_WALK_ANIM); eat = 0; }
void Zombie::Eat() { PlayAnimation(ANIMID_EAT_ANIM); eat = 1; }
void BucketHead::Update() {
	Zombie::Update();
	if(GetHP()<=200) ChangeImage(IMGID_REGULAR_ZOMBIE);
}
void PoleVaulting::Update() {
	if (jump > 0) {
		jump--;
		if (jump == 0) {
			MoveTo(GetX() - 150, GetY());
			PlayAnimation(ANIMID_WALK_ANIM);
		}
	}
	else {
		if (run) {
			MoveTo(GetX() - 40, GetY());
			if (GetWorld()->Crash(shared_from_this()) != nullptr) {
				jump = 42;
				run = 0;
				PlayAnimation(ANIMID_JUMP_ANIM);
			}
			MoveTo(GetX() + 40, GetY());
			MoveTo(GetX() - 2, GetY());
		}
		else Zombie::Update();
	}
	if (GetHP() <= 0) Die();
}