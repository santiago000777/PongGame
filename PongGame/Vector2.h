#pragma once
#include "common.h"
class TVector2 {
public:
	float x, y;

public:
	TVector2();
	TVector2(float x, float y);

	TVector2& operator+(TVector2& pos);
	TVector2& operator-(TVector2& pos);
	void operator+=(TVector2& pos);
	void operator-=(TVector2& pos);
	bool operator==(TVector2& pos);
};

