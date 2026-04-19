#ifndef MEDIDOR_TEMPO_H
#define MEDIDOR_TEMPO_H
using namespace std;

#include <functional>

double medirTempoMedio(const function<void()>& funcao, int repeticoes);

#endif