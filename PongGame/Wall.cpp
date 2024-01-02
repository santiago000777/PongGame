#include "Wall.h"

TWall::TWall() {

}

TWall::TWall(TVector2 pos, TVector2 size, char znak, bool destroyable) {
	this->pos = pos;
	this->size = size;
	for (int y = 0; y < size.y; y++) {
		for (int x = 0; x < size.x; x++) {
			boxes.push_back({ { pos.x + x, pos.y + y }, znak, destroyable });
		}
	}
}

void TWall::Print() {
	for (int i = 0; i < boxes.size(); i++) {
		boxes.at(i).Print();
	}
}

void TWall::Smaz() {
	for (int i = 0; i < boxes.size(); i++) {
		boxes.at(i).Smaz();
	}
}
