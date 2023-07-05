#ifndef DOSYA_H
#define DOSYA_H

#include "BagliListe.h"

struct DOSYA
{
    BagliListe (*KisiOku)(struct DOSYA *);
    int *(*SayiOku)(struct DOSYA *);
    void (*DosyaYokEt)(struct DOSYA *);
    int (*KisiSayisiBul)(struct DOSYA *);
    int (*SayiSayisiBul)(struct DOSYA *);
};
typedef struct DOSYA *Dosya;

Dosya DosyaOlustur();
int KisiSayisiBul(const Dosya);
int SayiSayisiBul(const Dosya);
BagliListe KisiOku(const Dosya);
int *SayiOku(const Dosya);
void DosyaYokEt(Dosya);

#endif