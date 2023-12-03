#include "Ball.h"

void TBall::Frame() {
	Print();
	NastaveniKontrolnichBodu();
	Posun();
}

void TBall::NastaveniKontrolnichBodu() {
	kontrolniBody[XSIDE] = { pos.x + vec.x, pos.y };
	kontrolniBody[YSIDE] = { pos.x, pos.y + vec.y };
	kontrolniBody[CORNERSIDE] = { pos.x + vec.x, pos.y + vec.y };
}

void TBall::Posun() {

}