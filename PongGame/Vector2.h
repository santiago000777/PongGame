#pragma once
#include "common.h"
class TVector2 {
public:
	float x, y;

public:
	TVector2();
	TVector2(float x, float y);

	TVector2 operator+(const TVector2& pos) const;
	TVector2 operator-(const TVector2& pos) const;
	void operator+=(const TVector2& pos);
	void operator-=(const TVector2& pos);
	bool operator==(const TVector2& pos) const;
};

