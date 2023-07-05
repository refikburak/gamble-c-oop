#include "Dosya.h"

Dosya DosyaOlustur()
{
    Dosya this;
    this = (Dosya)malloc(sizeof(struct DOSYA));
    this->KisiOku = &KisiOku;
    this->SayiOku = &SayiOku;
    this->SayiSayisiBul = &SayiSayisiBul;
    this->KisiSayisiBul = &KisiSayisiBul;
    this->DosyaYokEt = &DosyaYokEt;
    return this;
};
int KisiSayisiBul(const Dosya this)
{
    FILE *dosya = fopen("Kisiler.txt", "r");
    int kisiSayisi = 0;
    char satir[255];
    while (!feof(dosya))
    {
        fgets(satir, 255, dosya);
        kisiSayisi++;
    };
    fclose(dosya);
    return kisiSayisi;
};
BagliListe KisiOku(const Dosya this)
{
    FILE *dosya = fopen("Kisiler.txt", "r");
    char satir[255];
    char *eptr;
    char *isim;
    double para;
    float yatirdigiOran;
    int sansliSayi;
    int kisisayac = 0;
    int sayac = 0;
    BagliListe kisiler = BagliListeOlustur();
    while (!feof(dosya))
    {
        fgets(satir, 255, dosya);
        char *token = strtok(satir, "#");
        while (token != NULL)
        {
            if (sayac % 4 == 0)
                isim = token;
            else if (sayac % 4 == 1)
                para = strtod(token, &eptr);

            else if (sayac % 4 == 2)
                yatirdigiOran = strtof(token, &eptr);
            else
                sansliSayi = atoi(token);
            token = strtok(NULL, "#");
            sayac++;
        };
        Kisi eklenecek = (Kisi)KisiOlustur(isim, para, yatirdigiOran, sansliSayi);
        kisiler->Ekle(kisiler, eklenecek);
        kisisayac++;
    };
    /*printf("1-)Isim: %s\nPara: %lf\nYatirdigi Oran: %f\nSansli Sayi: %d\n", kisiler[0]->isim, kisiler[0]->para, kisiler[0]->yatirdigiParaOrani, kisiler[0]->yatirdigiSayi);
    printf("2-)Isim: %s\nPara: %lf\nYatirdigi Oran: %f\nSansli Sayi: %d\n", kisiler[1]->isim, kisiler[1]->para, kisiler[1]->yatirdigiParaOrani, kisiler[1]->yatirdigiSayi);
    printf("3-)Isim: %s\nPara: %lf\nYatirdigi Oran: %f\nSansli Sayi: %d\n", kisiler[2]->isim, kisiler[2]->para, kisiler[2]->yatirdigiParaOrani, kisiler[2]->yatirdigiSayi);
    printf("4-)Isim: %s\nPara: %lf\nYatirdigi Oran: %f\nSansli Sayi: %d\n", kisiler[3]->isim, kisiler[3]->para, kisiler[3]->yatirdigiParaOrani, kisiler[3]->yatirdigiSayi);
    printf("5-)Isim: %s\nPara: %lf\nYatirdigi Oran: %f\nSansli Sayi: %d\n", kisiler[4]->isim, kisiler[4]->para, kisiler[4]->yatirdigiParaOrani, kisiler[4]->yatirdigiSayi);
    */
    fclose(dosya);
    return kisiler;
};
int SayiSayisiBul(const Dosya this)
{
    FILE *dosya = fopen("Sayilar.txt", "r");
    int sayiSayisi = 0;
    char satir[5];
    while (!feof(dosya))
    {
        fgets(satir, 255, dosya);
        sayiSayisi++;
    };
    fclose(dosya);
    return sayiSayisi;
};
int *SayiOku(const Dosya this)
{
    char satir[5];
    int sayiSayac = 0;
    FILE *dosya = fopen("Sayilar.txt", "r");
    int *sayilar = (int *)malloc(SayiSayisiBul(this) * sizeof(int));
    while (!feof(dosya))
    {
        fgets(satir, 255, dosya);
        sayilar[sayiSayac] = atoi(satir);
        sayiSayac++;
    };
    return sayilar;
};
void DosyaYokEt(Dosya this)
{
    if (this == NULL)
        return;
    free(this);
};
