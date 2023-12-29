# Como participar

Nesta seção descreveremos os procedimentos para participação e submissão na Rinha de Algoritmos.

## Como submeter

Começar a Rinha de Algoritmos é muito mamão com açúcar, é só:

1. No seu Terminal, clone esse repositório com o comando `git clone git@github.com:Universidade-Livre/rinha-de-algoritmos`.
2. Crie uma ramificação (branch) no repositório clonado para a resolução do seu exercício com o comando `git checkout -b problema-1`.
3. Na pasta submissions crie uma pasta com o seu nome de usuário. Ex: `mateusrovedaa/`
4. Resolva o problema com base nas instruções informadas na seção [Instâncias](#instâncias) e salve o código em um arquivo `.txt` com o nome `problema-1.txt`. Além disso, crie um arquivo `README.md` colocando instruções ou detalhes da implementação que achar necessário.
5. Adicione as alterações feitas para serem enviadas com o comando `git add .`
6. Faça o commit enviando essas alterações `git commit -m "Completado o Problema 1"`.
7. Abra um PR para a ramificação main.

## Instâncias

Para cada problema fornecemos 3 instâncias relativamente pequenas para realizar os testes dos algoritmos. As instâncias referentes ao problema $1 \leq i \leq 3$ encontram-se em `resources/instancias/exemplo_0i`. Ainda, todas as pastas contêm um arquivo `resultados.txt` com as soluções ótimas das instâncias dadas, separadas por espaço.

Nas seções abaixo, descreveremos a estrutura dos arquivos de texto que compõem as instâncias e formalizaremos os objetivos e restrições.

## Estrutura dos Problemas

### Problema 01

**Instâncias:**

As instâncias estão organizadas da seguinte maneira.

- A primeira linha consiste de dois valores, a quantidade de sementes distintas e a quantidade de espaços disponíveis, respectivamente.

- As $n$ linhas seguintes, onde $n$ é a quantidade de sementes consistem de dois valores por linha, divididas por espaço. O primeiro é o espaço necessário para plantar a semente $i$, já o segundo corresponde ao ganho em moedas no final do periodo ao plantar esta semente.

**Objetivo:** 

- Obtenha o lucro máximo possível.

**Exemplo**

Suponhamos que você receba as informações abaixo, e que possui apenas 2 blocos disponíveis pra plantio.

| **Semente** | **Valor** | **Espaço** |
|-------------|-----------|------------|
| Café        | 150       | 1          |
| Arroz       | 260       | 2          |
| Cenoura     | 100       | 1          |

Podemos ver facilmente que a solução ótima é dada pelo plantio de arroz apenas.

---

### Problema 02

---

### Problema 03

