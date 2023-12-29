![Learn4Elixir](./resources/img/header.png)

<p align="center">
  <a href="https://discord.gg/eXUBTY6HAu">
      <img src="https://img.shields.io/discord/866378348368625704.svg?label=&logo=discord&logoColor=ffffff&color=7389D8&labelColor=6A7EC2" alt="Discord">
  </a>
  <a href="https://github.com/Universidade-Livre/rinha-de-algoritmos/stargazers">
      <img alt="GitHub Repo stars" src="https://img.shields.io/github/stars/Universidade-Livre/rinha-de-algoritmos?logo=apache%20spark&logoColor=gray&labelColor=E6E600&color=D8D800">
  </a>
</p>

<hr>

> Você está prestes a entrar na Rinha de Algoritmos, uma competição incrível que desafia você a mostrar o seu talento no mundo dos algoritmos e estruturas de dados. Nesta aventura, você vai enfrentar problemas reais que exigem soluções criativas e eficientes. Você vai se surpreender com casos curiosos, onde a sua habilidade em resolver desafios computacionais fará toda a diferença. Prepare-se para se divertir em um ambiente estimulante, onde o seu domínio algorítmico será testado. Venha para a Rinha de Algoritmos e embarque nessa jornada desafiadora!

## O que é?

A rinha de algoritmos é uma competição amistosa baseada em competições similares, como a [Rinha de Compiladores](https://github.com/aripiprazole/rinha-de-compiler), [Rinha de Frontend](https://github.com/codante-io/rinha-frontend), e [Rinha de Backend](https://github.com/zanfranceschi/rinha-de-backend-2023-q3). O projeto possui como objetivo avaliar a capacidade dos participantes no design de algoritmos e estruturas de dados para resolver problemas práticos.

Para avaliar os participantes, a descrição de algum caso prático será proposta. Caberá aos participantes identificar o problema e propor a melhor solução para resolvê-lo. Seguindo o mesmo modelo de maratonas de programação, serão fornecidas uma lista de entradas e de resultados esperados, em formato de texto, que poderão ser utilizados para guiar a criação do algoritmo. A pontuação e o ranking correspondente serão baseados em instâncias privadas que serão liberadas **apenas ao final** da competição.

Cada participante deverá entregar um algoritmo, sinalizando para qual problema aquele algoritmo foi criado, podendo utilizar apenas 2 unidades de CPU e 2GB de memória. Para mais detalhes sobre as submissões, veja [como submeter um algoritmo](how_to_participate.md).

Caso hajam dúvidas, por favor abram uma *issue* ou utilizem o nosso servidor do Discord!

## Regras

- Embora estaremos sempre incentivando a conversa e colaboração entre os participantes em prol do estabelecimento de um ambiente de aprendizado, não será permitido compartilhar as soluções nos canais de comunicação da UBL¹;

- Para essa competição é importante ressaltar que **não** é permitido o uso de *solvers*².  

- Caso sejam utilizados algoritmos de Monte Carlo³, o valor de solução a ser considerado será o melhor dentre $40$ iterações do algoritmo, ou o valor mais próximo possível dessa quantidade de iterações, a depender do tempo necessário para uma solução ser computada.

---

> ¹: *Note que isso não proibe tirar dúvidas de outros participantes ou fornecer direções. Não esperamos que cada candidato submeta uma solução única, até mesmo porque uma implementação inteligente pode fazer a diferença entre ambas as submissões.*
>
> ²: *Um solver é um programa de computador que, quando aplicado a um problema, é capaz de encontrar a solução automaticamente, sem intervenção direta ou ajuste significativo por parte do usuário. Geralmente, o objetivo de um solver é encontrar a melhor solução ou uma solução aproximada para o problema, tornando-o um mecanismo automatizado de resolução. Na Rinha de Algoritmos, seu uso é proibido. A justificativa é incentivar a resolução manual e criativa dos problemas.*
> 
> ³: *Aos participantes interessados em aprender mais sobre algoritmos probabilisticos, vejam os livros recomendados para a Rinha e a página na [Wikipedia](https://en.wikipedia.org/wiki/Randomized_algorithm).*

---

## Pontuação

Uma função $f: \mathbb{R}^2 \rightarrow \mathbb{R}$ determinará a pontuação dos participantes. Antes de descrevê-la, denotaremos por $\mathbf{x} = [x_1 \; x_2]^T$ o vetor de saída do algoritmo, onde $x_1$ é o tempo, em segundos, para obtenção da solução, e $x_2$ é o valor da **solução viável**¹ encontrada.

A pontuação é dada por $f(\mathbf{x}) = \min(100, \; C_{1} / x_{1}) + \min(100, \; C_{2} / |x^{\star} - x_{2}|)$, onde $x^{\star}$ é o valor da solução ótima. As constantes $C_1$ e $C_2$ serão definidas para cada problema, e servem para penalizar o tempo de execução e o quão distante a solução viável está do ótimo, respectivamente.

Vale ressaltar que quanto maior for o valor de $f(\mathbf{x})$, melhor será a pontuação.

---

> ¹: *Uma solução viável é toda solução que satisfazem as restrições do problema, embora talvez não seja a solução ótima.*

---

## Problemas

### Problema 01: Lucro de Plantação no Stardew Valley

**Descrição:** Na busca por otimizar seus ganhos enquanto joga Stardew Valley, você analisa as opções de sementes disponíveis em determinado momento e registra a quantidade de espaços disponíveis para o plantio. 

Por ser um fazendeiro organizado, você já tem conhecimento sobre a quantia de moedas que pode obter ao plantar cada tipo de semente durante um período específico, bem como a quantidade de espaços necessários para cada uma delas. Seu objetivo é, portanto, maximizar seu lucro ao plantar o maior número possível de sementes, levando em consideração a capacidade de plantio disponível, ao final do período escolhido.

Para esse problema, definiremos $C_{1} = 1$, $C_{2} = 0.2$, e uma pontuação bônus por cada instância resolvida de $C_{3} = 50$. Ainda, para fins de simplicidade, assumiremos que todas as sementes possuem o mesmo tempo de plantio e maturação.

Confira os detalhes em [como participar](how_to_participate.md#problema-01).

---

### Problema 02: ???

**Descrição:** ???

---

### Problema 03: ???

**Descrição:** ???

## Resultados

Nesta seção disponibilizaremos os resultados das submissões. Para cada instância resolvida, uma pontuação bônus será aplicada. 

Incluiremos uma submissão secreta de um membro da moderação da UBL para fins de benchmarking inicial. Esta submissão **não** será considerada para fins de premiação.

A pontuação será calculada a partir da média de $40$ iterações do algoritmo.

---
### Resultados do Problema 01:

| Posição | Participante | Segundos | Resolvidas | Linguagem
| ---------- | ---------- | ------- | ------- | ---------- |
| - | Secreto | ? | ?/20 | ? |
---

### Resultados do Problema 02:

| Posição | Participante | Pontuação | Resolvidas | Linguagem
| ---------- | ---------- | ------- | ------- | ---------- |
| - | Secreto | ? | ?/20 | ? |

---

### Resultados do Problema 03:

| Posição | Participante | Pontuação | Resolvidas | Linguagem
| ---------- | ---------- | ------- | ------- | ---------- |
| - | Secreto | ? | ?/20 | ? |

---


## Premiação

Forneceremos uma premiação simbólica para os três primeiros colocados. Esta premiação consiste em cargos comemorativos no [servidor da UBL](url).

## Leitura recomendada

Nesta seção incluiremos alguns livros recomendados que podem ajudar na elaboração de algoritmos para os problemas que serão trabalhados nesta Rinha. Quando gratuitos, incluiremos um link para acesso.

Não faremos a distinção entre um livro de nível básico ou avançado. Cabe ao participante conferir as primeiras páginas do livro e fazer esse juízo por si só.

### Referências

- Carvalho, Cerioli, Dahab, Feofiloff, Fernandes, Ferreira, Guimarães, Miyazawa, Pina Jr, Soares, Wakabayashi, Uma Introdução Sucinta a Algoritmos de Aproximação, IMPA, 2001. [Disponivel aqui](https://www.ime.usp.br/~cris/aprox/).

- Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). London, England: MIT Press.

- J.L. Szwarcfiter e L. Markenzon,  Estruturas de Dados e seus Algoritmos, 2a.ed., Livros Técnicos e Científicos, 1994.

- Kleinberg, J., & Tardos, E. (2006). Algorithm design. Pearson Education India.

- Mitzenmacher, M., & Upfal, E. (2017). Probability and computing (2nd ed.). Cambridge, England: Cambridge University Press.

- Motwani, R., & Raghavan, P. (1995). Randomized algorithms. Cambridge University Press. 

- P. Feofiloff, Y. Kohayakawa, & Y. Wakabayashi. (2011). Uma Introdução Sucinta à Teoria dos Grafos. [Disponível aqui](https://www.ime.usp.br/~pf/teoriadosgrafos/).

- P. Feofiloff. Análise de Algoritmos. [Disponível aqui](https://www.ime.usp.br/~pf/analise_de_algoritmos/).

- P. Feofiloff. (2019). Minicurso de Análise de Algoritmos. [Disponível aqui](https://www.ime.usp.br/~pf/livrinho-AA/).

- Vazirani, V. V. (2002). Approximation algorithms. Springer Science & Business Media.