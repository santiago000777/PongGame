#pragma once
#include "Wall.h"
#include "Paddle.h"
#include "Box.h"


class TCircle
{
public:
	TVector2 pos;
	TVector2 vec;
	float radius;
	int color;
	char znak;
	bool isDestroyable;

	/*enum eKontrolniBody : int {
		XSIDE = 0,
		YSIDE,
		CORNERSIDE
	};*/


public:

	void NacteniPrekazek(TPaddle& paddle, std::vector<TWall>& walls);

	TCircle(const TVector2 pos, const TVector2 vec, float r, char znak, int color = 15, bool isDestroyable = false);

	void Print();
	void Smaz();
	void Frame();
	void Calculate();
	void NastaveniKontrolnichBodu();


private:
	std::vector<TBox> positions;
	std::vector<TVector2> kontrolniBody;
	std::vector<TBox*> prekazky;

private:
	void Decalculate();
	void Posun();
	void NastaveniVektoru();
};

