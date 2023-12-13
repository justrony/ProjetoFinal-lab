#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#define DIRETORIO_IMAGENS "./images"

struct pgm
{
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
};

void readPGMImage(struct pgm *, char *);
void quantizeImage(unsigned char *, int, int, int);
void filtraMatriz(unsigned char *, int, int, int);
int criaCoocorrencias(int *, unsigned char *, unsigned char *, int, int ,int);
void gerarSCM(unsigned char *, unsigned char *, char *, int, struct pgm *pio, int);