#include "ff.h"

int main(int argc, char *argv[])
{
    clock_t begin, end;
    double tempo_total = 0;
    begin = clock();

    // Verifica o número correto de argumentos
    if (argc != 3)
    {
        fprintf(stderr, "Formato: %s <Nivel de Filtragem> <Nivel de Quantização>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Nível de Filtragem e Quantização
    int niveis = atoi(argv[1]);
    int quantizacao = atoi(argv[2]);

    // Abre o diretório
    DIR *d;
    struct dirent *dir;
    d = opendir("./images");

    if (d)
    {

        while ((dir = readdir(d)) != NULL)
        {
            // Ignorar diretórios "." e ".."
            if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            {
                continue;
            }

            printf("Processando arquivo: %s\n", dir->d_name);

            // Constrói o caminho completo do arquivo
            char caminhoCompleto[256];
            snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/%s", "./images", dir->d_name);
            
            // Leitura da Imagem - PGM
            struct pgm img;
            struct pgm imgF;
            readPGMImage(&img, caminhoCompleto);
            readPGMImage(&imgF,caminhoCompleto);

            // Copia os dados da struct img em uma nova struct que vai ser filtrada
    
            filtraMatriz(imgF.pData, imgF.r, imgF.c, niveis);
            quantizeImage(img.pData, img.r, img.c, quantizacao);
            quantizeImage(imgF.pData, imgF.r, imgF.c, quantizacao);
            gerarSCM(img.pData, imgF.pData, dir->d_name, quantizacao, &img);


            free(img.pData);
            free(imgF.pData);

        }
        closedir(d);
    }
    else
    {
        perror("Erro ao abrir o diretório");
        exit(EXIT_FAILURE);
    }
    end = clock();
      tempo_total = (double)end - begin/ CLOCKS_PER_SEC;
      printf("Tempo total %lf\n", tempo_total);
    return 0;
}