
#include "libraries/libfila.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
int main(){
    fila_t* f = fila_cria();
    srand(time(0));

    int dequeueElem;
    int i;
    /*Testando fila_tamanho*/
    printf("O tamanho da fila agora é de %d elementos\n", fila_tamanho(f)); 
    /*Testando o queue com elementos aleatórios*/
    for(i=0; i<50; i++){ 
        queue(f, rand()%100);
    }
    printf("O tamanho da fila agora é de %d elementos\n", fila_tamanho(f));
    printf("Os elementos da fila são:\n");
    fila_imprime(f);
    /*testando o dequeue*/
    for(i=0; i<MAX; i++){
        dequeue(f, &dequeueElem);
        printf("Excluindo o índice %d: valor %d\n", MAX-fila_tamanho(f), dequeueElem);
    }
    if(fila_vazia(f))
        printf("A fila está vazia agora\n");

    printf("\nTentando quebrar as funções:\n");
    if(dequeue(f, &dequeueElem)==0) 
        printf("ERRO: impossível desinfileirar elemento de fila vazia\n");
    printf("tentando imprimir fila vazia:\n");
    fila_imprime(f);
    fila_destroi(f);
    return 0;
}