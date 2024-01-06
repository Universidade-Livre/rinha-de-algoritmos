/*
Adaptação da Heurística clássica, Branch and Bound, proposta por Gilmore e Gomory para o problema da mochila
Gilmore, Paul C., and Ralph E. Gomory. 
"A linear programming approach to the cutting stock problem—Part II." 
Operations research 11.6 (1963): 863-888.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Valores {
    int valor;
    int peso;
    float pi;
    int quantidadeDoItem;
} Valor;

// Funções utilizadas

void swap(Valor *itemA, Valor *itemB) {
    int peso = itemB->peso;
    int valor = itemB->valor;
    double pi = itemB->pi;
    double quantidadeDoItem = itemB->quantidadeDoItem;

    itemB->peso = itemA->peso;
    itemB->valor = itemA->valor;
    itemB->pi = itemA->pi;
    itemB->quantidadeDoItem = itemA->quantidadeDoItem;

    itemA->peso = peso;
    itemA->valor = valor;
    itemA->pi = pi;
    itemA->quantidadeDoItem = quantidadeDoItem;
}

int partition(Valor *vetor, int low, int high) {
    int pivot = vetor[low].pi;
    int i = (high + 1), j = 0;

    for (j = high; j > low; j--) {
        if (vetor[j].pi <= pivot) {
            i--;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[i - 1], &vetor[low]);
    return (i - 1);
}

void quickSort(Valor *vetor, int low, int high) {
    if (low < high) {
        int p = partition(vetor, low, high);
        quickSort(vetor, low, p - 1);
        quickSort(vetor, p + 1, high);
    }
}

// Passo 2
void primeira_solucao(Valor *vetor, int tam_vetor, int tam_mochila, int melhor_mochila) {
    int i = 0;
    int L = tam_mochila; 

    for (i = 0; i < tam_vetor; i++) {
        vetor[i].quantidadeDoItem = (div(L, vetor[i].peso)).quot;
        if (vetor[i].quantidadeDoItem > 1) {
        	vetor[i].quantidadeDoItem = 1;
        }
        L = L - (vetor[i].quantidadeDoItem * vetor[i].peso);            
    }
}

// Passo 3
int calcular_valor_da_mochila(Valor *vetor, int tam_vetor, int melhor_mochila) {
    int valor_dessa_mochila = 0;
    int i = 0;

    // Passo 3.1 
    for (i = 0; i < tam_vetor; i++) {
        valor_dessa_mochila += vetor[i].valor * vetor[i].quantidadeDoItem;
    }

    // Passo 3.2
    if( melhor_mochila < valor_dessa_mochila) {
        return valor_dessa_mochila;
    } 
    return melhor_mochila;
}

/**
    Passo 4.1
    Encontrando o maior indice diferente de 0
    Retorna -1 caso todos os valores forem 0
    Se retornar -1 significa que a melhor mochila foi encontrada
 */
int encontra_maior_indice(Valor *vetor, int tam_vetor) {
	int i = tam_vetor - 1;
	
    // Backtracking
    for (i; i >= 0; i--) {
        if(vetor[i].quantidadeDoItem != 0) {
            return i;
        }
    }

    return -1;
}

//Passo 4.2

float calcula_limitante_da_mochila(Valor *vetor, int tam_vetor, int tam_mochila, int indice_r) {
    float limitante_superior = 0;
    int parte_conhecida = 0;
    float pi_proximo_item = 0;
    int parte_desconhecida = tam_mochila;
    int i = 0;

    // Adiciona o valor de pi do proximo item
    // Caso nao tenha um proximo item o valor atribuido é zero
    if(tam_vetor >= (indice_r + 1)) {
         pi_proximo_item = vetor[indice_r + 1].pi; 
    } 
    else { 
        pi_proximo_item = 0;
    }

    for (i = 0; i < indice_r; i++) {
        parte_conhecida += vetor[i].valor * vetor[i].quantidadeDoItem;
        parte_desconhecida -= (vetor[i].quantidadeDoItem * vetor[i].peso); 
    }

    // Adiciona valores da posicao R
    parte_conhecida +=  vetor[indice_r].valor * (vetor[indice_r].quantidadeDoItem - 1);
    parte_desconhecida -= ((vetor[indice_r].quantidadeDoItem - 1)* vetor[indice_r].peso); 
	
    limitante_superior = parte_conhecida + pi_proximo_item * parte_desconhecida;

    return limitante_superior;
}

