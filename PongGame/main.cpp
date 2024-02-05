
//#include "Paddle.h"
//#include "Wall.h"
//#include "Ball.h"
#include "Circle.h"
#include "Time.h"

void SetCursor(bool visible) {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

int main() {		// chyba 

	TPaddle paddle({33, 33}, 10, '#');
	std::vector<TWall> walls;
	walls.push_back({ {4, 6}, {1, 30}, '@', false });
	walls.push_back({ {5, 6}, {40, 1}, '@', false });
	walls.push_back({ {44, 6}, {1, 30}, '@', false });
	walls.push_back({ {9, 10}, {31, 1}, '%', true });
	walls.push_back({ {9, 11}, {31, 1}, '%', true });

	TCircle ball({ 30, 27 }, { 0.1f, 0.2f }, 2.0f, 'B');

	ball.NacteniPrekazek(paddle, walls);
	ball.Calculate();
	ball.NastaveniKontrolnichBodu();
	ball.Print();
	for(int i = 0; i < walls.size(); i++)
		walls.at(i).Print();

	paddle.ReadingWallInfo(walls);

	SetCursor(false);
	TTime timer;
	while (true) {
		DEBUG();
		paddle.Frame();
		ball.Frame();
		
		Sleep(25);
		timer.Frame();
	}
}