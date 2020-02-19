#include "Fire.h"
#include "rlutil.h"
#include <math.h>
#include <iostream>

using namespace std;
using namespace rlutil;

Fire::Fire(float x, float y, bool bizimMi, float c) {
	this->x = x;
	this->y = y;
	this->bizimMi = bizimMi;
	this->c = c;
}

Fire::Fire() {
}

void Fire::Ilerlet() {
	if (bizimMi) {
		--y;
	}
	else {
		++y;
	}
}

bool Fire::BizimMi() {
	return bizimMi;
}

float Fire::X() {
	return x;
}

float Fire::Y() {
	return y;
}

void Fire::Ciz() {
	locate(x, y);
	setColor(c);
	cout<<("@");
	fflush(stdout);
}

void Fire::Sil() {
	locate(x, y);
	cout<<(" ");
	fflush(stdout);
}

bool Fire::AktifMi() {
	if (y < 5 || y >  28) {
		return false;
	}
	else {
		return true;
	}
}

