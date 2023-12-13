/****************************************************/
/*Alunos: RONIELLE DE SOUZA, RYAN MACEDO, PEDRO IURY*/
/*Matricula:                                        */
/*Avaliacao 04: Trabalho Final                      */
/*14.12.2023 - 2023.2 - Porf. Daniel Ferreira       */
/*Compilador: gcc/mingw versão: (tdm64-1) 10.3.0    */
/****************************************************/
#include "ff.h"

void readPGMImage(struct pgm *pio, char *filename)
{
    FILE *fp;
    char ch;

    if (!(fp = fopen(filename, "r")))
    {
        perror("Erro.");
        exit(1);
    }
    printf("nome arq :%s\n", filename);

    if ((ch = getc(fp)) != 'P')
    {
        puts("A imagem fornecida não está no formato pgm");
        exit(2);
    }

    pio->tipo = getc(fp) - 48;

    fseek(fp, 1, SEEK_CUR);

    while ((ch = getc(fp)) == '#')
    {
        while ((ch = getc(fp)) != '\n')
            ;
    }

    fseek(fp, -2, SEEK_CUR);

    fscanf(fp, "%d %d", &pio->c, &pio->r);

    if (ferror(fp))
    {
        perror(NULL);
        exit(3);
    }
    fscanf(fp, "%d", &pio->mv);
    fseek(fp, 0, SEEK_CUR);

    pio->pData = (unsigned char *)malloc(pio->r * pio->c * sizeof(unsigned char));

    switch (pio->tipo)
    {
    case 2:
        puts("Lendo imagem PGM (dados em texto)");
        for (int k = 0; k < (pio->r * pio->c); k++)
        {
            fscanf(fp, "%hhu", pio->pData + k);
        }
        break;
    case 5:
        puts("Lendo imagem PGM (dados em binário)");
        fread(pio->pData, sizeof(unsigned char), pio->r * pio->c, fp);
        break;
    default:
        puts("Não está implementado");
    }
    fclose(fp);
}
