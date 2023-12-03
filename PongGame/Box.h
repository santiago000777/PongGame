#pragma once
#include "Vector2.h"



class TBox {
public:
	TVector2 pos;
	char znak;
public:
	TBox(TVector2 pos, char znak);
	TBox(const TBox& box);
	TBox(TBox& box);
	void Print();
	void Smaz();
private:

private:

};

