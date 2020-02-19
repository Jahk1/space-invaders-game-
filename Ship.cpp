#include "Ship.h"
#include "rlutil.h"
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;
using namespace rlutil;

Ship::Ship(float x, float y) {
	this->x = x;
	this->y = y;
}

Ship::Ship() {
}

bool Ship::CarparMi(float ax, float ay) {
 	return (ax==x) && (ay==y);
}

void Ship::SolaGit() {
	--x;
	if (x < 10) {x = 10;}
}

void Ship::SagaGit() {
	++x;
	if (x > 45) {x = 45;}
}

float Ship::X() {
	return x;
}

float Ship::Y() {
	return y;
}

void Ship::Ciz() {
	locate(x, y);
	setColor(7);
	cout<<("+");
	fflush(stdout);
}

void Ship::Sil() {
	locate(x, y);
	cout<<(" ");
	fflush(stdout);
}