void nova_solucao(Valor *vetor, int tam_vetor, int tam_mochila, int melhor_mochila, int indice_r) {
    int i = indice_r;
    int L = tam_mochila; 

    for (i = 0; i < tam_vetor; i++) {
        L = L - (vetor[i].quantidadeDoItem * vetor[i].peso);
    }
	for (i = indice_r + 1; i < tam_vetor; i++) {
		vetor[i].quantidadeDoItem = (div(L, vetor[i].peso)).quot;
		if (vetor[i].quantidadeDoItem > 1) {
			vetor[i].quantidadeDoItem = 1;
		}
        L = L - (vetor[i].quantidadeDoItem * vetor[i].peso);
    }
}

void gerar_vetor_solucao(Valor *vetor,int * vetor_solucao, int tam_vetor){
	int i;
	for(i = 0; i < tam_vetor; i++){
		vetor_solucao[i] = vetor[i].quantidadeDoItem;
	}
}

int main(int argc, char *argv[]) {
    int num_elements, knapsack_size;
	int melhor_mochila = 0;
	float limitante_superior;
	int indice_r;

	FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1;
    }

    if(fscanf(file, "%d", &num_elements));
    if(fscanf(file, "%d", &knapsack_size));

    Valor *vet_elemento = (Valor*)malloc(num_elements * sizeof(Valor));
	int * vetor_solucao = (int*)malloc(num_elements * sizeof(int));

    if (vet_elemento == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return 1;
    }

    for (int i = 0; i < num_elements; ++i) {
        if(fscanf(file, "%d %d", &vet_elemento[i].peso, &vet_elemento[i].valor));
        vet_elemento[i].pi = vet_elemento[i].valor / vet_elemento[i].peso;
        vet_elemento[i].quantidadeDoItem = 0; 
    }

    // QuickSort (Decrescente por pi)
    quickSort(vet_elemento, 0, num_elements - 1);
	
    // Calculando a primeira solução para o problema
    primeira_solucao(vet_elemento, num_elements, knapsack_size, melhor_mochila);
	
    // Passo 3 
	melhor_mochila = calcular_valor_da_mochila(vet_elemento, num_elements,  melhor_mochila); // G(x)
	gerar_vetor_solucao(vet_elemento,vetor_solucao,num_elements);
	
	// Passo 4.1
	// Encontra o maior indice diferente de 0
	// Se retornar -1, significa que todos os valores sao 0 e a melhor mochila ja foi encontrada
	indice_r = encontra_maior_indice(vet_elemento, num_elements);
	limitante_superior = 0;
	
    //  Passo 4.2
	if(indice_r != -1)
		limitante_superior = calcula_limitante_da_mochila(vet_elemento, num_elements, knapsack_size, indice_r);
	
	//	Passo 5	
	while(indice_r != -1) {
		if(limitante_superior <= melhor_mochila){
			vet_elemento[indice_r].quantidadeDoItem = 0;
			//	Backtrack do passo 4
			indice_r = encontra_maior_indice(vet_elemento, num_elements);
			if(indice_r != -1)
				limitante_superior = calcula_limitante_da_mochila(vet_elemento, num_elements, knapsack_size, indice_r);
		} else {
			//	Backtrack do passo 3
			vet_elemento[indice_r].quantidadeDoItem--;
			nova_solucao(vet_elemento, num_elements, knapsack_size, melhor_mochila, indice_r);
			melhor_mochila = calcular_valor_da_mochila(vet_elemento, num_elements,  melhor_mochila);
			gerar_vetor_solucao(vet_elemento,vetor_solucao,num_elements);
			// Passo 4
			indice_r = encontra_maior_indice(vet_elemento, num_elements);
			if(indice_r != -1)
				limitante_superior = calcula_limitante_da_mochila(vet_elemento, num_elements, knapsack_size, indice_r);
		}
	}
    printf("Solução viável encontrada: %d\n", melhor_mochila);

	free(vet_elemento);
	free(vetor_solucao);

    return 0;
}
