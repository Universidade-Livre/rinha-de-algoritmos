/* =============================================================================
 * ### main.c
 * Interface básica para testar minha solução do Problema 2.
 * By: anachan01h
 * ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char *argv[]) {
    extern uint64_t mcds(uint64_t n, uint8_t *graph, uint8_t *covered, uint8_t *cds);
    extern char *slice(char *buf);
    uint64_t n;
    uint8_t *graph, *covered, *cds;
    FILE *fptr;
    char buf[256];
    int i;
    uint64_t v, u;

    // Verifica se o programa recebeu apenas um argumento
    if(argc != 2) {
        printf("Erro: número de argumentos inválido!\n");
        return -1;
    }

    // Abre o arquivo
    fptr = fopen(argv[1], "r");
    if(fptr == NULL) {
        printf("Erro: não foi possível abrir o arquivo \"%s\".\n", argv[1]);
        return -1;
    }

    // Lê a primeira linha do arquivo, obtendo o valor de n
    fgets(buf, 256, fptr);
    slice(buf);
    n = atoi(buf);

    // Cria a matriz de adjacências do grafo, armazenada em graph
    graph = calloc(n * n, 1);
    for(i = 0; fgets(buf, 256, fptr); i++) {
        u = atoi(slice(buf)) - 1;
        v = atoi(buf) - 1;
        graph[v * n + u] = 1;
        graph[u * n + v] = 1;
    }

    // Cria os arrays covered e cds, utilizados no algoritmo
    covered = calloc(n, 1);
    cds = calloc(n, 1);

    // Aplica o algoritmo, e exibe o resultado
    printf("%" PRIu64 "\n", n - mcds(n, graph, covered, cds));

    // Libera a memória alocada dinamicamente
    free(cds);
    free(covered);
    free(graph);

    // Fecha o arquivo
    fclose(fptr);

    return 0;
}

// Pega uma linha do arquivo e separa os números, substituindo o espaço ou tab pelo caractere nulo
char *slice(char *buf) {
    int i;
    for(i = 0; i < 256; i++) {
        if(buf[i] == ' ' || buf[i] == '\t') {
            buf[i] = 0;
            break;
        }
    }
    return(buf + i + 1);
}
