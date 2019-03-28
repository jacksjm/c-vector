## PASSOS PARA INICIALIZAÇÃO
1. Realize a extração dos arquivos SortPPA.zip em um diretório de sua escolha.
2. Localize o diretório através do Terminal (comando CD)
3. Ao acessar o diretório, execute o comando Make (ex.: `~/Documentos/C/PPA$ make`) para executar o programa. Será exibido no termina algo semelhante a:
```
                **** PRINT vetor lido N(15) **** 
###############################
(0)     0       1       2       3       4       5       6       7       8       9
(10)    10      11      12      13      14
                **** ORDENAÇÃO MERGE SORT **** 
                **** PRINT vetor Ordenado N(15) **** 
###############################
(0)     0       1       2       3       4       5       6       7       8       9
(10)    10      11      12      13      14
        Runtime: 0.000002
```
4. Caso deseje alterar os valores de geração, basta utilizar os parâmetros abaixo após o comando Make:
* TAMARQ (Numeric) - Determina o tamanho do Array a ser gerado (Default: 10)
* TIPSORT (Numeric) - Determina o tipo de Algoritmo que será executado (Default: 1-QuickSort)
    * 1-QuickSort;
    * 2-BubbleSort;
    * 3-MergeSort
* TIPORD (Numeric - Negative) - Determina o tipo de ordenação que o Array irá possuir (Default: -9999)
    * -9999 - Aleatório;
    * -8888 - Ordem Crescente;
    * -7777 - Ordem Decrescente

Exemplos de utilização:
* `make TIPARQ=20`: Irá gerar um Array de tamanho 20 composto de valores aleatórios e ordenará pelo metodo Quicksort;
* `make TIPSORT=2`: Irá gerar um Array de tamanho 10 composto de valores aleatórios e ordenará pelo metodo BubbleSort;
* `make TIPORD=-7777`: Irá gerar um Array de tamanho 10 composto de valores ordenados de maneira decrescente e ordenará pelo metodo Quicksort;
* `make TIPARQ=30 TIPSORT=3 TIPORD=-7777`: Irá gerar um Array de tamanho 30 composto de valores ordenados de maneira decrescente e ordenará pelo metodo MergeSort;
