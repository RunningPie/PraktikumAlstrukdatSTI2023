#include <stdio.h>
#include <math.h>
#include "garis.h"

void MakeGARIS (POINT P1, POINT P2, GARIS * L)
{
    PAwal(*L) = P1; PAkhir(*L) = P2;
}

void BacaGARIS (GARIS * L)
{
    float x1, y1; scanf("%f %f", &x1, &y1);
    float x2, y2; scanf("%f %f", &x2, &y2);
    POINT P1 = MakePOINT(x1, y1), P2 = MakePOINT(x2, y2);
    while(EQ(P1, P2)) 
    {
        printf("Garis tidak valid\n");
        scanf("%f %f", &x1, &y1);
        scanf("%f %f", &x2, &y2);
        P1 = MakePOINT(x1, y1);
        P2 = MakePOINT(x2, y2);
    }
    MakeGARIS(P1, P2, L);
}

void TulisGARIS (GARIS L)
{
    float x1 = Absis(PAwal(L));
    float y1 = Ordinat(PAwal(L));
    float x2 = Absis(PAkhir(L));
    float y2 = Ordinat(PAkhir(L));
    printf("((%.2f,%.2f),(%.2f,%.2f))", x1, y1, x2, y2);
}

float PanjangGARIS (GARIS L)
{
    float x1 = Absis(PAwal(L));
    float y1 = Ordinat(PAwal(L));
    float x2 = Absis(PAkhir(L));
    float y2 = Ordinat(PAkhir(L));
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

float Gradien (GARIS L)
{
    float x1 = Absis(PAwal(L));
    float y1 = Ordinat(PAwal(L));
    float x2 = Absis(PAkhir(L));
    float y2 = Ordinat(PAkhir(L));
    return (y2-y1)/(x2-x1);
}

boolean IsTegakLurus (GARIS L1, GARIS L2)
{
    return (Gradien(L1)*Gradien(L2) == -1);
}

boolean IsSejajar (GARIS L1, GARIS L2)
{
    return (Gradien(L1) == Gradien(L2));
}
