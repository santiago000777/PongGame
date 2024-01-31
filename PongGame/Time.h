#pragma once
//#include "Vector2.h"
#include <chrono>
class TTime
{
public:
	TTime();
	void Frame();
	~TTime();
private:

	std::chrono::high_resolution_clock::time_point start, end;
	std::chrono::duration<double> duration;
};

