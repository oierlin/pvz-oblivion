#include "Background.hpp"
Background::Background(std::shared_ptr<GameWorld> World_ptr) :
	GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION){
	SetWorld(World_ptr);
};