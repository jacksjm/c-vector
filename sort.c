#include "sort.h"

void merge(int *vetor, int nStart, int nMid, int nEnd);

void quick_sort(int *vetor, int indice_esq, int indice_dir) {
   // Desenvolva o código do Quicksort
   int nIdxLeft; //Variavel de controle da referência a esquerda
   int nIdxRight; //Variavel de controle da referência a direita
   int nMidPoint; //Variavel para encontrar o ponto médio
   int nTmp; //Variavel auxiliar

   //Seleciona os valores de índice conforme os parâmetros
   nIdxLeft = indice_esq;
   nIdxRight = indice_dir;

   //Determina o ponto médio
   nMidPoint = vetor[ (nIdxLeft + nIdxRight) / 2 ];

   //Executa até que o valor de esquerda seja maior ou igual ao de direita
   do {
      //Executa até chegar ao limite da Direita ou até chegar ao valor do
      // ponto médio para identificar qual é o menor valor
      while( vetor[nIdxLeft] < nMidPoint && nIdxLeft < indice_dir){
         nIdxLeft++;
      }
      //Executa até chegar ao limite da Esquerda ou até chegar ao valor do
      // ponto médio para identificar qual é o maior valor
      while( vetor[nIdxRight] > nMidPoint && nIdxRight > indice_esq){
         nIdxRight--;
      }
      // Caso o valor da esquerda seja menor ou igual, inverte os valores
      if( nIdxLeft <= nIdxRight){
         nTmp = vetor[nIdxLeft];
         vetor[nIdxLeft] = vetor[nIdxRight];
         vetor[nIdxRight] = nTmp;
         nIdxLeft++;
         nIdxRight--;
      }

   } while (nIdxLeft <= nIdxRight);

   // Caso o valor encontrado seja maior que o primeiro valor
   // reduz o problema para continuar a ordenação
   if( nIdxRight > indice_esq){
      quick_sort(vetor, indice_esq, nIdxRight);
   }
    // Caso o valor encontrado seja menor que o último valor
   // reduz o problema para continuar a ordenação
   if ( nIdxLeft < indice_dir){
      quick_sort(vetor, nIdxLeft, indice_dir);
   }
}

void bubble_sort(int *vetor, int nMax) {
   // Desenvolva o código do Bubblesort
   int nCnt;
   int nCnt2;
   int nTmp;

   for(nCnt = 0; nCnt < nMax; nCnt++){
      for(nCnt2 = nCnt+1; nCnt2 < nMax; nCnt2++){
         if(vetor[nCnt2] < vetor[nCnt]){
            nTmp = vetor[nCnt];
            vetor[nCnt] = vetor[nCnt2];
            vetor[nCnt2] = nTmp;
         }
      }
   }
}

void merge_sort(int *vetor, int nStart, int nEnd) {
   // Desenvolva o código do Mergesort
   int nMid;
 
   if(nStart < nEnd) {
      nMid = ( nStart + nEnd ) / 2;
      
      merge_sort(vetor, nStart, nMid);
      merge_sort(vetor, nMid+1, nEnd);
      merge(vetor,nStart,nMid,nEnd);
   }
}

void merge(int *vetor, int nStart, int nMid, int nEnd) {
   int nCntPos;
   int nStartLeft;
   int nStartRight;
   int nCnt;

   int aAux[nEnd+1];

   nStartLeft = nStart;
   nStartRight = nMid + 1;
   nCntPos = nStart;

   while (nStartLeft <= nMid && nStartRight <= nEnd){
      if( vetor[nStartLeft] <= vetor[nStartRight]){
         aAux[nCntPos] = vetor[nStartLeft];  
         nStartLeft++;
      } else {
         aAux[nCntPos] = vetor[nStartRight];
         nStartRight++;
      }
      nCntPos++;
   }

   for (nCnt = nStartLeft;nCnt<=nMid;nCnt++){
      aAux[nCntPos] = vetor[nCnt];
      nCntPos++;
   }
   for (nCnt = nStartRight;nCnt <= nEnd;nCnt++){
      aAux[nCntPos] = vetor[nCnt];
      nCntPos++;
   }
   for(nCnt = nStart;nCnt <= nEnd; nCnt++){
      vetor[nCnt] = aAux[nCnt];
   }
}