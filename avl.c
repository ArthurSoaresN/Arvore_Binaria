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
 
 filhos a esquerda (+1)
 filhos a direita (-1)
 dois ou nenhum filho (0)
 
 fb = altura da sub arvore esquerda - sub arvore direita
 
 
 */

int main()
{
	
	return 0;
}

