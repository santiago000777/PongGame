#pragma once
#include "Box.h"
#include "Wall.h"
#include "Paddle.h"

#define GAMEOVER_LINE   30


class TBall :
    public TBox
{
public:
    TVector2 vec;
public:
    TBall(TVector2 pos, TVector2 vec, char znak);
    void NacteniPrekazek(TPaddle& paddle, std::vector<TWall>& walls);
    bool Frame();
private:
    enum eKontrolniBody : int {
        XSIDE = 0,
        YSIDE,
        CORNERSIDE
    };

    enum eSounds : int {
        SCORE = 0,
        COLLISION,
        GAMEOVER
    };

    TVector2 kontrolniBody[3];

    
    std::vector<TBox*> prekazky;

private:
    void NastaveniKontrolnichBodu();
    void Posun();
    void MakeSound(eSounds sound);
    bool IsGameOver();
};

