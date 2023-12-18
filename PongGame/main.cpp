
#include "Paddle.h"
#include "Wall.h"
#include "Ball.h"


void SetCursor(bool visible) {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

int main() {
	TPaddle paddle({20, 30}, 10, '#');
	std::vector<TWall> walls;
	walls.push_back({ {4, 3}, {1, 30}, '@' });
	walls.push_back({ {5, 3}, {40, 1}, '@' });
	walls.push_back({ {44, 3}, {1, 30}, '@' });

	TBall ball({20, 20}, {0.4f, 0.2f}, 'B');	// spatne odrazeni od vodorovnych zdi

	ball.NacteniPrekazek(paddle, walls);
	ball.Print();
	for(int i = 0; i < walls.size(); i++)
		walls.at(i).Print();

	paddle.ReadingWallInfo(walls);

	SetCursor(false);
	while (true) {
		DEBUG();
		paddle.Frame();
		if (!ball.Frame()) {
			return 0;
		}
		
		Sleep(25);
	}
}