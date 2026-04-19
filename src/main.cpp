#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "../include/buscas.h"
#include "../include/ordenacoes.h"
#include "../include/gerador_dados.h"
#include "../include/medidor_tempo.h"
#include "../include/util.h"

int main() {
    vector<int> tamanhosBusca = {10000, 50000, 100000, 500000, 1000000, 2000000, 4000000, 10000000};
    vector<int> tamanhosOrdenacao = {100, 500, 1000, 2000, 5000, 10000, 20000};

    vector<pair<int, double>> resultadosBuscaSequencial;
    vector<pair<int, double>> resultadosBuscaBinaria;
    vector<pair<int, double>> resultadosSelectionSort;
    vector<pair<int, double>> resultadosMergeSort;

    cout << "Iniciando testes de busca...\n";

    for (int n : tamanhosBusca) {
        vector<int> vet = gerarVetorOrdenado(n);
        int alvo = vet[n - 1];

        int repeticoes = 1000;

        double tempoSeq = medirTempoMedio([&]() {
            buscaSequencial(vet, alvo);
        }, repeticoes);

        double tempoBin = medirTempoMedio([&]() {
            buscaBinaria(vet, alvo);
        }, repeticoes);

        resultadosBuscaSequencial.push_back({n, tempoSeq});
        resultadosBuscaBinaria.push_back({n, tempoBin});

        cout << "Busca n = " << n << " concluida.\n";
    }

    cout << "Iniciando testes de ordenacao...\n";

    for (int n : tamanhosOrdenacao) {
        vector<int> original = gerarVetorAleatorio(n, 0, 100000);

        int repeticoesSelection = 20;
        int repeticoesMerge = 20;

        double tempoSelection = medirTempoMedio([&]() {
            vector<int> copia = original;
            selectionSort(copia);
        }, repeticoesSelection);

        double tempoMerge = medirTempoMedio([&]() {
            vector<int> copia = original;
            mergeSort(copia, 0, (int)copia.size() - 1);
        }, repeticoesMerge);

        resultadosSelectionSort.push_back({n, tempoSelection});
        resultadosMergeSort.push_back({n, tempoMerge});

        cout << "Ordenacao n = " << n << " concluida.\n";
    }

    salvarCSV("resultados/tempos_busca_sequencial.csv", resultadosBuscaSequencial);
    salvarCSV("resultados/tempos_busca_binaria.csv", resultadosBuscaBinaria);
    salvarCSV("resultados/tempos_selection_sort.csv", resultadosSelectionSort);
    salvarCSV("resultados/tempos_mergesort.csv", resultadosMergeSort);

    cout << "\nResultados salvos na pasta resultados.\n";
    cout << "Execucao finalizada com sucesso.\n";

    return 0;
}