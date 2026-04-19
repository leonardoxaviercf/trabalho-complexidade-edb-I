#include "../include/buscas.h"
using namespace std;

int buscaSequencial(const vector<int>& vet, int alvo) {
    for (int i = 0; i < (int)vet.size(); i++) {
        if (vet[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(const vector<int>& vet, int alvo) {
    int esquerda = 0;
    int direita = (int)vet.size() - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (vet[meio] == alvo) {
            return meio;
        } else if (vet[meio] < alvo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return -1;
}