#include "Oyun.h"

Oyun OyunOlustur()
{
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->kasa = 0;
    this->tur = 0;
    Dosya dosya = DosyaOlustur();
    // this->kisiler = dosya->KisiOku(dosya);
    this->sayilar = dosya->SayiOku(dosya);
    this->enZengin = (Kisi)malloc(sizeof(struct KISI));
    this->enZengin = this->kisiler[0];
    this->kisiSayisi = dosya->KisiSayisiBul(dosya);
    this->oyuncuSayisi = this->kisiSayisi;
    this->sayiSayisi = dosya->SayiSayisiBul(dosya);
    this->TurOyna = &TurOyna;
    this->OyunOyna = &OyunOyna;
    return this;
};
void TurOyna(const Oyun this, int sayi)
{
    this->tur++;
    for (int i = 0; i < this->kisiSayisi; i++)
    {
        if (this->kisiler[i]->para >= 1000)
        {
            if (this->kisiler[i]->yatirdigiSayi == sayi)
            {
                this->kasa -= this->kisiler[i]->para * this->kisiler[i]->yatirdigiParaOrani * 10;
                this->kisiler[i]->ParaKazan(this->kisiler[i]);
            }
            else
            {
                this->kasa += this->kisiler[i]->para * this->kisiler[i]->yatirdigiParaOrani;
                this->kisiler[i]->ParaKaybet(this->kisiler[i]);
                if (this->kisiler[i]->para < 1000)
                    this->oyuncuSayisi--;
            }
            if (this->kisiler[i]->para > this->enZengin->para)
                this->enZengin = this->kisiler[i];
        }
    }
    //ÇIKTI YERİ
    printf("\n\n\n\t\t\t\t\t#############################################\n");
    if (sayi < 10)
        printf("\t\t\t\t\t##\t\tSANSLI SAYI: %d%15s\n", sayi, "##");
    else
        printf("\t\t\t\t\t##\t\tSANSLI SAYI: %d%14s\n", sayi, "##");
    printf("\t\t\t\t\t#############################################\n");
    printf("\t\t\t\t\t#############################################\n");
    if (this->tur < 10)
        printf("\t\t\t\t\t##\t\tTUR: %d%23s\n", this->tur, "##");
    else if (this->tur < 100)
        printf("\t\t\t\t\t##\t\tTUR: %d%22s\n", this->tur, "##");
    else
        printf("\t\t\t\t\t##\t\tTUR: %d%21s\n", this->tur, "##");
    printf("\t\t\t\t\t##\tMASA BAKIYE: %d TL%13s\n", (int)round(this->kasa), "##");
    printf("\t\t\t\t\t##%43s\n", "##");
    printf("\t\t\t\t\t##-----------------------------------------##\n");
    printf("\t\t\t\t\t##\t\tEN ZENGIN KISI%15s\n", "##");
    printf("\t\t\t\t\t##%28s%15s\n", this->enZengin->isim, "##");
    if ((int)round(this->enZengin->para) < 10000)
        printf("\t\t\t\t\t##\tBAKIYESI: %d%23s\n", (int)round(this->enZengin->para), "##");
    else if ((int)round(this->enZengin->para) < 100000)
        printf("\t\t\t\t\t##\tBAKIYESI: %d%22s\n", (int)round(this->enZengin->para), "##");
    else
        printf("\t\t\t\t\t##\tBAKIYESI: %d%21s\n", (int)round(this->enZengin->para), "##");
    printf("\t\t\t\t\t##%43s\n", "##");
    printf("\t\t\t\t\t#############################################\n");

    Sleep(25);
    system("cls");
    //ÇIKTI YERİ
};

void OyunOyna(const Oyun this)
{
    printf("%d\n", this->sayiSayisi);
    for (int i = 0; i < this->sayiSayisi; i++)
    {
        if (this->oyuncuSayisi > 0)
        {
            TurOyna(this, this->sayilar[i]);
        }
        else
        {
            printf("\n\n\n\t\t\t\t\t#############################################\n");
            if (this->tur < 10)
                printf("\t\t\t\t\t##\t\tTUR: %d%23s\n", this->tur, "##");
            else if (this->tur < 100)
                printf("\t\t\t\t\t##\t\tTUR: %d%22s\n", this->tur, "##");
            else
                printf("\t\t\t\t\t##\t\tTUR: %d%21s\n", this->tur, "##");
            printf("\t\t\t\t\t##\tMASA BAKIYE: %d TL%13s\n", (int)round(this->kasa), "##");
            printf("\t\t\t\t\t##%43s\n", "##");
            printf("\t\t\t\t\t##-----------------------------------------##\n");
            printf("\t\t\t\t\t##\t\tOYUN BITTI%19s\n", "##");
            printf("\t\t\t\t\t##%43s\n", "##");
            printf("\t\t\t\t\t##%43s\n", "##");
            printf("\t\t\t\t\t##%43s\n", "##");
            printf("\t\t\t\t\t#############################################\n");
            break;
        }
        if (i == this->sayiSayisi - 1)
        {
            i = 0;
        }
    }
};