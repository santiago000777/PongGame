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
	NastaveniKontrolnichBodu();
	Posun();
	Decalculate();
	Calculate();
	Print();
	
}


void TCircle::Calculate() {
	TVector2 pos;
	for (int i = -1 * radius; i <= radius; i++) {

		pos = { roundf(this->pos.x + i), roundf(sqrtf(
			powf(radius, 2.0f) - powf(((this->pos.x + i) - this->pos.x), 2.0f)) + this->pos.y) };

		positions.push_back({pos, znak, isDestroyable, color});

		pos = { roundf(this->pos.x + i), roundf(-1 * sqrtf(
			powf(radius, 2.0f) - powf(((this->pos.x + i) - this->pos.x), 2.0f)) + this->pos.y) };

		positions.push_back({ pos, znak, isDestroyable, color });

	}
	for (int i = -1 * radius; i <= radius; i++) {
		pos = {roundf(sqrtf(
			powf(radius, 2.0f) - powf(((this->pos.y + i) - this->pos.y), 2.0f)) + this->pos.x),
			roundf(this->pos.y + i)};

		positions.push_back({pos, znak, isDestroyable, color });

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
	positions.clear();
}

void TCircle::NastaveniKontrolnichBodu() {
	for (int i = 0; i < positions.size(); i++) {
		if (vec.x > 0 && fabsf(positions.at(i).pos.x - this->pos.x) == radius) {
			kontrolniBody[eKontrolniBody::XSIDE].push_back({ positions.at(i).pos.x + vec.x, positions.at(i).pos.y });
		}
		else if (vec.x < 0 && fabsf(positions.at(i).pos.x - this->pos.x) == radius)
			kontrolniBody[eKontrolniBody::XSIDE].push_back({ positions.at(i).pos.x + vec.x, positions.at(i).pos.y });
	}

	for (int i = 0; i < positions.size(); i++) {
		if (vec.y > 0 && fabsf(positions.at(i).pos.y - this->pos.y) == radius) {

			kontrolniBody[eKontrolniBody::YSIDE].push_back({ positions.at(i).pos.x, positions.at(i).pos.y + vec.y });
		}
		else if (vec.y < 0 && fabsf(positions.at(i).pos.y - this->pos.y) == radius)
			kontrolniBody[eKontrolniBody::YSIDE].push_back({ positions.at(i).pos.x, positions.at(i).pos.y + vec.y });
	}
	
			// na roh !!!
}

void TCircle::Posun() {
		// Neodrazi se (nenastavi se kontrolni body)
	for (int k = 0; k < prekazky.size(); k++) {
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
	}
	pos += vec;
}
