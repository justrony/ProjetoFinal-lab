/****************************************************/
/*Alunos: RONIELLE DE SOUZA, RYAN MACEDO, PEDRO IURY*/
/*Matricula:                                        */
/*Avaliacao 04: Trabalho Final                      */
/*14.12.2023 - 2023.2 - Porf. Daniel Ferreira       */
/*Compilador: gcc/mingw versão: (tdm64-1) 10.3.0    */
/****************************************************/

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
void viewPGMImage(struct pgm *pio);
void gerarSCM(unsigned char *, unsigned char *, char *, int, struct pgm *pio);
