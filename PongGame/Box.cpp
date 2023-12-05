#include "Box.h"
//#include "common.h"

void xy(TVector2 pos) {
	COORD c;
	c.X = pos.x;
	c.Y = pos.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

TBox::TBox(TVector2 pos, char znak) {
	this->pos = pos;
	this->znak = znak;
}

TBox::TBox(const TBox& box) {
	this->pos = box.pos;
	this->znak = box.znak;
}
TBox::TBox(TBox& box) {
	this->pos = box.pos;
	this->znak = box.znak;
}

void TBox::Print() {
	xy({round(pos.x), round(pos.y)});
	std::cout << znak;
}

void TBox::Smaz() {
	xy({ round(pos.x), round(pos.y) });
	std::cout << ' ';
}
