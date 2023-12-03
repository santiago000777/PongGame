#include "Ball.h"

void TBall::NacteniPrekazek(TPaddle& paddle, std::vector<TWall>& walls) {
	/*paddleInfo.pos = paddle.pos;
	paddleInfo.width = paddle.iWidth;

	for (int i = 0; i < walls.size(); i++) {
		wallsInfo.at(i).pos = walls.at(i).boxes.at(0).pos;
		wallsInfo.at(i).size = walls.at(i).size;
	}*/

	for (int k = 0; k < walls.size(); k++) {
		for (int i = 0; i < walls.at(k).boxes.size(); i++) {
			prekazky.push_back(walls.at(k).boxes.at(i));
		}
	}
	for (int i = 0; i < paddle.vBoxes.size(); i++) {
		prekazky.push_back(paddle.vBoxes.at(i));
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
	for (int i = 0; i < prekazky.size(); i++) {
		if (round(kontrolniBody[XSIDE].x) == prekazky.at(i).pos.x 
			&& round(kontrolniBody[XSIDE].y) == prekazky.at(i).pos.y) {
			vec.x *= -1;
		}
		if (round(kontrolniBody[YSIDE].x) == prekazky.at(i).pos.x 
			&& round(kontrolniBody[YSIDE].y) == prekazky.at(i).pos.y) {
			vec.y *= -1;
		}
		//if (kontrolniBody[CORNERSIDE].) {			// roh

		//}
	}
	

	pos += vec;
}