#ifndef OYUN_H
#define OYUN_H

#include "Dosya.h"

struct OYUN
{
    double kasa;
    int tur;
    Kisi *kisiler;
    Kisi enZengin;
    int *sayilar;
    int kisiSayisi;
    int sayiSayisi;
    int oyuncuSayisi;
    void (*TurOyna)(struct OYUN *, int);
    void (*OyunOyna)(struct OYUN *);
};

typedef struct OYUN *Oyun;

Oyun OyunOlustur();
void TurOyna(const Oyun, int);
void OyunOyna(const Oyun);
#endif