#include "../include/util.h"
#include <fstream>
using namespace std;

bool estaOrdenado(const vector<int>& vet) {
    for (int i = 1; i < (int)vet.size(); i++) {
        if (vet[i] < vet[i - 1]) {
            return false;
        }
    }
    return true;
}

void salvarCSV(const string& nomeArquivo,
               const vector<pair<int, double>>& dados) {
    ofstream arquivo(nomeArquivo);

    arquivo << "n,tempo_ms\n";

    for (const auto& par : dados) {
        arquivo << par.first << "," << par.second << "\n";
    }

    arquivo.close();
}