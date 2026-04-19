import pandas as pd
import matplotlib.pyplot as plt
import os
import math

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RESULTADOS_DIR = os.path.join(BASE_DIR, "resultados")
GRAFICOS_DIR = os.path.join(BASE_DIR, "graficos")

os.makedirs(GRAFICOS_DIR, exist_ok=True)


def carregar_csv(nome_arquivo):
    caminho = os.path.join(RESULTADOS_DIR, nome_arquivo)
    return pd.read_csv(caminho)


def normalizar_curva(x, y_real, func_teorica):
    valores_teoricos = [func_teorica(v) for v in x]

    max_real = max(y_real)
    max_teorico = max(valores_teoricos)

    if max_teorico == 0:
        return valores_teoricos

    fator = max_real / max_teorico
    return [v * fator for v in valores_teoricos]


def plotar_grafico(df, titulo, nome_saida, func_teorica=None, legenda_teorica=None):
    x = df["n"]
    y = df["tempo_ms"]

    plt.figure(figsize=(10, 6))
    plt.plot(x, y, marker="o", label="Tempo medido")

    if func_teorica is not None and legenda_teorica is not None:
        y_teorico = normalizar_curva(x, y, func_teorica)
        plt.plot(x, y_teorico, linestyle="--", label=legenda_teorica)

    plt.title(titulo)
    plt.xlabel("Tamanho da entrada (n)")
    plt.ylabel("Tempo médio (ms)")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()

    caminho_saida = os.path.join(GRAFICOS_DIR, nome_saida)
    plt.savefig(caminho_saida)
    plt.close()

    print(f"Gráfico salvo em: {caminho_saida}")


def main():
    df_seq = carregar_csv("tempos_busca_sequencial.csv")
    plotar_grafico(
        df_seq,
        "Busca Sequencial: tempo vs tamanho da entrada",
        "busca_sequencial.png",
        func_teorica=lambda n: n,
        legenda_teorica="Curva teórica O(n)"
    )

    df_bin = carregar_csv("tempos_busca_binaria.csv")
    plotar_grafico(
        df_bin,
        "Busca Binária: tempo vs tamanho da entrada",
        "busca_binaria.png",
        func_teorica=lambda n: math.log2(n),
        legenda_teorica="Curva teórica O(log n)"
    )

    df_sel = carregar_csv("tempos_selection_sort.csv")
    plotar_grafico(
        df_sel,
        "Selection Sort: tempo vs tamanho da entrada",
        "selection_sort.png",
        func_teorica=lambda n: n**2,
        legenda_teorica="Curva teórica O(n²)"
    )

    df_merge = carregar_csv("tempos_mergesort.csv")
    plotar_grafico(
        df_merge,
        "Merge Sort: tempo vs tamanho da entrada",
        "merge_sort.png",
        func_teorica=lambda n: n * math.log2(n),
        legenda_teorica="Curva teórica O(n log n)"
    )

    print("Gráficos gerados com sucesso.")


if __name__ == "__main__":
    main()