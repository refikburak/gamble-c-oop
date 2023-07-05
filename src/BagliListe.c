#include "BagliListe.h"

BagliListe BagliListeOlustur()
{
    BagliListe this;
    this = (BagliListe)malloc(sizeof(struct BAGLILISTE));
    this->ilk = NULL;
    this->kisiSayisi = 0;
    this->Ekle = &Ekle;
    this->YokEt = &YokEt;
    return this;
};
void Ekle(const BagliListe this, const Kisi yeni)
{
    Kisi gecici = this->ilk;
    if (this->ilk == 0)
    {
        this->ilk = yeni;
        this->kisiSayisi++;
    }
    else
    {
        while (gecici->sonraki != 0)
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
        yeni->onceki = gecici;
        this->kisiSayisi++;
    }
};
void YokEt(const BagliListe this)
{
    if (this == NULL)
        return;
    free(this);
};
