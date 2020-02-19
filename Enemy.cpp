#include "Enemy.h"
#include "rlutil.h"
#include <math.h>
#include <iostream>

using namespace std;
using namespace rlutil;

Enemy::Enemy(float x, float y) {
	this->x = x;
	this->y = y;
}

bool Enemy::CarparMi(float ax, float ay) {
	return (ax==x) && (ay==y);
}

float Enemy::X() {
	return x;
}

float Enemy::Y() {
	return y;
}

void Enemy::Ciz() {
	locate(x, y);
	setColor(2);
	cout<<("X");
	fflush(stdout);
}

void Enemy::Sil() {
	locate(x, y);
	cout<<(" ");
	fflush(stdout);
}

