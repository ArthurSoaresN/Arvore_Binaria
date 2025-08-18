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
		printf("Arvore já criada\n");
		return NULL;
		}
	
	else {
		p_raiz->chave = chave;
		p_raiz->p_filho_esquerdo = NULL;
		p_raiz->p_filho_direito = NULL;
		p_raiz->altura = 0; // altura(p) = 1+max(-1,-1) = 0
		p_raiz->fb = 0; // fb = (h_e + 1) - (h_d + 1)
		
		p_verificador = 1; // Raiz Criada
		printf("Arvore criada! Raiz de chave: %d\n", p_raiz->chave);
		return p_raiz;
		}
}

void ProcessarPreOrdem (No* p_raiz)
{
	if (p_raiz != NULL) {
		printf("%d ", p_raiz->chave);
		ProcessarPreOrdem(p_raiz->p_filho_esquerdo);
		ProcessarPreOrdem(p_raiz->p_filho_direito); 
	}
}

void ProcessarOrdemSimetrica (No* p_raiz)
{
	if(p_raiz != NULL) {
		ProcessarOrdemSimetrica(p_raiz->p_filho_esquerdo);
		printf("%d ", p_raiz->chave);
		ProcessarOrdemSimetrica(p_raiz->p_filho_direito);
	}
}

void ProcessarPosOrdem (No* p_raiz) 
{
		if (p_raiz != NULL) {
			ProcessarPosOrdem(p_raiz->p_filho_esquerdo);
			ProcessarPosOrdem(p_raiz->p_filho_direito);
			printf("%d ", p_raiz->chave);
		}
}

int AlturaNo(No* no)
{
	if (no == NULL){
		return 0;
	}
	else {
		return no->altura;
	}
}

// altura(p) = 1+max(-1,-1) = 0
void CalcularAltura(No* no) {
	no->altura = 1+max(AlturaNo(no->p_filho_direito->altura),(no->p_filho_esquerdo->altura));
	}

int max(int HE, int HD) {
	if (HE > HD) {
		return HE;
	}
	else {
		return HD;
	}
}

Fator de Balanceamento = (h_e + 1) - (h_d + 1)
void CalcularFatorBalanceamento(No* no)
{
	if(no == NULL){
		continue;
	}
	
	CalcularAltura(no->p_filho_esquerdo);
	CalcularAltura(no->p_filho_direito);
	no->fb = AlturaNo(no->p_filho_esquerdo) - AlturaNo(no->p_filho_direito); 
}

// Quando o nó é inserido na sub-arvore direita 2x acaba desbalanceando a arvore porque a diferença
// de altura em uma Arvore AVL é no máximo 1. Resolver com a rotação RR (Right Right)

void RodarRR (No* no_desbalanceado)
{
	if (no_desbalanceado != NULL) {
		CalcularFatorBalanceamento(no_desbalanceado);
		CalcularFatorBalanceamento(no_desbalanceado->p_filho_direito);
		CalcularFatorBalanceamento(no_desbalanceado->p_filho_direito->p_filho_direito);
		
		if (no_desbalanceado->fb < no_desbalanceado->p_filho_direito && 
			no_desbalanceado->p_filho_direito < no_desbalanceado->p_filho_direito->p_filho_direito) {
				
			if (no_desbalanceado->p_pai != NULL) { // não é a raiz precisar "conectar"
					no_desbalanceado->p_filho_direito->p_pai = no_desbalanceado->p_pai;
				}	
				
			no_desbalanceado->p_filho_direito->p_filho_esquerdo = no_desbalanceado;
			no_desbalanceado->p_filho_direito->altura = 1;
			no_desbalanceado->p_pai = no_desbalanceado->p_filho_direito;
			no_desbalanceado->p_filho_direito = NULL;
			no_desbalanceado->p_filho_esquerdo = NULL;
			no_desbalanceado->altura = 0;
		}
	}
}

// Quando o nó é inserido na sub-arvore esquerda 2x acaba desbalanceando a arvore porque a diferença
// de altura em uma Arvore AVL é no máximo 1. Resolver com a rotação LL (Left Left)

