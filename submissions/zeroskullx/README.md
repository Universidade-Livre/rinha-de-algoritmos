# Zeroskullx

## Problema 01: Lucro de Plantação no Stardew Valley

**🛠 Getting Started**

- JavaScript
- Node v20.10.0

**🚀 Run problem**

```bash
node problema-01
or
node problema-01 -S
```

_Utilize -S para visualizar as sementes plantadas._

## Algoritmo de Programação Dinâmica

"Programação Dinâmica é uma técnica de otimização que resolve problemas dividindo-os em subproblemas menores e resolvendo cada subproblema apenas uma vez."

Iniciei o processo criando uma matriz para armazenar as sementes válidas. Além disso, levei a análise um passo adiante ao incluir as sementes plantadas, junto com o valor gerado por elas. No entanto, antes de chegar a esses resultados, elaborei um array de sementes com base nos exemplos do arquivo de texto. Isso foi feito para proporcionar uma compreensão mais aprofundada do algoritmo que seria aplicado às sementes.

```typescript
[
  {
    seed: string, //nome da semente baseado no index da linha
    spaceRequired: number,
    coins: number,
  },
];
```

_Não usei typescript, somente para fins ilustrativos_

## Desempenho do Algoritmo

O desempenho do algoritmo pode depender de diversos fatores, incluindo o tamanho dos dados de entrada. O algoritmo `maxCoins` é uma implementação de um problema clássico chamado "Problema da Mochila" usando programação dinâmica. A complexidade de tempo típica do algoritmo é da ordem de O(n \* W), onde "n" é o número de sementes e "W" é a capacidade total dos espaços disponíveis.

## Resultado Template

```bash
../exemplo_02.txt
🌱 Sementes plantadas: 2, 3, 4, 6, 8, 9
🟡 Valor máximo obtido: 407
```
