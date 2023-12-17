#include "Paddle.h"


TPaddle::TPaddle() {

}

TPaddle::TPaddle(TVector2 pos, int width, char znak) 
	: pos(pos) {

	this->iWidth = width;
	this->cZnak = znak;
	for(int i = 0; i < width; i++)
		vBoxes.push_back({{pos.x + i, pos.y}, znak, false});
}


void TPaddle::Frame() {
	Smaz();
	GetKey();
	DirectionLogic();
	Posun();
	Print();
}

void TPaddle::ReadingWallInfo(std::vector<TWall>& wls) {
	wallsInfo.topLeftC = wls.at(0).boxes.at(0).pos;
	wallsInfo.topRightC = wls.at(2).boxes.at(0).pos;
}


	// PRIVATE

void TPaddle::GetKey() {
	if (GetAsyncKeyState(VK_LEFT)) {
		controls = eControls::LEFT;
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		controls = eControls::RIGHT;
	}
	else {
		controls = eControls::STAY;
	}
}

void TPaddle::DirectionLogic() {
	switch (controls) {
		case eControls::LEFT: {
			vec = {-1, 0};
			break;
		}
		case eControls::RIGHT: {
			vec = { 1, 0 };
			break;
		}
		case eControls::STAY: {
			vec = { 0, 0 };
			break;
		}
	}
}

void TPaddle::Print() {
	for (int i = 0; i < iWidth; i++)
		vBoxes.at(i).Print();
}

void TPaddle::Smaz() {
	for (int i = 0; i < iWidth; i++)
		vBoxes.at(i).Smaz();
}

void TPaddle::Posun() {
	if (vBoxes.at(0).pos.x + vec.x > wallsInfo.topLeftC.x && vBoxes.at(vBoxes.size()-1).pos.x + vec.x < wallsInfo.topRightC.x) {
		
		pos += vec;
		for (int i = 0; i < vBoxes.size(); i++)
			vBoxes.at(i).pos += vec;
	}
}