void RodarLL (No* no_desbalanceado) 
{
	if (no_desbalanceado != NULL) {
		CalcularFatorBalanceamento(no_desbalanceado);
		CalcularFatorBalanceamento(no_desbalanceado->p_filho_esquerdo);
		CalcularFatorBalanceamento(no_desbalanceado->p_filho_esquerdo->p_filho_);
		
		if (no_desbalanceado->fb > no_desbalanceado->p_filho_esquerdo && 
			no_desbalanceado->p_filho_esquerdo > no_desbalanceado->p_filho_esquerdo->p_filho_esquerdo) {
			
			if (no_desbalanceado->p_pai != NULL) { // não é a raiz precisar "conectar"
					no_desbalanceado->p_filho_esquerdo->p_pai = no_desbalanceado->p_pai;
				}
			
			no_desbalanceado->p_filho_esquerdo->p_filho_direito = no_desbalanceado;
			no_desbalanceado->p_filho_esquerdo->altura = 1;
			no_desbalanceado->p_pai = no_desbalanceado->p_filho_esquerdo
			no_desbalanceado->p_filho_direito = NULL;
			no_desbalanceado->p_filho_esquerdo = NULL;
			no_desbalanceado->altura = 0;
		}
	}
}

void VerificarBalanceamento(No* p_raiz) 
{
	while (p_raiz != NULL) {
			CalcularFatorBalanceamento(p_raiz);
			
			if ( (p_raiz->fb != -1) || (p_raiz->fb != 0) || (p_raiz->fb != 1) ) { // no pivo
				
				if ( (p_raiz->fb == 2) && (p_raiz->p_filho_esquerdo == 1) {RodarLL(p_raiz);} // ROTAÇÃO LL
				
				else if ((p_raiz->fb == -2) && (p_raiz->p_filho_direito == -1)) {RodarRR(p_raiz);} // ROTAÇÃO RR
				
				else if  ((p_raiz->fb == 2) && (p_raiz->p_filho_esquerdo == -1)) { //ROTAÇÂO LR
					RodarRR(p_raiz);
					RodarLL(p_raiz);
				}
				
				else if ((p_raiz->fb == -2) && (p_raiz->p_filho_direito == +1)) { //ROTAÇÂO RL
					RodarLL(p_raiz);
					RodarRR(p_raiz);
				}
				
			}
			
		
		}
}




void InserirNo (No* p_raiz, No* chave) 
{
	if (p_raiz == NULL) { printf("Arvore Vazia, crie a Raiz para poder inserir\n");}
	if (chave == p_raiz->chave) {printf("Chave já existente\n");}
	
	if (chave < p_raiz->chave) { // CHAVE MENOR -> INSERIR A ESQUERDA
		if (p_raiz->p_filho_esquerdo == NULL) { // SE TIVER ESPAÇO LIVRE NA ESQUERDA
			// CRIAR NO
			No* novo_no = (No*) malloc(sizeof(No));
			novo_no->chave = chave;
			novo_no->p_filho_esquerdo = NULL;
			novo_no->p_filho_direito = NULL;
			novo_no->altura = 0;
			novo_no->fb = 0;
			novo_no->p_pai = p_raiz;
			p_raiz->p_filho_esquerdo = novo_no;
		}
		
		else { // PROCURAR O ESPAÇO LIVRE COM RECURSSIVIDADE
			 InserirNo(p_raiz->p_filho_esquerdo, chave);
			}
		}
	else {
		// INSERÇÃO A DIREITA
		if(p_raiz->p_filho_direito == NULL) {
			No* novo_no = (No*) malloc(sizeof(No));
			novo_no->chave = chave;
			novo_no->p_filho_esquerdo = NULL;
			novo_no->p_filho_direito = NULL;
			novo_no->altura = 0;
			novo_no->fb = 0;
			novo_no->p_pai = p_raiz;
			p_raiz->p_filho_esquerdo = novo_no;
			}
		else {
			InserirNo(p_raiz->p_filho_direito, chave);
			}
	}
	
	// LOGICA PARA AUTO BALANCEAMENTO
	
}




int main()
{
	int verificador = 0;
	int* p_verificador = &verificador; 
	
	
	
	return 0;
}

