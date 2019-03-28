#include <stdio.h>
#include <stdlib.h>

// Bibliotecas pessoais
#include "vector.h"
#include "toolsvector.h"
#include "sort.h"

int main(int argc, char** argv) {
  int nlinhas;
  int *vet = NULL;
  FILE *fvet;
  double start_time, end_time;

  if (argc != 3){
    printf ("ERRO: Numero de parametros %s <filename>", argv[0]);
    exit (1);
  }

  //nlinhas =  atoi(argv[1]);
  fvet = fopen(argv[1],"r");
  if (fvet == NULL) {
    printf("Error: Na abertura dos arquivos.");
    exit(1);
  }

  nlinhas = extrai_nroLine(fvet);
  vet = alocar_vetor(nlinhas);
  filein_vetor (vet, nlinhas, fvet);
  printf("\t\t**** PRINT vetor lido N(%d) **** \n", nlinhas);
  imprimir_vetor(vet, nlinhas);

  start_time = wtime();

  if(atoi(argv[2]) == 1){
    quick_sort(vet, 0, nlinhas - 1);
  } else if (atoi(argv[2]) == 2){
    bubble_sort(vet,nlinhas);
  } else {
    merge_sort(vet,0,nlinhas - 1);
  }
  
  end_time = wtime();
  if(atoi(argv[2]) == 1){
    printf("\t\t**** ORDENAÇÃO QUICK SORT **** \n");
  } else if (atoi(argv[2]) == 2){
    printf("\t\t**** ORDENAÇÃO BUBBLE SORT **** \n");
  } else {
    printf("\t\t**** ORDENAÇÃO MERGE SORT **** \n");
  }

  printf("\t\t**** PRINT vetor Ordenado N(%d) **** \n", nlinhas);
  imprimir_vetor(vet, nlinhas);

  printf("\tRuntime: %f\n", end_time - start_time);

  liberar_vetor (vet);
  fclose (fvet);
  return 0;
}
