#pragma once
#include "Box.h"
class TBall :
    public TBox
{
public:
    TVector2 vec;
public:
    void Frame();
private:
    enum eKontrolniBody : int {
        XSIDE = 0,
        YSIDE,
        CORNERSIDE
    };

    TVector2 kontrolniBody[3];

private:
    void NastaveniKontrolnichBodu();
    void Posun();
};

