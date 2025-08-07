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
 
 
 */

int main()
{
	
	return 0;
}

