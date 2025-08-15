#include <stdio.h>
#include <stdlib.h> // Para malloc

// A razão pela qual usamos ponteiros na definição da 
// struct é para permitir a auto-referência de forma 
// indireta e a alocação dinâmica de memória.

typedef struct No No;

struct No {
	int key;
	No* No_Esquerdo; // Ponteiro para o No Esquerdo (Guarda o endereço de memória de outro nó)
	No* No_Direito;  // Ponteiro para o No Direito (Possibilita a compilação e serve de "caso base")
	No* No_Pai;
};

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
			printf("Chave: %d", raiz->key); // Processa a raiz
		}
}

// Buscar No

// Procurando uma chave: Começando pela raiz, se for igual achou, se for menor
// vai para a sub arvore esquerda, caso maior vai para a sub arvore direita
// se chegar em NULL, a chave não existe.

// Usando ponteiro no argumento para mudar o valor da variável, e não
// usar uma variável temporario do escopo da função.

// Raiz para pegar o inicio da arvore e a chave buscada.
No* buscar_no(No* raiz, int key){
	No* no_buscado = NULL;
	
	if (raiz == NULL){
		printf("Null\n");
		}
		
	else {
			if(raiz->key == key) {
			no_buscado = raiz;
			}
			
			else if (key > raiz->key) {
			no_buscado = buscar_no(raiz->No_Direito, key);
			}
			
			else if (key < raiz->key) {
			no_buscado = buscar_no(raiz->No_Esquerdo, key);
			}
		}
	return no_buscado;
}

/*
 
Função Inserir
Por que retornar um ponteiro No* também?
Retornar um No* é uma técnica comum em C para lidar com modificações. 
A função retorna o endereço da (possivelmente nova) raiz da subárvore 
que ela acabou de processar. Isso é especialmente útil em árvores AVL, 
onde uma rotação pode mudar completamente qual nó é a raiz de uma 
determinada subárvore.
 */
 
// Função para inserir um nó em uma ABB
No* inserir(No* raiz, int key) {
    // Se a árvore está vazia, retorna um novo nó
    if (raiz == NULL) {
        return criarNo(key);
    }

    // Se a chave a ser inserida é menor, insere na subárvore esquerda
    if (key < raiz->key) {
        raiz->No_Esquerdo = inserir(raiz->No_Esquerdo, key);
    } 
    // Se a chave a ser inserida é maior, insere na subárvore direita
    else if (key > raiz->key) {
        raiz->No_Direito = inserir(raiz->No_Direito, key);
    }

    // Retorna o ponteiro da raiz (sem alterações se a chave já existir)
    return raiz;
}

void exibir_arvore(No* No_Pai)
{
	if(No_Pai != NULL)
	{
		if(No_Pai->No_Esquerdo != NULL && No_Pai->No_Direito != NULL)
		{
			printf("%d: %d %d ", No_Pai->key, No_Pai->No_Esquerdo->key, No_Pai->No_Direito->key);
		}
		else if (No_Pai->No_Esquerdo != NULL && No_Pai->No_Direito == NULL) 
		{
			printf("%d: %d - ", No_Pai->key, No_Pai->No_Esquerdo->key);
		}
		else if (No_Pai->No_Esquerdo == NULL && No_Pai->No_Direito != NULL)
		{
			printf("%d: - %d ", No_Pai->key, No_Pai->No_Direito->key);			
		}
		else
		{
			printf("%d: - - ", No_Pai->key);
		}
		
		// Impressão do pai (ou "-" se for a raiz)
		
		if(No_Pai->No_Pai != NULL)
		{
			printf("| %d\n", No_Pai->No_Pai->key);
		}
		else
		{
			printf("| -\n");
		}
		
		// Exibir os filhos
		exibir_arvore(No_Pai->No_Esquerdo);
		exibir_arvore(No_Pai->No_Direito);
	}
}

// CRIAR A RAIZ
No* criar_arvore(int new_key)
{
	No* novo_no = (No*) malloc(sizeof(No));
	novo_no->key = new_key;
	novo_no->No_Esquerdo = NULL;
	novo_no->No_Direito = NULL;
	novo_no->No_Pai = NULL;
	return novo_no;
}

void inserir_em_arvore_nao_vazia(No* raiz, int new_key) {

	if (raiz == NULL) {
		printf("Arvora nao esta vazia");
	}
	else if (new_key == raiz->key) {
		printf("Chave já existente");
	}
	else if (new_key < new_key) {
		// INSERÇÃO DEVE OCORRER A ESQUERDA
		if(raiz->No_Esquerdo == NULL) {
			// CRIAR NO 
			No* novo_no  = (No*) malloc(sizeof(No));
			novo_no->key = new_key;
			novo_no->No_Esquerdo = NULL;
			novo_no->No_Direito = NULL;
			novo_no->No_Pai = raiz;
			raiz->No_Esquerdo = novo_no;
		}
		else {
			// Chamada recursiva para inserir nó na subarvore esquerda
			inserir_em_arvore_nao_vazia(raiz->No_Esquerdo, new_key);
		}
	}
	else{
		//INSERÇÃO DEVE OCORRER A DIREITA
		if(raiz->No_Direito == NULL){
			No* novo_no = (No*) malloc(sizeof(No));
			novo_no->No_Esquerdo = NULL;
			novo_no->No_Direito = NULL;
			raiz->No_Direito = novo_no;
			novo_no->key = new_key;
			novo_no->No_Pai = raiz;
		}
		else{
			// Chamada recursiva para inserir no na subarvore direita
			inserir_em_arvore_nao_vazia(raiz->No_Direito, new_key);
		}
	}	
}

int main() {
	
	// Criar raiz da arvore
	No* p_raiz = criar_arvore(10);
	
	// Inserção de chavees

	inserir_em_arvore_nao_vazia(p_raiz, 20);
	inserir_em_arvore_nao_vazia(p_raiz, 17);
	inserir_em_arvore_nao_vazia(p_raiz, 1);
	inserir_em_arvore_nao_vazia(p_raiz, 8);
	inserir_em_arvore_nao_vazia(p_raiz, 12);
	inserir_em_arvore_nao_vazia(p_raiz, 14);
	inserir_em_arvore_nao_vazia(p_raiz, 15);
	inserir_em_arvore_nao_vazia(p_raiz, 16);

	// Realizar os 3 tipos de percuso

	return 0;
}

