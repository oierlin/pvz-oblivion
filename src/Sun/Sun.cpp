#include "Sun.hpp"
#include "GameWorld.hpp"
Sun::Sun(int x, int y, bool t) :
	GameObject(IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM)
	, sun_type(t) {
	if (sun_type == natural) time = randInt(63,263) + 1;
	else if (sun_type == flower) time = 12 + 1;
};
void Sun::Update() {
	if (time > 1) {
		time--;
		if (sun_type == natural) MoveTo(GetX(), GetY() - 2);
		else { MoveTo(GetX() - 1, GetY() + a--); }
	}
	else if (time == 1) time = -300;
	else if (time < 0) time++;
	else if (time == 0) Die();
}
void Sun::OnClick() { GetWorld()->SetSun(GetWorld()->GetSun() + 25); Die(); }