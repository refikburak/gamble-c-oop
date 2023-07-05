hepsi:derle bagla calistir

derle:
	gcc -I ./include -o ./lib/Test.o -c ./src/Test.c
	gcc -I ./include -o ./lib/Dosya.o -c ./src/Dosya.c
	gcc -I ./include -o ./lib/Kisi.o -c ./src/Kisi.c
	gcc -I ./include -o ./lib/Oyun.o -c ./src/Oyun.c
	gcc -I ./include -o ./lib/BagliListe.o -c ./src/BagliListe.c


bagla:
	gcc -I ./include ./lib/Test.o ./lib/Dosya.o ./lib/Kisi.o ./lib/Oyun.o ./lib/BagliListe.o -o ./bin/Uygulama
calistir:
	./bin/Uygulama