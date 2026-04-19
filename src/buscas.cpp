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
