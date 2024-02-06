/* =============================================================================
 * ### main.c
 * Interface básica para testar minha solução do Problema 1.
 * By: anachan01h
 * ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char *argv[]) {
    extern uint64_t mochila_pd(uint64_t n, uint64_t max_w, uint64_t *w, uint64_t *v, uint64_t *table);
    extern char *slice(char *buf);
    uint64_t n, max_w, *w, *v, *table;
    FILE *fptr;
    char buf[256];
    int i;

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

    // Lê a primeira linha do arquivo, obtendo os valores de n e max_w
    fgets(buf, 256, fptr);
    max_w = atoi(slice(buf));
    n = atoi(buf);

    // Cria os arrays w e v, e carrega seus valores do arquivo
    w = malloc(n * sizeof(uint64_t));
    v = malloc(n * sizeof(uint64_t));
    for(i = 0; fgets(buf, 256, fptr); i++) {
        v[i] = atoi(slice(buf));
        w[i] = atoi(buf);
    }

    // Cria a tabela, para o algoritmo de programação dinâmica
    table = malloc((n + 1) * (max_w + 1) * sizeof(uint64_t));

    // Aplica o algoritmo, e exibe o resultado
    printf("%" PRIu64 "\n", mochila_pd(n, max_w, w, v, table));

    // Libera a memória alocada dinamicamente
    free(w);
    free(v);
    free(table);

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
