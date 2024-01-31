#include "Time.h"
#include "common.h"
void xy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

TTime::TTime() {
	start = std::chrono::high_resolution_clock::now();
	xy(15, 1);
	std::cout << "+-------------------+";
	xy(15, 2);
	std::cout << "|                   |";
	xy(15, 3);
	std::cout << "+-------------------+";
}

void TTime::Frame() {
	xy(16, 2);
	std::cout << "                   ";
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	xy(20, 2);
	//std::cout << std::roundf(duration.count()) << ": " << modf(duration.count(), &);
}

TTime::~TTime() {

}
