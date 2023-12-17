#pragma once
#include "Vector2.h"



class TBox {
public:
	TVector2 pos;
	char znak;
	bool isDestroyable;
public:
	TBox(TVector2 pos, char znak);
	TBox(TVector2 pos, char znak, bool isDestoyble);
	TBox(const TBox& box);
	TBox(TBox& box);
	TBox() = default;
	void Print();
	void Smaz();
private:

private:

};

