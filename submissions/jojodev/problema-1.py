import sys

def ler_entrada(nome_arquivo):
    matriz = []

    with open(nome_arquivo, 'r') as arquivo:
        primeira_linha = arquivo.readline().split()
        n, W = int(primeira_linha[0]), int(primeira_linha[1])

        for _ in range(n):
            linha = arquivo.readline().split()
            semente = [int(linha[0]), int(linha[1])]
            matriz.append(semente)

        pesos = [item[0] for item in matriz]
        valores = [item[1] for item in matriz]

    return n, W, pesos, valores


def knapsack_iterativo(capacidade, pesos, valores, n):

  tabela = [[0] * (capacidade + 1) for _ in range(n + 1)]

  for i in range(1, n + 1):
    for w in range(capacidade + 1):
      if pesos[i - 1] <= w:
        tabela[i][w] = max(valores[i - 1] + tabela[i - 1][w - pesos[i - 1]], tabela[i - 1][w])
      else:
        tabela[i][w] = tabela[i - 1][w]

  return tabela[n][capacidade]


if __name__ == "__main__":
    nome_arquivo = sys.argv[1]
    n, capacidade, pesos, valores = ler_entrada(nome_arquivo)
    resultado = knapsack_iterativo(capacidade, pesos, valores, n)
    print(resultado)
    