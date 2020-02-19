#pragma once
#include <vector>

class Enemy {
public:
	float x, y;
	int dusmanAtesSayaci = 0;
	Enemy(float x, float y);
	bool CarparMi(float ax, float ay);
	float X();
	float Y();
	void Ciz();
	void Sil();
};

