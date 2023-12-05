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
    TBall(TVector2 pos, TVector2 vec, char znak);
    void NacteniPrekazek(TPaddle& paddle, std::vector<TWall>& walls);
    void Frame();
private:
    enum eKontrolniBody : int {
        XSIDE = 0,
        YSIDE,
        CORNERSIDE
    };

    TVector2 kontrolniBody[3];

    
    std::vector<TBox*> prekazky;

private:
    void NastaveniKontrolnichBodu();
    void Posun();
};

