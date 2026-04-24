#pragma once
#include <string>
class Enemy {
public:
	std::string name;
	int wrist;
	int backpress;
	int sidepress;
	Enemy(std::string , int w, int b, int s);
};