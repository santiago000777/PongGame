#pragma once
#include "Box.h"
#include "Wall.h"

class TPaddle {
public:
    TVector2 pos, vec;
    int iWidth;
    std::vector<TBox> vBoxes;
    int color;
public:
    TPaddle();
    TPaddle(TVector2 pos, int width, char znak, int color = 15);

    void Frame();

    void ReadingWallInfo(std::vector<TWall>& wls);

private:
    char cZnak;
    enum class eControls : int {
        LEFT = VK_LEFT,
        STAY = 0,
        RIGHT = VK_RIGHT
    } controls;

    struct TWallsInfo {
        TVector2 topLeftC, topRightC;
    } wallsInfo;

private:
    void GetKey();
    void DirectionLogic();
    void Print();
    void Smaz();
    void Posun();

};

