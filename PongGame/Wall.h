#pragma once
#include "Box.h"

class TWall
{
public:
	std::vector<TBox> boxes;
	TVector2 size;
public:
	TWall();
	TWall(TVector2 pos, TVector2 size, char znak, bool destroyable);

	void Print();
	void Smaz();
private:
	TVector2 pos;
private:

};

