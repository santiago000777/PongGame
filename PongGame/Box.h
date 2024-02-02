#pragma once
#include "Vector2.h"



class TBox {
public:
	TVector2 pos;
	char znak;
	int color;
	bool isDestroyable;
public:
	TBox(TVector2 pos, char znak);
	TBox(TVector2 pos, char znak, bool isDestoyble, int color);
	TBox(const TBox& box);
	TBox(TBox& box);
	TBox() = default;
	void Print();
	void Smaz();
private:

private:

};

