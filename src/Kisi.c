#include "Kisi.h"

Kisi KisiOlustur(char isim[50], double para, float yatirdigiParaOrani, int yatirdigiSayi)
{
    Kisi this;
    this = (Kisi)malloc(sizeof(struct KISI));
    strcpy(this->isim, isim);
    this->para = para;
    this->yatirdigiParaOrani = yatirdigiParaOrani;
    this->yatirdigiSayi = yatirdigiSayi;
    this->onceki = NULL;
    this->sonraki = NULL;

    this->ParaKazan = &ParaKazan;
    this->ParaKaybet = &ParaKaybet;
    this->KisiYokEt = &KisiYokEt;
    return this;
};
void ParaKazan(const Kisi this)
{
    this->para += (this->para * this->yatirdigiParaOrani * 9);
};
void ParaKaybet(const Kisi this)
{
    this->para -= (this->para * this->yatirdigiParaOrani);
};
void KisiYokEt(Kisi this)
{
    if (this == NULL)
        return;
    free(this);
};