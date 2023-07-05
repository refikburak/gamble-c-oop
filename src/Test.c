#include "Dosya.h"

int main()
{
    // printf("Isim: %s", kisiler->isim);
    // char *a = "abcdef";
    // printf("%d", strlen(a));
    // Kisi *kisiler;
    // kisiler = (Kisi *)malloc(2 * sizeof(struct KISI));
    // Kisi kisi = KisiOlustur("Ahmet", 324.34, 12312, 1);
    // Kisi kisi1 = KisiOlustur("Mehmet", 123123.34, 56456, 3);
    // kisiler[0] = KisiOlustur("Ahmet", 324.34, 12312, 1);
    // kisiler[1] = KisiOlustur("Mehmet", 123123.34, 56456, 3);
    // for (int i = 0; i < 2; i++)
    //   printf("Isim: %s\nPara: %lf\nYatirdigi Oran: %f\nSansli Sayi: %d\n", kisiler[i]->isim, kisiler[i]->para, kisiler[i]->yatirdigiParaOrani, kisiler[i]->yatirdigiSayi);
    // Kisi *kisiler = (Kisi *)malloc(1000 * sizeof(struct KISI));
    // printf("Isim: %s\nPara: %lf\nYatirdigi Oran: %f\nSansli Sayi: %d\n", kisiler[0]->isim, kisiler[0]->para, kisiler[0]->yatirdigiParaOrani, kisiler[0]->yatirdigiSayi);
    // printf("Isim: %s\nPara: %lf\nYatirdigi Oran: %f\nSansli Sayi: %d\n", kisiler[1]->isim, kisiler[1]->para, kisiler[1]->yatirdigiParaOrani, kisiler[1]->yatirdigiSayi);
    // for (int i = 0; i < 1000; i++)
    //     printf("Isim: %s\nPara: %lf\nYatirdigi Oran: %f\nSansli Sayi: %d\n", kisiler[i]->isim, kisiler[i]->para, kisiler[i]->yatirdigiParaOrani, kisiler[i]->yatirdigiSayi);

    // for (int i = 0; i < SayiSayisiBul(dosya); i++)
    //     printf("Sayi:%d\n", sayilar[i]);

    Dosya dosya = DosyaOlustur();
    BagliListe b = BagliListeOlustur();
    b = dosya->KisiOku(dosya);
    Kisi gecici = b->ilk;
    while (gecici->sonraki != NULL)
    {
        printf("%lf\n", gecici->para);
        gecici = gecici->sonraki;
    }
    return 0;
}
