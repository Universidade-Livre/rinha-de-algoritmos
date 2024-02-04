Adaptação da Heurística clássica, Branch and Bound, proposta por Gilmore e Gomory para o problema da mochila  
*Gilmore, Paul C., and Ralph E. Gomory. 
"A linear programming approach to the cutting stock problem—Part II." 
Operations research 11.6 (1963): 863-888.*

Compile:
```shell
gcc -Ofast -o knapsack main.c
```

Execute:
```shell
./knapsack exemplo_xx.txt
```
Onde `exemplo_xx.txt` são os exemplares disponíveis para teste.

---

A heurística é baseada no seguinte algoritmo:

**Passo 01:** Definição do problema segundo as variáveis mais "valiosas"  
**1.1** Defina $\pi_{i}$ da seguinte forma:

Para $i = 1, \dots, n$ definimos a razão:
$$\pi_{i} = \frac{u_i}{l_i}$$

**1.2** Definidos os valores $\pi_{i}, i = 1,\dots, n$, definimos a seguinte ordenação:
$$\pi_1 \geq \pi_2 \geq \dots \geq \pi_{n}$$

**1.3** Defina $\underline{G} = 0$, o melhor valor para o objetivo da mochila encontrado.

**Passo 02:** Determinação da solução inicial - Busca em profundidade primeiro

**2.1** Determine a solução $X = (x_1, x_2, \dots, x_n)$, aqui ocorre a "adaptação" para o caso restrito considerando apenas uma unidade de item disponível:

$x_{i+1} = \left \lfloor \frac{L - \sum_{j=1}^{i}l_j x_j}{l_{i+1}} \right \rfloor\Rightarrow \text{sobra: } L - l_1 x_1 - l_2 x_2 - \dots - l_{i+1}x_{i+1}$

**Passo 03:** Avaliação da Solução corrente e armazenamento da mais valiosa

**3.1** Determine: $g(X) = \sum_{i=1}^{n} u_i x_i$

**3.2** Se $\underline{G} < g(X)$ então faça:
$\underline{G} = g(X)$
e guarde a solução correspondente: $X^* = X$

**Passo 04** Teste de parada e cálculo do limite superior

**4.1** Determine $r$, o maior índice tal que: $x_r \neq 0$.

**4.2** Se $X = (0,0,\dots,0)$ então **PARE**, a melhor solução guardada em $X^*$ é uma solução adotada.

Caso contrário, calcule:
$$\overline{G}(X) = u_1 x_1 + u_2 x_2 + \dots + u_r (x_r -1) + \frac{u_{r+1}}{l_{r+1}}(L - l_1 x_1 - l_2 x_2 - \dots - l_r (x_r - 1))$$

Se $r = n$, considere $u_{n+1} = 0$ e $l_{n+1} = 1$.

**Passo 05:** Backtracking

**5.1** Retorno longo

Se $\overline{G}(X) \leq \underline{G}$ faça:

$x_r = 0$ e volte ao {\bf Passo 04}.

{\bf 5.2} \{\emph{Retorno ao nó precedente e nova busca em profundidade}\}

Se $\overline{G}(X) > \underline{G}$ faça:

$x_r = x_r -1$ e defina a nova solução $X$:
$x_{j+1} = \left \lfloor \frac{L - \sum_{i=1}^{j}l_i x_i}{l_{j+1}} \right \rfloor, j = r,\dots, n-1$

volte ao *Passo 03*.

**Passo 06:** Print da Solução

*Fim do Algoritmo*

---
Existem outros algoritmos como o Martello e Toth (MTU2), porém meu recesso acabou hoje (hehehe) e não tive tempo de adaptar o que já tenho implementado aqui (hehe)

Caso alguém tenha interesse em implementar, esse [livro](https://doc.lagout.org/science/0_Computer%20Science/2_Algorithms/Knapsack%20Problems_%20Algorithms%20and%20Computer%20Implementations%20%5BMartello%20%26%20Toth%201990-11%5D.pdf) contempla esses métodos. Existem outros como *Knapsack Problems* escrito pelo *David Pisinger* que também possuem outras abordagens para o mesmo problema.

