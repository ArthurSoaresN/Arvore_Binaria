#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 31

// Zera todos os indices da tabela
void IniciarTabela(int tabela[]) {
	for (int i = 0; i < TAMANHO; i++){
		// Ponto 1: Faltava um ponto e vírgula aqui
		tabela[i] = 0;
	}
}

int FunctionHash(int chave) {
	return chave % TAMANHO;
}

void inserir(int tabela[], int valor){
	int id = FunctionHash(valor);
	
	// Ponto 2: Parêntese no lugar errado e operador de comparação incorreto
	while(tabela[id] != 0) {
		id = FunctionHash(id + 1);
	}
	tabela[id] = valor;
}

int busca (int tabela[], int chave) {
	int id = FunctionHash(chave);
	// Ponto 3: O operador de comparação deve ser '!='
	while(tabela[id] != 0) {
		if(tabela[id] == chave){
			return tabela[id];
		}
		else {
			id = FunctionHash(id + 1);
		}
	}
	// Ponto 4: Faltava um ponto e vírgula aqui
	return 0;
}

void ImprimirTabela(int tabela[]) {
	for (int i = 0; i < TAMANHO; i++) {
		// Ponto 5: O formatador de string para o segundo valor deve ser '%d', não 'd%'
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
		// Ponto 6: Corrigido o erro de digitação "Sairz" para "Sair"
		printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				// Ponto 7: Parêntese fora das aspas removido
				printf("Digite o valor que deseja inserir:\n");
				scanf("%d", &valor);
				inserir(tabela, valor);
			case 2:
				// Ponto 8: Parêntese fora das aspas removido
				printf("Digite o valor que deseja buscar:\n");
				scanf("%d", &valor);
				retorno = busca(tabela, valor);
				if(retorno != 0){
					printf("Valor Encontrado: %d\n", retorno);
				}
				else {
					printf("Valor nao encontrado\n");
				}
			case 3:
				ImprimirTabela(tabela);
			default:
				printf("Opcao Invalida\n");
		}
	} while (opcao != 0);
	
	return 0;
}
