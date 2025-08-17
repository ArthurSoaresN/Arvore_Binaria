#include <stdio.h>
#include <stdlib.h>

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
 
typedef struct AVL_NO No;

struct AVL_NO {
	int chave;
	No* p_pai;
	No* p_filho_esquerdo;
	No* p_filho_direito;
	int altura;
	int fb;
	};

No* criar_arvore(No* p_raiz, int chave, int* p_verificador)
{
	if (p_verificador == 1) {
		printf("Árvore já criada");
		return NULL;
		}
	
	else {
		p_raiz->chave = chave;
		p_raiz->p_filho_esquerdo = NULL;
		p_raiz->p_filho_direito = NULL;
		p_raiz->altura = 0; // altura(p) = 1+max(-1,-1) = 0
		p_raiz->fb = 0; // fb = (h_e + 1) - (h_d + 1)
		
		p_verificador = 1; // Raiz Criada
		return p_raiz;
		}
}

int CalcularAlturaDoNo(No* p_raiz, int chave)
{
	
}







int main()
{
	int verificador = 0;
	int* p_verificador = &verificador; 
	
	
	
	return 0;
}

