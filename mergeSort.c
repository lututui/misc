
/* Desenvolva uma função que receba como parâmetro os ponteiros de 
dois vetores de 5 posições. O procedimento deverá imprimir na tela os 
valores contidos nos dois vetores de forma crescente */

#include <stdio.h>
#include <stdlib.h>

#define VLEN 5

void merge(int *v, int l, int r, int m);
void mergeSort(int *m, int l, int r);
void printArray(int *a, int start, int finish);
void imprimeCrescente(int *v1, int *v2);

int main() {
    int v1[VLEN] = {2, 5, 9, 8, 3};
    int v2[VLEN] = {7, 4, 1, 10, 6};
    
    imprimeCrescente(v1, v2);
}

void imprimeCrescente(int *v1, int *v2) {
    int *v = (int*) malloc(2 * VLEN * sizeof(int));
    int i, j;
    
    for (i = 0; i < VLEN; i++) {
        v[i] = v1[i];
    }
    
    for (j = 0; j < VLEN; j++, i++) {
        v[i] = v2[j];
    }
    
    
    printArray(v, 0, 2 * VLEN);
    
    mergeSort(v, 0, (2 * VLEN) - 1);
    
    printArray(v, 0, 2 * VLEN);
    
    free(v);
}

void printArray(int *a, int start, int finish) {
    int i;
    
    for (i = start; i < finish; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergeSort(int *v, int l, int r) {
    if (l >= r)
        return;
    
    
    int m = (l + r) / 2;
    
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    
    merge(v, l, r, m);
}

void merge(int *v, int l, int r, int m) {
    int tamanhoEsquerda = m - l + 1;
    int tamanhoDireita = r - m;
    
    int* copiaEsquerda = (int*) malloc(tamanhoEsquerda * sizeof(int));
    int* copiaDireita  = (int*) malloc(tamanhoDireita * sizeof(int));

    int i, i_copia;
    
    for (i = 0, i_copia = l; i < tamanhoEsquerda; i++, i_copia++) {
        copiaEsquerda[i] = v[i_copia];
    }
    
    for (i = 0, i_copia = m + 1; i < tamanhoDireita; i++, i_copia++) {
        copiaDireita[i] = v[i_copia];
    }
    
    int i_esquerda = 0, 
        i_direita = 0, 
        i_original = l;
    
    while (i_esquerda < tamanhoEsquerda && i_direita < tamanhoDireita) {
        if (copiaEsquerda[i_esquerda] <= copiaDireita[i_direita]) {
            v[i_original++] = copiaEsquerda[i_esquerda++];
        } else { 
            v[i_original++] = copiaDireita[i_direita++];
        }
    }
    
    while (i_esquerda < tamanhoEsquerda) {
        v[i_original++] = copiaEsquerda[i_esquerda++];
    }
    
    while (i_direita < tamanhoDireita) {
        v[i_original++] = copiaDireita[i_direita++];
    }
    
    
    free(copiaEsquerda);
    free(copiaDireita);
    
}
