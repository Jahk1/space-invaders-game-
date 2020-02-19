#pragma once
#include <iostream>

class Fire {
public:
	float x, y, c;
	bool bizimMi;
	Fire(float x, float y, bool bizimMi, float c);
	Fire();
	void Ilerlet();
	bool BizimMi();
	float X();
	float Y();
	void Ciz();
	void Sil();
	bool AktifMi();
};

