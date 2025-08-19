 /*
* Este código-fonte é baseado em uma implementação
* elaborada pelo professor e pelos alunos na aula do dia 12/08/2025.
* Trata-se de uma implementação de uma tabela de dispersão
* cuja função de dispersão é h(x) = x % m
* As seguintes operações são contempladas:
* criar uma tabela de dispersão;
* imprimir a tabela;
* inserir elemento na tabela;
* buscar elemento na tabela.
* Versão 1.
*/

#include <stdio.h>
#include <stdlib.h>

// Definição do tipo No como um apelido para struct meu_registro
typedef struct meu_registro No;

// Estrutura de um elemento da tabela de dispersão
struct meu_registro
{
	int chave;        // Valor armazenado no nó
	No* p_proximo;    // Ponteiro para o próximo nó (usado em caso de colisão — encadeamento)
};

// Função que cria e inicializa a tabela de dispersão
// Parâmetro: tamanho — número de posições da tabela
// Retorno: ponteiro para a tabela criada
No* criar_tabela(int tamanho)
{
	// Aloca memória para o vetor de registros (um para cada posição da tabela de dispersão).
	No* tabela_hash = (No*) malloc(tamanho * sizeof(No));
	
	// Inicializa cada posição como vazia
	for (int i = 0; i < tamanho; i++)
	{
		tabela_hash[i].chave = -1;         // -1 indica posição livre
		tabela_hash[i].p_proximo = NULL;   // Nenhum nó encadeado
	}
	
	return tabela_hash;
}

// Função que imprime a tabela de dispersão
// Percorre cada posição e, se houver encadeamento, imprime todos os elementos
void imprimir_tabela(No* tabela_hash, int tamanho)
{
	for(int i = 0; i < tamanho; i++)
	{
		printf("%d: ", i);
		No* atual = &tabela_hash[i];       // Começa pelo nó da posição i
		while(atual != NULL)
		{
			printf("%d ", atual->chave);   // Imprime chave do nó atual
			atual = atual->p_proximo;      // Avança para o próximo nó (se houver)
		}
		printf("\n");
	}
	printf("\n");
}

// Função que insere um elemento na tabela de dispersão
// Parâmetros:
// - tabela_hash: ponteiro para a tabela
// - m: tamanho usado na função de dispersão (módulo)
// - nova_chave: valor a ser inserido
void inserir_elemento(No* tabela_hash, int m, int nova_chave)
{
	int indice = nova_chave % m;  // Calcula posição usando h(x) = x % m
	
	// Caso a posição esteja livre
	if(tabela_hash[indice].chave == -1)
	{
		tabela_hash[indice].chave = nova_chave;
	}
	else // Caso haja colisão, insere no final da lista encadeada
	{
		No* atual = &tabela_hash[indice];
		
		// Percorre até encontrar o último nó
		while(atual->p_proximo != NULL)
		{
			atual = atual->p_proximo;
		}
		
		// Cria novo nó e insere após o último
		No* novo_no = (No*) malloc(sizeof(No));
		novo_no->chave = nova_chave;
		novo_no->p_proximo = NULL;
		atual->p_proximo = novo_no;
	}
}

// Função que busca um elemento na tabela de dispersão
// Retorna ponteiro para o nó se encontrado, ou NULL caso contrário
No* buscar_elemento(No* tabela_hash, int m, int chave)
{
    int indice = chave % m;     // Calcula índice usando função de dispersão
    No* atual = &tabela_hash[indice];

    // Percorre lista encadeada na posição calculada
    while (atual != NULL)
    {
        if (atual->chave == chave)
		{
            return atual; // Chave encontrada
		}
        atual = atual->p_proximo;
    }
    
    return NULL; // Chave não encontrada
}

int main()
{
	int m = 7;  // Parâmetro para a função de dispersão (módulo)
	
	// Cria e imprime tabela inicial (vazia)
	No* tabela_hash = criar_tabela(m);
	imprimir_tabela(tabela_hash, m);
	
	// Insere elementos na tabela
	inserir_elemento(tabela_hash, m, 21);
	inserir_elemento(tabela_hash, m, 9);
	inserir_elemento(tabela_hash, m, 10);
	inserir_elemento(tabela_hash, m, 5);
	inserir_elemento(tabela_hash, m, 20);
	inserir_elemento(tabela_hash, m, 14);
	inserir_elemento(tabela_hash, m, 3);
	inserir_elemento(tabela_hash, m, 17);
	
	// Imprime tabela após inserções
	imprimir_tabela(tabela_hash, m);
	
	// Busca elemento com chave 3
	No* elemento = buscar_elemento(tabela_hash, m, 3);
	if(elemento != NULL)
	{
		printf("%d\n", elemento->chave);
	}
	
	return 0;
}
