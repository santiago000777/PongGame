#include "Ball.h"

TBall::TBall(TVector2 pos, TVector2 vec, char znak) {
	this->pos = pos;
	this->vec = vec;
	this->znak = znak;
	this->isDestroyable = false;
}

void TBall::NacteniPrekazek(TPaddle& paddle, std::vector<TWall>& walls) {
	
	for (int k = 0; k < walls.size(); k++) {
		for (int i = 0; i < walls.at(k).boxes.size(); i++) {
			prekazky.push_back(&(walls.at(k).boxes.at(i)));
		}
	}
	for (int i = 0; i < paddle.vBoxes.size(); i++) {
		prekazky.push_back(&(paddle.vBoxes.at(i)));
	}
}


void TBall::Frame() {
	Smaz();
	NastaveniKontrolnichBodu();
	Posun();
	Print();
}

void TBall::NastaveniKontrolnichBodu() {
	kontrolniBody[XSIDE] = { pos.x + vec.x, pos.y };
	kontrolniBody[YSIDE] = { pos.x, pos.y + vec.y };
	kontrolniBody[CORNERSIDE] = { pos.x + vec.x, pos.y + vec.y };
}

void TBall::Posun() {
	for (int i = 0; i < prekazky.size(); i++) {
		
		

		if (round(kontrolniBody[XSIDE].x) == prekazky.at(i)->pos.x 
			&& round(kontrolniBody[XSIDE].y) == prekazky.at(i)->pos.y) {
			vec.x *= -1;

			if (prekazky.at(i)->isDestroyable) {
				prekazky.at(i)->Smaz();
				prekazky.erase(prekazky.begin() + i);
			}
		}
		if (round(kontrolniBody[YSIDE].x) == prekazky.at(i)->pos.x 
			&& round(kontrolniBody[YSIDE].y) == prekazky.at(i)->pos.y) {
			vec.y *= -1;

			if (prekazky.at(i)->isDestroyable) {
				prekazky.at(i)->Smaz();
				prekazky.erase(prekazky.begin() + i);
			}
		}
		/*if (round(kontrolniBody[CORNERSIDE].x) == prekazky.at(i)->pos.x
			&& round(kontrolniBody[CORNERSIDE].y) == prekazky.at(i)->pos.y) {
			vec.x *= -1;
			vec.y *= -1;
		}*/
	}
	pos += vec;
}