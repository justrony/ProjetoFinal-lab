
README:

Este é um programa em C que processa imagens PGM (Portable Gray Map) localizadas no diretório "./images". O código realiza a filtragem e a quantização nas imagens, calcula a matriz de co-ocorrência e gera um arquivo txt contendo a matriz resultante.

Requisitos:

O código utiliza a biblioteca "ff.h" para a manipulação de imagens PGM. Certifique-se de que a biblioteca está instalada antes de compilar e executar o programa.
Certifique-se também se o diretorio de imagens está nomeado corretamente como "images".

Compilação:

Compile o programa utilizando um compilador C, com intermedio de uma execução de Makefile.

Uso:

O programa espera dois argumentos da linha de comando:

<Nível de Filtragem>
<Nível de Quantização>

Exemplo de execução:

./nome_do_executavel 3 16
Neste exemplo, o programa aplicará um nível de filtragem de 3 e um nível de quantização de 16.

Saída
Durante a execução, o programa processa cada arquivo no diretório "./images", realiza as operações especificadas e exibe mensagens de progresso. Ao final da execução, será exibido o tempo total gasto no processamento.
