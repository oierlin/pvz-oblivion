#include "PlantingSpot.hpp"
#include "GameWorld.hpp" 
PlantingSpot::PlantingSpot(int x,int y) :
	GameObject(IMGID_NONE, FIRST_COL_CENTER+x*LAWN_GRID_WIDTH, FIRST_ROW_CENTER+y*LAWN_GRID_HEIGHT, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION) {};
void PlantingSpot::OnClick(){
	GetWorld()->PlantSeed(GetX(),GetY());
}