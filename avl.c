/*
 Arvore AVL (Adelson Velskii e Landis) criada por eles em 1962
 Permite rebalanceamento local, apenas na parte afetada
 pela "inserção" ou "remoção", usando rotação simples ou dupla.
 
 A arvore AVL busca manter-se como uma arvore binária quase
 completa (balanceada) "quase cheia".
 
 Calculo: fator de balanceamento
 Custo do algoritmo máximo é O(logN).
 
 Fator de balanceamento ou fb:
 é a diferença nas alturas da sub-arvores esquerda e direita
 Se uma das sub-arvores não existir sua altura será -1.
 (é considerado -1 para o cálculo da altura e do balanço do nó PAI.)
 
 O fb deve ser +1, 0 ou -1 para ser uma arvore balanceada.
 Nó com fb desbalanceado é o pivô e precisa ser balanceado.
 
 Balanço de um nó = (h_e + 1) - (h_d + 1)
 Altura(P) = 1 + max(altura_subarvore_esquerda, altura_subarvore_direita)
 
 h_e -> é a altura da subárvore esquerda daquele nó
 h_d -> é a altura da subárvore direita daquele nó
 
 No contexto da árvore, usamos a função max() para 
 descobrir qual das duas subárvores (a da esquerda, 
 com altura h_e, ou a da direita, com altura h_d)
 é a mais alta. A mais alta é a que tem o maior valor de altura.
 
 A altura de um nó é o comprimento do caminho mais longo desse nó até uma folha
 A altura de uma árvore vazia (um filho que não existe, ou seja, um ponteiro NULL) é convencionada como -1
 Por definição, a altura de uma folha (um nó sem filhos) é 0
 A altura de um nó que não é folha é calculada como: 1 + a maior altura entre seus filhos.
 
 Altura de um Nó: É o comprimento do caminho mais longo daquele nó até uma folha. 
 A altura de um nó que existe pode ser 0, 1, 2, 3, 4, ..., ou seja, qualquer número 
 inteiro não negativo. É muito comum que a altura seja diferente de -1, 0 ou 1.
 
 Fator de Balanceamento de um Nó: É o resultado de um cálculo que usa as alturas 
 das duas subárvores filhas (h_e e h_d). Para a árvore ser considerada uma AVL, o 
 resultado desse cálculo deve, obrigatoriamente, ser -1, 0 ou 1.
 
 Exemplo: 
 A altura da sua subárvore esquerda (nó 10) é h_e = 0.
 A altura da sua subárvore direita (nó 40) é h_d = 2.
 Fator de Balanceamento = (h_e + 1) - (h_d + 1) = (0 + 1) - (2 + 1) = 1 - 3 = -2.
 Fator de Balanceamento -2 que torna o nó 20 "desregulado" e dispara a necessidade de rebalancear a árvore
 
  
Rotação RR (RIGHT RIGHT)
Quando o nó é inserido 2x na direita.
> para balancear é necessário uma rotação simples à esquerda
 
 A					 B
  \					/ \
   B		--->   A   C
    \
     C
  
Rotação LL (Left Left)
Quando o nó é adicionado 2x na esquerda.
> para balancear é necessário uma rotação simples à direita
 
	 A			   B
	/			  / \
   B	   --->  A	 C
  /
 C
 
Rotação RL ou Rotação dupla à esquerda
O nó é inserido na direita depois na esquerda
> para balancear precisa fazer uma rotação LL e depois uma RR

Rotação LR ou Rotação dupla à direita 
O nó é inserido na esquerda depois na esquerda
> para balancear precisar fazer uma rotação RR e depois LL

Quando usar cada rotação?

Cosiderando C filho do no B, e B filho do nó A
se o fb for:

A +2 e B +1 -> LL
A -2 e B -1 -> RR
A +2 e B -1 -> LR
A -2 e B +1 -> RL
 
As rotações são aplicadas no ancestral mais proximo do nó inserido cujo
fb passa a ser +2 ou -2

Esse é o parametro das funções implementadas.
As rotações simples (LL e RR) atualizam as novas alturas das sub-arvores.
As rotações duplas (LR e RL) podem ser implementadas com 2 rotações simples.
 
 */
 
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do Nó AVL
typedef struct AVL_NO No;

struct AVL_NO {
	int chave;
	No* p_pai; // O campo pai não é estritamente necessário para a lógica de inserção e rotação recursiva, mas mantê-lo pode ser útil para outras operações.
	No* p_filho_esquerdo;
	No* p_filho_direito;
	int altura;
	int fb; // Fator de balanceamento
};

// ======================
// FUNÇÕES AUXILIARES
// ======================

// Função para retornar a altura de um nó (retorna -1 se o nó for NULL)
// Isso simplifica os cálculos e evita bugs.
int AlturaNo(No* no)
{
	if (no == NULL) {
		return -1;
	}
	return no->altura;
}

