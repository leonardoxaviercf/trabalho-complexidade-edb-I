#include "../include/ordenacoes.h"
using namespace std;

static void merge(vector<int>& vet, int esquerda, int meio, int direita) {
    int tamanhoEsq = meio - esquerda + 1;
    int tamanhoDir = direita - meio;

    vector<int> esquerdaVet(tamanhoEsq);
    vector<int> direitaVet(tamanhoDir);

    for (int i = 0; i < tamanhoEsq; i++) {
        esquerdaVet[i] = vet[esquerda + i];
    }

    for (int j = 0; j < tamanhoDir; j++) {
        direitaVet[j] = vet[meio + 1 + j];
    }

    int i = 0, j = 0, k = esquerda;

    while (i < tamanhoEsq && j < tamanhoDir) {
        if (esquerdaVet[i] <= direitaVet[j]) {
            vet[k] = esquerdaVet[i];
            i++;
        } else {
            vet[k] = direitaVet[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsq) {
        vet[k] = esquerdaVet[i];
        i++;
        k++;
    }

    while (j < tamanhoDir) {
        vet[k] = direitaVet[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& vet, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(vet, esquerda, meio);
        mergeSort(vet, meio + 1, direita);
        merge(vet, esquerda, meio, direita);
    }
}