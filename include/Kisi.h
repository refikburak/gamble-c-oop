#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "Windows.h"

struct KISI
{

    char isim[50];
    double para;
    float yatirdigiParaOrani;
    int yatirdigiSayi;
    struct KISI *onceki;
    struct KISI *sonraki;
    void (*ParaKazan)(struct KISI *);
    void (*ParaKaybet)(struct KISI *);
    void (*KisiYokEt)(struct KISI *);
};

typedef struct KISI *Kisi;

Kisi KisiOlustur(char[50], double, float, int);
void ParaKazan(const Kisi);
void ParaKaybet(const Kisi);
void KisiYokEt(Kisi);

#endif