/****************************************************/
/*Alunos: RONIELLE DE SOUZA, RYAN MACEDO, PEDRO IURY*/
/*Matricula:                                        */
/*Avaliacao 04: Trabalho Final                      */
/*14.12.2023 - 2023.2 - Porf. Daniel Ferreira       */
/*Compilador: gcc/mingw versão: (tdm64-1) 10.3.0    */
/****************************************************/
#include "ff.h"

void gerarSCM(unsigned char *dados, unsigned char *dadosF, char *filename, int niveis, struct pgm *pio, int filtro)
{
    char rotulo[20];
    char nomeArquivo[20];
    FILE *fp;
    static int count = 0;
    int *scm;
    scm = (int *)malloc(niveis * niveis * sizeof(int));
    sprintf(nomeArquivo, "SCM-Qtz_%d_%d.txt", niveis, filtro);

    fp = fopen(nomeArquivo, "a");

    if (fp == NULL)
    {   
        
        puts("Erro ao abrir o arquivo");
        exit(1);
    }
 
    if (count<1)
    {
        for (int i = 1; i <= niveis * niveis; i++)
        {
            
            fprintf(fp, "%d, ", i);
        }
        
        fprintf(fp,"%d", niveis*niveis + 1 );
        fputc('\n', fp);
        count++;
    }


       for (int i = 0; i < niveis ; i++){
         for (int j = 0; j < niveis ; j++){
            (scm[i *niveis + j])  = 0;
            
         }
    }
    
       // Preenche com a coocorrência
    for (int i = 0; i < pio->r * pio->c; i++) {
        int indice_dados = dados[i];
        int indice_dadosF = dadosF[i];
        (scm[indice_dados * niveis + indice_dadosF])++;
     }

    for (int i = 0; i < niveis; i++)
    {
        for (int j = 0; j < niveis; j++){
            fprintf(fp, "%d, ", scm[i * niveis + j]);
        }
        
    }

    if (*filename == '1')
    {
        strcpy(rotulo, "stroma");
    }
    else
    {
        strcpy(rotulo, "epithelium");
    }

    fprintf(fp, "%s", rotulo);
    fputc('\n', fp);

    fclose(fp);
    free(scm);
}



void quantizeImage(unsigned char *dados, int linha, int coluna, int nivel, int mv)
{
    int quantizedValue;

    for (int i = 0; i < linha * coluna; i++)
    {
        quantizedValue = (dados[i] * nivel) / mv;
        // Atualiza o valor na imagem
        dados[i] = (unsigned char)quantizedValue;
    }
    quantizedValue = 0;
}

void filtraMatriz(unsigned char *dados, int linha, int coluna, int filtro)
{
    if (filtro != 3 && filtro != 5 && filtro != 7)
    {
        fprintf(stderr, "Erro: O número de filtro deve ser 3, 5 ou 7.\n");
        exit(EXIT_FAILURE);
    }

    int soma = 0;
    int media = 0;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            soma = 0;
            for (int x = i - filtro / 2; x <= i + filtro / 2; x++) 
            {
                for (int y = j - filtro / 2; y <= j + filtro / 2; y++)
                {
                    if (x >= 0 && x < linha && y >= 0 && y < coluna)
                    {
                        soma += dados[x * linha + y];
                    }
                }
            }
            media = soma / (filtro * filtro); 

            dados[i * coluna + j] = media;
        }
    }
}


int criaCoocorrencias(int *matriz, unsigned char *dados, unsigned char *dadosF, int niveis, int linhas, int colunas)
{
    // Preenche com a coocorrência
    for (int i = 0; i < linhas * colunas; i++) {
        int indice_dados = dados[i];
        int indice_dadosF = dadosF[i];

        // Garante que os índices estejam dentro dos limites
        if (indice_dados < niveis && indice_dadosF < niveis) {
            matriz[indice_dados * niveis + indice_dadosF]++;
        }
     }
    }


