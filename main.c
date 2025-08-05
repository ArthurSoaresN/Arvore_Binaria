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
	
	
	}






int main() {
	
	return 0;
}

