#include "Shovel.hpp"
#include "GameWorld.hpp"
Shovel::Shovel() :
	GameObject(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION){};
void Shovel::OnClick() {
	if(GetWorld()->Gethand()==hand_type::none) GetWorld()->Sethand(hand_type::shovel);
	else if(GetWorld()->Gethand()==hand_type::shovel) GetWorld()->Sethand(hand_type::none);
}