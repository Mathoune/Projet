NOM=PROJET_IN301

all: slider

run: slider
	./slider test.slider

# Edition de liens
slider: slider.o lire_ecrire.o afficher.o jeu.o deplacements.o
	gcc slider.o lire_ecrire.o afficher.o jeu.o deplacements.o -o slider -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

# Compilation
slider.o: slider.c mes_types.h lire_ecrire.h afficher.h 
	gcc -c -Wall `sdl-config --cflags` slider.c

# Compilation
lire_ecrire.o: lire_ecrire.c mes_types.h
	gcc -c -Wall lire_ecrire.c

# Compilation
afficher.o: afficher.c mes_types.h
	gcc -c -Wall `sdl-config --cflags` afficher.c
	
deplacements.o: deplacements.c mes_types.h 
	gcc -c -Wall `sdl-config --cflags` deplacements.c
	
jeu.o: jeu.c deplacements.h afficher.h
	gcc -c -Wall `sdl-config --cflags` jeu.c

editeur:
	geany Makefile *.c *.h

# Pour creer le zip a deposer sur e-campus
zip:
	rm -fr $(NOM)
	rm -f $(NOM).zip
	mkdir $(NOM)
	cp *.c $(NOM)
	cp *.h $(NOM)
	cp Makefile $(NOM)
#	cp -f *.slider $(NOM)
	zip $(NOM).zip $(NOM)/*
#	rm -fr $(NOM)



clean:
	rm -rf $(NOM)
	rm -f $(NOM).zip
	rm -f lire_ecrire.o
	rm -f afficher.o
	rm -f slider.o
	rm -f slider
