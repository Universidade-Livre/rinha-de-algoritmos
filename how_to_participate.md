# Como participar

Nesta seção descreveremos os procedimentos para participação na Rinha de Algoritmos.

## Instâncias

Para cada problema fornecemos 3 instâncias relativamente pequenas para realizar os testes dos algoritmos. As instâncias referentes ao problema $1 \leq i \leq 3$ encontram-se em `resources/instances/problem_0i`. Ainda, todas as pastas contêm um arquivo `results.txt` com as soluções ótimas das instâncias dadas, separadas por espaço.

Nas seções abaixo, descreveremos a estrutura dos arquivos de texto que compõem as instâncias e formalizaremos os objetivos e restrições.

### Estrutura: Problema 01

As instâncias estão organizadas da seguinte maneira.

- A primeira linha contêm a quantidade $n_{1}$ de agentes e a quantidade $n_{2}$ de missões, respectivamente.

- Cada linha $2 \leq i \leq n_{1} + 1$ corresponde às informações de do agente $i$. As informações, separadas por espaços, informam a avaliação do agente e uma lista de habilidades que o agente possui, nesta ordem.

- A linha $n_{1} + 2 \leq i \leq n_{1} + n_{2} + 1$ contêm informações sobre a missão $i$. Essas linhas estão estruturadas de forma semelhante aos agentes, contendo a avaliação mínima necessária para um agente ser alocado a essa missão e uma lista de habilidades necessárias, separadas por espaço, nesta ordem.

- A linha $n_{1} + n_{2} + 2 \leq i \leq 2n_{1} + n_{2} + 1$ contêm informações sobre o custo de alocar o agente $i$ para cada missão, se for possível. Assim como nos casos anteriores, os valores são dividos por espaços. O $j$-ésimo valor da lista corresponde ao custo de alocar o agente $i$ à missão $j$.

**Objetivo:** 

- Realize uma alocação de agentes que minimize o custo.

**Restrições:** 

- Um agente deve ser alocado a no máximo uma missão.

- Uma missão pode ser assumida por no máximo um agente.

### Estrutura: Problema 02



### Estrutura: Problema 03