// Retorna o maior entre dois inteiros
int max(int HE, int HD) {
	return (HE > HD) ? HE : HD;
}

// Função para criar e inicializar um novo nó
No* criar_no(int chave) {
	No* novo_no = (No*)malloc(sizeof(No));
	if (novo_no == NULL) {
		printf("Erro de alocação de memória!\n");
		exit(1);
	}
	novo_no->chave = chave;
	novo_no->p_filho_esquerdo = NULL;
	novo_no->p_filho_direito = NULL;
	novo_no->p_pai = NULL;
	novo_no->altura = 0;
	novo_no->fb = 0;
	return novo_no;
}

// =========================================================================
// FUNÇÕES DE ROTAÇÃO
// =========================================================================
// As rotações são o coração da AVL. Elas rearranjam a árvore para restaurar
// o balanceamento. As funções de rotação devem retornar a nova raiz da
// subárvore que foi rotacionada.

// Rotação simples à direita (LL)
// Esta rotação é usada quando a subárvore esquerda do nó desbalanceado
// é muito "pesada" e a inserção ocorreu no filho esquerdo dele.
No* RodarLL(No* no_desbalanceado) {
	No* novo_no = no_desbalanceado->p_filho_esquerdo;
	
	// A subárvore direita do novo nó se torna a subárvore esquerda do nó desbalanceado
	no_desbalanceado->p_filho_esquerdo = novo_no->p_filho_direito;

	// O nó desbalanceado se torna o filho direito do novo nó
	novo_no->p_filho_direito = no_desbalanceado;

	// Atualiza os pais (se necessário)
	// (Lógica de pai não implementada aqui para simplificar, mas seria necessário se fosse usada)
	
	// Recalcula as alturas dos nós afetados (de baixo para cima)
	no_desbalanceado->altura = 1 + max(AlturaNo(no_desbalanceado->p_filho_esquerdo), AlturaNo(no_desbalanceado->p_filho_direito));
	novo_no->altura = 1 + max(AlturaNo(novo_no->p_filho_esquerdo), AlturaNo(novo_no->p_filho_direito));
	
	return novo_no; // Retorna o novo nó que é a raiz da subárvore
}

// Rotação simples à esquerda (RR)
// Usada quando a subárvore direita do nó desbalanceado é "pesada"
// e a inserção ocorreu no filho direito dele.
No* RodarRR(No* no_desbalanceado) {
	No* novo_no = no_desbalanceado->p_filho_direito;
	
	no_desbalanceado->p_filho_direito = novo_no->p_filho_esquerdo;
	novo_no->p_filho_esquerdo = no_desbalanceado;
	
	// Recalcula as alturas
	no_desbalanceado->altura = 1 + max(AlturaNo(no_desbalanceado->p_filho_esquerdo), AlturaNo(no_desbalanceado->p_filho_direito));
	novo_no->altura = 1 + max(AlturaNo(novo_no->p_filho_esquerdo), AlturaNo(novo_no->p_filho_direito));
	
	return novo_no;
}

// Rotação dupla esquerda-direita (LR)
// É uma combinação de uma rotação à esquerda no filho esquerdo, seguida de uma rotação à direita no nó desbalanceado.
No* RodarLR(No* no_desbalanceado) {
	no_desbalanceado->p_filho_esquerdo = RodarRR(no_desbalanceado->p_filho_esquerdo);
	return RodarLL(no_desbalanceado);
}

// Rotação dupla direita-esquerda (RL)
// É uma combinação de uma rotação à direita no filho direito, seguida de uma rotação à esquerda no nó desbalanceado.
No* RodarRL(No* no_desbalanceado) {
	no_desbalanceado->p_filho_direito = RodarLL(no_desbalanceado->p_filho_direito);
	return RodarRR(no_desbalanceado);
}

// ===============================
// FUNÇÃO PRINCIPAL DE INSERÇÃO
// ===============================

