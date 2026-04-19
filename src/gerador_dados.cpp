#include "../include/gerador_dados.h"
using namespace std;

vector<int> gerarVetorOrdenado(int tamanho) {
    vector<int> vet(tamanho);

    for (int i = 0; i < tamanho; i++) {
        vet[i] = i;
    }

    return vet;
}

vector<int> gerarVetorInverso(int tamanho) {
    vector<int> vet(tamanho);

    for (int i = 0; i < tamanho; i++) {
        vet[i] = tamanho - i;
    }

    return vet;
}