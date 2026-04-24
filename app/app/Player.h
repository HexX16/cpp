#pragma once
#include <string>

class Player
{
public:
	std::string name;
	int wrist;
	int backpress;
	int sidepress;
	Player(std::string, int w, int b, int s);
};

