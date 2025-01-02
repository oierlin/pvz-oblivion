#include "Card.hpp"
#include "GameWorld.hpp"
void Card::Click(hand_type seed) {
	if (GetWorld()->Gethand() == hand_type::none) {
		if (GetWorld()->GetSun() >= price) {
			GetWorld()->SetMask(GetX(), GetY(),cd);
			GetWorld()->Sethand(seed);
			GetWorld()->SetSun(GetWorld()->GetSun() - price);
		}
	}
}
void SunflowerSeed::OnClick() {Click(hand_type::sunflower);}
void PeashooterSeed::OnClick() {Click(hand_type::peashooter);}
void WallnutSeed::OnClick() {Click(hand_type::wallnut);}
void CherryBombSeed::OnClick() { Click(hand_type::cherry); }
void RepeaterSeed::OnClick() { Click(hand_type::repeater); }