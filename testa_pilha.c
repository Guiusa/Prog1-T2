#include "libraries/libpilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

int main(){
    srand(time(0));
    pilha_t* pilha = pilha_cria(MAX);

    int i;
    /*testando o push com elementos aleatórios */
    for(i=0; i<MAX; i++) 
        push(pilha, rand()%100);
    /*testando pilha_tamanho*/
    printf("O tamanho é: %d\nOs elementos são:\n", pilha_tamanho(pilha));
    pilha_imprime(pilha);
    /*testando pilha_topo*/
    printf("O elemento do topo é: %d\n", pilha_topo(pilha));
    
    /*testando pop com todos os elementos para checar pilha_vazia no final*/
    for(i=0; i<MAX; i++)
        printf("Excluindo o índice %d: valor %d\n", pilha_tamanho(pilha), pop(pilha));

    if(pilha_vazia(pilha))
        printf("Agora a pilha está vazia!\n");

    printf("\nTentando quebrar as funções:\n");
    if(pop(pilha)==0)
        printf("ERRO: pop em pilha vazia, operação bloqueada!\n");
    printf("Tentando imprimir pilha vazia:\n");
    pilha_imprime(pilha);
    for(i=0; i<MAX; i++) 
        push(pilha, rand()%100);
    if(push(pilha, rand()%100)==-1)
        printf("ERRO: push em pilha cheia, operação bloqueada!\n\n");

    pilha_destroi(pilha);
    return 0;
}