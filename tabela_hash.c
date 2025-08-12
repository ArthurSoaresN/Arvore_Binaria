#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 31

// Zera todos os indices da tabela
void IniciarTabela(int tabela[]) {
	for (int i = 0; i < TAMANHO; i++){
			tabela[i] = 0
		}
}

int FunctionHash(int chave) {
	return chave % TAMANHO;
}

void inserir(int tabela[], int valor){
	int id = FunctionHash(valor);
	
	while(tabela[id]) != 0) {
		id = FunctionHash(id + 1);
	}
	tabela[id] = valor;
}

int busca (int tabela[], int chave) {
	int id = FunctionHash(chave);
	while(tabela[id] = !0) {
		if(tabela[id] == chave){
			return tabela[id];
		}
		else {
			id = FunctionHash(id + 1);
		}
	}
}

int main()
{
	// M = 2 * numero de elementos -> Número primo mais próximo;
	// 2*15 = 30 -> M = 31
	int tabela[TAMANHO]; 
	
	return 0;
}

