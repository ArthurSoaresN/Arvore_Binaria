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
 
 O fb deve ser +1, 0 ou -1 para ser uma arvore balanceada.
 Nó com fb desbalanceado é o pivô e precisa ser balanceado.
 
 Balanço de um nó = (h_e + 1) - (h_d + 1)
 
 h_e -> é a altura da subárvore esquerda daquele nó
 h_d -> é a altura da subárvore direita daquele nó
 
 A altura de um nó é o comprimento do caminho mais longo desse nó até uma folha
 A altura de uma árvore vazia (um filho que não existe, ou seja, um ponteiro NULL) é convencionada como -1
 Por definição, a altura de uma folha (um nó sem filhos) é 0
 A altura de um nó que não é folha é calculada como: 1 + a maior altura entre seus filhos.
 
  
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

int main()
{
	
	return 0;
}

