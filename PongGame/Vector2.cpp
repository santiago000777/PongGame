#include "Vector2.h"

TVector2::TVector2() {
	this->x = 0;
	this->y = 0;
}

TVector2::TVector2(float x, float y) {
	this->x = x;
	this->y = y;
}

TVector2 TVector2::operator+(const TVector2& pos) const {
	return { this->x + pos.x, this->y + pos.y };
}

TVector2 TVector2::operator-(const TVector2& pos) const {
	return { this->x - pos.x, this->y - pos.y };
}
void TVector2::operator+=(const TVector2& pos) {
	this->x += pos.x;
	this->y += pos.y;
}

void TVector2::operator-=(const TVector2& pos) {
	this->x -= pos.x;
	this->y -= pos.y;
}

bool TVector2::operator==(const TVector2& pos) const {
	if (roundf(this->x) == roundf(pos.x)
		&& roundf(this->y) == roundf(pos.y))
		return true;
	else
		return false;
}
