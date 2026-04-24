#include "Player.h"
#include <stdexcept>

Player::Player(std::string n, int w, int b, int s) : name(n)
{
	if (w < 0 || w > 100 || b < 0 || b>100 || s < 0 || s>100)
	{
		throw std::invalid_argument("Enemy value must be 0-100");
	}

	wrist = w;
	backpress = b;
	sidepress = s;
}