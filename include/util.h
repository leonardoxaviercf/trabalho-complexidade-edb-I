#ifndef UTIL_H
#define UTIL_H
using namespace std;

#include <vector>
#include <string>
#include <utility>

bool estaOrdenado(const vector<int>& vet);
void salvarCSV(const string& nomeArquivo,
               const vector<pair<int, double>>& dados);

#endif