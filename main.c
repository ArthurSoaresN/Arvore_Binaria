#include <stdio.h>
#include <stdlib.h> // Para malloc

// A razão pela qual usamos ponteiros na definição da 
// struct é para permitir a auto-referência de forma 
// indireta e a alocação dinâmica de memória.

typedef struct {
	int key;
	No* No_Esquerdo;
	No* No_Direito;
} No;



int main() {
	
	return 0;
}

