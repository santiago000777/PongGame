#include "Ball.h"

void TBall::NacteniPrekazek(const TPaddle& paddle, const std::vector<TWall>& walls) {
	paddleInfo.pos = paddle.pos;
	paddleInfo.width = paddle.iWidth;

	for (int i = 0; i < walls.size(); i++) {
		wallsInfo.at(i).pos = walls.at(i).boxes.at(0).pos;
		wallsInfo.at(i).size = walls.at(i).size;
	}
}

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
	if () {	

	}
	else if () {

	}
	if () {			// roh

	}

	pos += vec;
}