// Esta é a função principal de inserção em uma AVL.
// A lógica recursiva é perfeita para isso.
No* InserirNo(No* p_raiz, int chave) {
	// 1. Caso base: Se a raiz for NULL, cria um novo nó e retorna.
	if (p_raiz == NULL) {
		return criar_no(chave);
	}
	
	// 2. Inserção recursiva (lógica de ABB)
	if (chave < p_raiz->chave) {
		p_raiz->p_filho_esquerdo = InserirNo(p_raiz->p_filho_esquerdo, chave);
	} else if (chave > p_raiz->chave) {
		p_raiz->p_filho_direito = InserirNo(p_raiz->p_filho_direito, chave);
	} else {
		// Chave já existe, não faz nada e retorna a raiz atual
		return p_raiz;
	}
	
	// 3. Atualiza a altura do nó atual (o nó que a função está retornando)
	p_raiz->altura = 1 + max(AlturaNo(p_raiz->p_filho_esquerdo), AlturaNo(p_raiz->p_filho_direito));
	
	// 4. Calcula o Fator de Balanceamento do nó atual
	p_raiz->fb = AlturaNo(p_raiz->p_filho_esquerdo) - AlturaNo(p_raiz->p_filho_direito);
	
	// 5. Verifica se há desbalanceamento e aplica as rotações
	
	// Caso LL: Inserção na subárvore esquerda do filho esquerdo
	if (p_raiz->fb > 1 && chave < p_raiz->p_filho_esquerdo->chave) {
		return RodarLL(p_raiz);
	}
	
	// Caso RR: Inserção na subárvore direita do filho direito
	if (p_raiz->fb < -1 && chave > p_raiz->p_filho_direito->chave) {
		return RodarRR(p_raiz);
	}
	
	// Caso LR: Inserção na subárvore direita do filho esquerdo
	if (p_raiz->fb > 1 && chave > p_raiz->p_filho_esquerdo->chave) {
		return RodarLR(p_raiz);
	}
	
	// Caso RL: Inserção na subárvore esquerda do filho direito
	if (p_raiz->fb < -1 && chave < p_raiz->p_filho_direito->chave) {
		return RodarRL(p_raiz);
	}

	// 6. Retorna a raiz da subárvore (pode ser a mesma ou a nova)
	return p_raiz;
}

// =====================
// FUNÇÕES DE PERCURSO
// =====================

// As suas funções de percurso já estão corretas e são ideais para visualizar a árvore.
void ProcessarPreOrdem(No* p_raiz) {
	if (p_raiz != NULL) {
		printf("%d ", p_raiz->chave);
		ProcessarPreOrdem(p_raiz->p_filho_esquerdo);
		ProcessarPreOrdem(p_raiz->p_filho_direito);
	}
}

void ProcessarOrdemSimetrica(No* p_raiz) {
	if(p_raiz != NULL) {
		ProcessarOrdemSimetrica(p_raiz->p_filho_esquerdo);
		printf("%d ", p_raiz->chave);
		ProcessarOrdemSimetrica(p_raiz->p_filho_direito);
	}
}

void ProcessarPosOrdem(No* p_raiz) {
	if (p_raiz != NULL) {
		ProcessarPosOrdem(p_raiz->p_filho_esquerdo);
		ProcessarPosOrdem(p_raiz->p_filho_direito);
		printf("%d ", p_raiz->chave);
	}
}

void ProcessarComFb(No* p_raiz) {
	if(p_raiz != NULL) {
		ProcessarComFb(p_raiz->p_filho_esquerdo);
		printf("Chave: %d Fb: %d Altura: %d\n", p_raiz->chave, p_raiz->fb, p_raiz->altura);
		ProcessarComFb(p_raiz->p_filho_direito);
	}
}

// =======
// 	MAIN
// =======
int main()
{
	No* p_raiz = NULL; // A raiz deve começar como NULL

	// Inserindo chaves para testar as rotações
	printf("Inserindo 10...\n");
	p_raiz = InserirNo(p_raiz, 10);
	
	printf("Inserindo 20...\n");
	p_raiz = InserirNo(p_raiz, 20);
	
	printf("Inserindo 30 (vai causar uma rotacao RR)...\n");
	p_raiz = InserirNo(p_raiz, 30); // Causa rotação RR

	printf("\nArvore apos insercoes:\n");
	ProcessarComFb(p_raiz); // Agora vai exibir os fatores de balanceamento corretos
	
	printf("\nPercurso em Ordem Simetrica: ");
	ProcessarOrdemSimetrica(p_raiz); // Deve imprimir 10 20 30

	// Exemplo de uma inserção que causa rotação LL
	p_raiz = NULL;
	printf("\n\nResetando arvore. Inserindo 30, 20, 10...\n");
	p_raiz = InserirNo(p_raiz, 30);
	p_raiz = InserirNo(p_raiz, 20);
	p_raiz = InserirNo(p_raiz, 10); // Causa rotação LL

	printf("\nArvore apos insercoes:\n");
	ProcessarComFb(p_raiz);
	
	// Exemplo de LR e RL
	p_raiz = NULL;
	printf("\n\nResetando arvore. Inserindo 30, 10, 20...\n");
	p_raiz = InserirNo(p_raiz, 30);
	p_raiz = InserirNo(p_raiz, 10);
	p_raiz = InserirNo(p_raiz, 20); // Causa rotação LR

	printf("\nArvore apos insercoes:\n");
	ProcessarComFb(p_raiz);
	
	return 0;
}
