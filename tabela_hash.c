#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 31

// Zera todos os indices da tabela
void IniciarTabela(int tabela[]) {
	for (int i = 0; i < TAMANHO; i++){
		tabela[i] = 0;
	}
}

int FunctionHash(int chave) {
	return chave % TAMANHO;
}

void inserir(int tabela[], int valor){
	int id = FunctionHash(valor);

	while(tabela[id] != 0) {
		id = FunctionHash(id + 1);
	}
	tabela[id] = valor;
}

int busca (int tabela[], int chave) {
	int id = FunctionHash(chave);
	while(tabela[id] != 0) {
		if(tabela[id] == chave){
			return tabela[id];
		}
		else {
			id = FunctionHash(id + 1);
		}
	}
	return 0;
}

void ImprimirTabela(int tabela[]) {
	for (int i = 0; i < TAMANHO; i++) {
		printf("%d = %d\n", i, tabela[i]);
	}
}

int main()
{
	// M = 2 * numero de elementos -> Número primo mais próximo;
	// 2*15 = 30 -> M = 31
	int tabela[TAMANHO];
	int opcao;
	int valor;
	int retorno;
	
	IniciarTabela(tabela);
	
	do{
		printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("Digite o valor que deseja inserir:\n");
				scanf("%d", &valor);
				inserir(tabela, valor);
			    break;
			case 2:
				printf("Digite o valor que deseja buscar:\n");
				scanf("%d", &valor);
				retorno = busca(tabela, valor);
				if(retorno != 0){
					printf("Valor Encontrado: %d\n", retorno);
				}
				else {
					printf("Valor nao encontrado\n");
				}
			    break;
			case 3:
				ImprimirTabela(tabela);
			    break;
			default:
				printf("Opcao Invalida\n");
		}
	} while (opcao != 0);
	
	return 0;
}
