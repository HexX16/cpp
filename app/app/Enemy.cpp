#include "Enemy.h"
#include <stdexcept>


Enemy::Enemy(std::string n, int w, int b, int s) : name(n)
{
	wrist = w;
	backpress = b;
	sidepress = s;
}