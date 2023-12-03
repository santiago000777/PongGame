#pragma once
#include "Box.h"
#include "Wall.h"
#include "Paddle.h"


class TBall :
    public TBox
{
public:
    TVector2 vec;
public:
    void NacteniPrekazek(TPaddle& paddle, std::vector<TWall>& walls);
    void Frame();
private:
    enum eKontrolniBody : int {
        XSIDE = 0,
        YSIDE,
        CORNERSIDE
    };

    TVector2 kontrolniBody[3];

    /*struct TPadlleInfo {
        TVector2 pos;
        int width;
    } paddleInfo;

    struct TWallInfo {
        TVector2 pos, size;
    };
    std::vector<TWallInfo> wallsInfo;*/
    std::vector<TBox&> prekazky;

private:
    void NastaveniKontrolnichBodu();
    void Posun();
};
