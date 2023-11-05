# Rinha de Algoritmos

## O que é?

A rinha de algoritmos é uma competição amistosa baseada em competições similares, como a [Rinha de Compiladores](https://github.com/aripiprazole/rinha-de-compiler), [Rinha de Frontend](https://github.com/codante-io/rinha-frontend), e [Rinha de Backend](https://github.com/zanfranceschi/rinha-de-backend-2023-q3). O projeto possui como objetivo avaliar a capacidade dos participantes no design de algoritmos e estruturas de dados para resolver problemas práticos.

Para avaliar os participantes, a descrição de algum caso prático será proposta. Caberá aos participantes identificar o problema e propor a melhor solução para resolvê-lo. Seguindo o mesmo modelo de maratonas de programação, serão fornecidas uma lista de entradas e de resultados esperados, em formato de texto, que poderão ser utilizados para guiar a criação do algoritmo. A pontuação e o ranking correspondente serão baseados em instâncias privadas. Estas serão liberadas apenas ao final da competição.

Cada participante deverá entregar um algoritmo, sinalizando para qual problema aquele algoritmo foi criado, podendo utilizar apenas 1 unidade de CPU e 2GB de memória. Para mais detalhes sobre as submissões, veja [Como submeter um algoritmo](#).

## Regras

Para essa competição é importante ressaltar que não é permitido o uso de *solvers*.  Um *solver* é um programa de computador que, quando aplicado a um problema, é capaz de encontrar a solução automaticamente, sem intervenção direta ou ajuste significativo por parte do usuário. Geralmente, o objetivo de um solver é encontrar a melhor solução ou uma solução aproximada para o problema, tornando-o um mecanismo automatizado de resolução. Na Rinha de Algoritmos, um solver é proibido para incentivar a resolução manual e criativa dos problemas.

Seja $x$ o valor da função objetivo retornado pelo algoritmo, $x_{opt}$ o valor objetivo da solução ótima e $y$ o tempo necessário para a obtenção da solução. A pontuação será determinada pela saída da função $f_{pontuação}(x) = f_{tempo}(y) + f_{aprox}(x)$, em que $f_{tempo}(y) = C_1y$ penaliza longos tempos computacionais e $f_{aprox}(x) = |x_{opt} - x| \times C_2$ penaliza soluções de baixa qualidade, ou seja, soluções cujo valor objetivo está significativamente distante do ótimo.

## Problemas

### Problema 01: Alocação Estratégica de Espiões

**Descrição:** Em uma agência de inteligência global, a alocação de agentes altamente treinados para missões secretas é uma tarefa crítica. Cada missão é única e envolve uma complexa rede de informações, espionagem e contrainteligência. Os agentes possuem diferentes especializações e níveis de habilidade.

Nós queremos alocar os agentes de forma estratégica para essas missões, levando em consideração suas habilidades, e as características de cada missão. O objetivo é maximizar a eficiência global da agência, sendo essa dada como a soma do nível de segurança e confidencialidade. No máximo um agente pode ser alocado por missão.

### Problema 02: Cobertura de Eventos Esportivos

**Descrição:** Um canal de esportes deseja otimizar a cobertura de eventos esportivos transmitindo-os ao vivo em diferentes horários. Existem vários eventos esportivos ocorrendo simultaneamente em diferentes locais, como partidas de futebol, corridas de automóveis e competições de tênis. A emissora possui uma programação fixa ao longo do dia, com horários disponíveis para transmissão.

O desafio é selecionar um conjunto mínimo de eventos esportivos para transmitir, de modo a cobrir o maior número possível de horários disponíveis, garantindo que nenhum horário fique vazio na programação. Cada evento tem um custo associado à transmissão, e o objetivo é minimizar o custo total da transmissão.

### Problema 03: Correção de Dependências de Software

**Descrição:** Em sistemas de software, módulos frequentemente possuem dependências uns dos outros, representando relações de chamada de funções ou bibliotecas. Nesses sistemas, comumente desejamos identificar e eliminar o menor número de módulos para corrigir dependências cíclicas indesejadas, que podem causar problemas de integridade no sistema.

O desafio é encontrar um conjunto mínimo de módulos a serem removidos para eliminar todas as dependências cíclicas no software, minimizando o impacto nas funcionalidades globais do sistema.

## Resultados

### Resultados do Problema 01:

### Resultados do Problema 02:

### Resultados do Problema 03:


## Premiação

Forneceremos uma premiação simbólica para os três primeiros colocados. Esta premiação consiste em cargos comemorativos no [servidor da UBL](url).
