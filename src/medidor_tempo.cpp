#include "../include/medidor_tempo.h"
using namespace std;

#include <chrono>

double medirTempoMedio(const function<void()>& funcao, int repeticoes) {
    using namespace chrono;

    double soma = 0.0;

    for (int i = 0; i < repeticoes; i++) {
        auto inicio = high_resolution_clock::now();
        funcao();
        auto fim = high_resolution_clock::now();

        duration<double, milli> duracao = fim - inicio;
        soma += duracao.count();
    }

    return soma / repeticoes;
}