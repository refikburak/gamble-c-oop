#ifndef BAGLILISTE_H
#define BAGLILISTE_H

#include "Kisi.h"

struct BAGLILISTE
{
    Kisi ilk;
    int kisiSayisi;
    void (*Ekle)(struct BAGLILISTE *, struct KISI *);
    void (*YokEt)(struct BAGLILISTE *);
};
typedef struct BAGLILISTE *BagliListe;

BagliListe BagliListeOlustur();
void Ekle(const BagliListe, const Kisi);
void YokEt(BagliListe);

#endif