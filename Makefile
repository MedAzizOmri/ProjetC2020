prog:menu.o fonction.o
	gcc menu.c fonction.c -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf 
