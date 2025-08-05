#include <stdio.h>
#include <stdlib.h> // Para malloc

// A razão pela qual usamos ponteiros na definição da 
// struct é para permitir a auto-referência de forma 
// indireta e a alocação dinâmica de memória.

typedef struct {
	int key;
	No* No_Esquerdo; // Ponteiro para o No Esquerdo (Guarda o endereço de memória de outro nó)
	No* No_Direito;  // Ponteiro para o No Direito (Possibilita a compilação e serve de "caso base")
} No;

// Função para criar um novo No

// Tipo retorno -> No
No* criarNo (int key) {
	
	No* novo_no = (No*)malloc(sizeof(No)); // Cast para malloc + size
	
	if (novo_no == NULL) {
		printf("Memory Error\n");
		exit(1);
	}
	
	novo_no->key = key;
	novo_no->No_Esquerdo = NULL; // Um novo nó começa sem filhos
	novo_no->No_Direito = NULL;
	
	return novo_no;
	
	}
	
// Percursos em Árvores Binárias

// Pré-Ordem (Raiz -> Esquerda -> Direita)

void PreOrdem(No* raiz){
	if (raiz != NULL) {
		printf("Chave: %d", raiz->key);
		PreOrdem(raiz->No_Esquerdo);
		PreOrdem(raiz->No_Direito);
	}
}

// Ordem Simetrica (Esquerda -> Raiz -> Direita)

void OrdemSimetrica(No* raiz){
	if(raiz != NULL){
		OrdemSimetrica(raiz->No_Esquerdo); // Percorre a subarvore esquerda
		printf("Chave: %d", raiz->key); // Processa a raiz
		OrdemSimetrica(raiz->No_Direito); // Percorre a subarvore direita
		}
	}

// Pos Ordem (Esquerda -> Direita -> Raiz)

void PosOrdem(No* raiz) {
	if (raiz != NULL) {
			PosOrdem(raiz->No_Esquerdo); // Percorre a subarvora esquerda
			PosOrdem(raiz->No_Direito); // Percorre a subarvore direita
			printf("Chave: %d", raiz->key) // Processa a raiz
	}
}

// Buscar No

// Procurando uma chave: Começando pela raiz, se for igual achou, se for menor
// vai para a sub arvore esquerda, caso maior vai para a sub arvore direita
// se chegar em NULL, a chave não existe.


int main() {
	
	return 0;
}

