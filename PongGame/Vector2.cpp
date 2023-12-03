#include "Vector2.h"

TVector2::TVector2() {
	this->x = 0;
	this->y = 0;
}

TVector2::TVector2(float x, float y) {
	this->x = x;
	this->y = y;
}

TVector2& TVector2::operator+(TVector2& pos) {
	this->x += pos.x;
	this->y += pos.y;
	return *this;
}

TVector2& TVector2::operator-(TVector2& pos) {
	this->x -= pos.x;
	this->y -= pos.y;
	return *this;
}
void TVector2::operator+=(TVector2& pos) {
	this->x += pos.x;
	this->y += pos.y;
}

void TVector2::operator-=(TVector2& pos) {
	this->x -= pos.x;
	this->y -= pos.y;
}
