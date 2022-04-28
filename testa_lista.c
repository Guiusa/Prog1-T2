#include "libraries/liblista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

int main(){
    srand(time(0));
    int i;
    int teste = 15;
    lista_t* l = lista_cria();


    printf("-> testando inserir_ordenado com 50 elementos aleatórios:\n");
    for(i=0; i<MAX; i++)
        lista_insere_ordenado(l, rand()%100);
    lista_imprime(l);
    
    printf("\n-> Agora, será removido 1 elemento para cada número de 1 a 10, caso esteja na lista:\n");
    for(i=1; i<=10; i++){
        if(lista_retira_elemento(l, &i))
            printf("O número %d aparece ao menos uma vez e será retirado\n", i);
        else
            printf("O número %d não aparece na lista\n", i);
    }
    
    printf("\n-> A lista nova é:\n");
    lista_imprime(l);
    
    printf("\n-> Será removido agora os 10 últimos e os 10 primeiros elementos:\n");
    for(i=0; i<10; i++)
        lista_retira_fim(l, &teste);
    lista_imprime(l);
    for(i=0; i<10; i++)
        lista_retira_inicio(l, &teste);
    lista_imprime(l);
    
    
    printf("\n-> O tamanho da lista agora é de %d elementos\n", lista_tamanho(l));

    printf("\n-> Agora serão inseridos 10 elementos no fim e no início:\n");
    for(i=0; i<10; i++)
        lista_insere_fim(l, rand()%100);
    lista_imprime(l);
    for(i=0; i<10; i++)
        lista_insere_inicio(l, rand()%100);
    lista_imprime(l);

    printf("\n-> Agora, para tentar quebrar o programa, serão aplicadas as funções de retirar elementos na lista extrapolando o tamanho dela:\n");
    int tam = lista_tamanho(l);
    for(i=0; i<tam*2; i++)
        lista_retira_fim(l, &teste);    
    for(i=0; i<tam*2; i++)
        lista_retira_inicio(l, &teste);
    for(i=0; i<tam*2; i++){
        int k = rand()%100;
        lista_retira_elemento(l, &k);
    }
    printf("\n-> O tamanho da lista agora é %d\n", lista_tamanho(l));
    printf("\n-> Apesar de ter tentado tirar algo próximo de 6 vezes o tamanho da lista, as funções só permitiram até que a lista estivesse vazia, obtendo sucesso\n");
    lista_destroi(l);
    return 0;
}