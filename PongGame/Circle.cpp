#include "Circle.h"

void CharC(int i)                                       // CharC(10);
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void xy(const TVector2& pos) {
	COORD c;
	c.X = pos.x;
	c.Y = pos.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void TCircle::NacteniPrekazek(TPaddle& paddle, std::vector<TWall>& walls) {
	for (int k = 0; k < walls.size(); k++) {
		for (int i = 0; i < walls.at(k).boxes.size(); i++) {
			prekazky.push_back(&(walls.at(k).boxes.at(i)));
		}
	}
	for (int i = 0; i < paddle.vBoxes.size(); i++) {
		prekazky.push_back(&(paddle.vBoxes.at(i)));
	}
}

TCircle::TCircle(const TVector2 pos, const TVector2 vec, float r, char znak, int color, bool isDestroyable) {
	this->pos = pos;
	this-> vec = vec;
	this->radius = r;
	this->znak = znak;
	this->color = color;
	this->isDestroyable = isDestroyable;
}

void TCircle::Print() {
	for (int i = 0; i < positions.size(); i++) {
		positions.at(i).Print();
	}
}

void TCircle::Smaz() {
	for (int i = 0; i < positions.size(); i++) {
		for (int i = 0; i < positions.size(); i++) {
			positions.at(i).Smaz();
		}
	}
}

void TCircle::Frame() {
	Smaz();
	//NastaveniKontrolnichBodu();
	NastaveniVektoru();
	Posun();
	Decalculate();
	Print();
}
/*Smaz();
	NastaveniKontrolnichBodu();
	Posun();
	Decalculate();
	Calculate();
	Print();*/

void TCircle::Calculate() {

	TVector2 pos;
	for (int i = -1 * radius; i <= radius; i++) {

		pos = { roundf(this->pos.x + i), roundf(sqrtf(
			powf(radius, 2.0f) - powf(((this->pos.x + i) - this->pos.x), 2.0f)) + this->pos.y) };

		positions.push_back({ pos, znak, isDestroyable, color });

		pos = { roundf(this->pos.x + i), roundf(-1 * sqrtf(
			powf(radius, 2.0f) - powf(((this->pos.x + i) - this->pos.x), 2.0f)) + this->pos.y) };

		positions.push_back({ pos, znak, isDestroyable, color });

	}

	for (int i = -1 * radius; i <= radius; i++) {
		pos = { roundf(sqrtf(
			powf(radius, 2.0f) - powf(((this->pos.y + i) - this->pos.y), 2.0f)) + this->pos.x),
			roundf(this->pos.y + i) };

		positions.push_back({ pos, znak, isDestroyable, color });

		pos = { roundf(-1 * sqrtf(
			powf(radius, 2.0f) - powf(((this->pos.y + i) - this->pos.y), 2.0f)) + this->pos.x),
			roundf(this->pos.y + i) };

		positions.push_back({ pos, znak, isDestroyable, color });
	}

	for (int k = 0; k < positions.size(); k++) {
		for (int i = k + 1; i < positions.size(); i++) {
			if (positions.at(i).pos == positions.at(k).pos) {
				positions.erase(positions.begin() + i);
				i--;
			}
		}
	}
}



void TCircle::Decalculate() {
	//positions.clear();
	/*for (int i = 0; i < kontrolniBody.size(); i++) {
		xy({ roundf(kontrolniBody.at(i).x), roundf(kontrolniBody.at(i).y) });
		std::cout << ' ';
	}*/
	//kontrolniBody.clear();
}

void TCircle::NastaveniKontrolnichBodu() {

	int r = radius + 1;
	TVector2 pos;
	for (int i = -1 * r; i <= r; i++) {

		pos = { this->pos.x + i, sqrtf(
			powf(r, 2.0f) - powf(((this->pos.x + i) - this->pos.x), 2.0f)) + this->pos.y };

		kontrolniBody.push_back({pos});

		pos = { this->pos.x + i, -1 * sqrtf(
			powf(r, 2.0f) - powf(((this->pos.x + i) - this->pos.x), 2.0f)) + this->pos.y };

		kontrolniBody.push_back({ pos });

	}

	for (int i = -1 * r; i <= r; i++) {
		pos = { sqrtf(
			powf(r, 2.0f) - powf(((this->pos.y + i) - this->pos.y), 2.0f)) + this->pos.x,
			this->pos.y + i };

		kontrolniBody.push_back({ pos });

		pos = { -1 * sqrtf(
			powf(r, 2.0f) - powf(((this->pos.y + i) - this->pos.y), 2.0f)) + this->pos.x,
			this->pos.y + i };

		kontrolniBody.push_back({ pos });
	}
	/*for (int i = -1 * r; i <= r; i++) {

		pos = { roundf(this->pos.x + i), roundf(sqrtf(
			powf(r, 2.0f) - powf(((this->pos.x + i) - this->pos.x), 2.0f)) + this->pos.y) };

		kontrolniBody.push_back({pos});

		pos = { roundf(this->pos.x + i), roundf(-1 * sqrtf(
			powf(r, 2.0f) - powf(((this->pos.x + i) - this->pos.x), 2.0f)) + this->pos.y) };

		kontrolniBody.push_back({ pos });

	}

	for (int i = -1 * r; i <= r; i++) {
		pos = { roundf(sqrtf(
			powf(r, 2.0f) - powf(((this->pos.y + i) - this->pos.y), 2.0f)) + this->pos.x),
			roundf(this->pos.y + i) };

		kontrolniBody.push_back({ pos });

		pos = { roundf(-1 * sqrtf(
			powf(r, 2.0f) - powf(((this->pos.y + i) - this->pos.y), 2.0f)) + this->pos.x),
			roundf(this->pos.y + i) };

		kontrolniBody.push_back({ pos });
	}*/

	for (int k = 0; k < kontrolniBody.size(); k++) {
		for (int i = k + 1; i < kontrolniBody.size(); i++) {
			if (kontrolniBody.at(i) == kontrolniBody.at(k)) {
				kontrolniBody.erase(kontrolniBody.begin() + i);
				i--;
			}
		}
	}



	/*for (int i = 0; i < positions.size(); i++) {
		float pom = sqrtf(powf(fabsf(this->pos.x - (positions.at(i).pos.x + vec.x)), 2.0f) + powf(fabsf(this->pos.y - (positions.at(i).pos.y + vec.y)), 2.0f));
		if (pom >= this->radius) {
			kontrolniBody.push_back({positions.at(i).pos.x + vec.x, positions.at(i).pos.y + vec.y});
		}
	}*/
	/*for (int i = 0; i < kontrolniBody.size(); i++) {
		xy({roundf(kontrolniBody.at(i).x), roundf(kontrolniBody.at(i).y) });
		std::cout << '5';
	}*/
			// na roh !!!
}

void TCircle::Posun() {
	

	/*for (int k = 0; k < prekazky.size(); k++) {
		for (int i = 0; i < kontrolniBody[eKontrolniBody::XSIDE].size(); i++) {
			if (prekazky.at(k)->pos == kontrolniBody[eKontrolniBody::XSIDE].at(i)) {
				vec.x *= -1;
			}
		}

		for (int i = 0; i < kontrolniBody[eKontrolniBody::YSIDE].size(); i++) {
			if (prekazky.at(k)->pos == kontrolniBody[eKontrolniBody::YSIDE].at(i)) {
				vec.y *= -1;
			}
		}
	}*/


	pos += vec;
	for (int i = 0; i < positions.size(); i++) {
		positions.at(i).pos += vec;

	}
	for (int i = 0; i < kontrolniBody.size(); i++) {

		kontrolniBody.at(i) += vec;
	}
}

void TCircle::NastaveniVektoru() {
	//int count = 0;
	float rad;
	for (int k = 0; k < prekazky.size(); k++) {

		for (int i = 0; i < kontrolniBody.size(); i++) {

			if (roundf(prekazky.at(k)->pos.x) == roundf(kontrolniBody.at(i).x)
				&& roundf(prekazky.at(k)->pos.y) == roundf(kontrolniBody.at(i).y)) {

				/*if (count == 0) {*/

					rad = atanf(fabsf(this->pos.y - kontrolniBody.at(i).y) / fabsf(this->pos.x - kontrolniBody.at(i).x));


					if (rad > (45.0f * PI) / 180) {

						this->vec.y *= -1;
					}

					if (rad < (45.0f * PI) / 180) {

						this->vec.x *= -1;
					}
					if (rad == (45.0f * PI) / 180) {
						this->vec.x *= -1;
						this->vec.y *= -1;
					}
					//count++;
					
				//}
				
			}
		}
	}
	/*for (int k = 0; k < prekazky.size(); k++) {

		for (int i = 0; i < kontrolniBody.size(); i++) {

			if (roundf(prekazky.at(k)->pos.x) == roundf(kontrolniBody.at(i).x)
				&& roundf(prekazky.at(k)->pos.y) == roundf(kontrolniBody.at(i).y)) {

				if (count == 0) {

					if (atanf(fabsf(this->pos.y - (kontrolniBody.at(i).y - this->vec.y))
						/ fabsf(this->pos.x - (kontrolniBody.at(i).x - this->vec.x))) > (45.0f * PI) / 180) {

						this->vec.y *= -1;
					}

					if (atanf(fabsf(this->pos.y - (kontrolniBody.at(i).y - this->vec.y))
						/ fabsf(this->pos.x - (kontrolniBody.at(i).x - this->vec.x))) < (45.0f * PI) / 180) {

						this->vec.x *= -1;
					}
					count++;
				}
		}
	}*/
}
