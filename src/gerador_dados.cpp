#include "../include/gerador_dados.h"
#include <random>
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

vector<int> gerarVetorAleatorio(int tamanho, int min, int max) {
    vector<int> vet(tamanho);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);

    for (int i = 0; i < tamanho; i++) {
        vet[i] = dist(gen);
    }

    return vet;
}