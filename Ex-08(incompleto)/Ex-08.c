// 8)Escreva um programa que empilhe uma sequência de números inteiros positivos até o momento em que for digitado o valor zero. A pilha tem tamanho máximo 50. Neste momento, o conteúdo da pilha deverá ser distribuído em outras duas pilhas. Uma delas conterá apenas os valores ímpares e a outra conterá apenas os valores pares. Imprima o conteúdo das duas pilhas.

#include <stdio.h>
#define TAM 50

struct tPilha {
    int topo;
    int pilha[TAM];
};

void inicializaPilha(struct tPilha *ps){
    ps->topo = -1;
}

int pilhaVazia(struct tPilha *ps){
    if(ps->topo== -1)
        return 1;
    return 0;
}

int pilhaCheia(struct tPilha *ps){
    if(ps->topo == TAM -1)
        return 1;
    return 0;
}

int insereNaPilha(struct tPilha *ps, int valor){
    if(pilhaCheia(ps))
        return 0;
    ps->topo++;
    ps->pilha[ps->topo] = valor;
    return 1;
}

int removeNaPilha(struct tPilha *ps, int *elem) {
    if(pilhaVazia(ps))
        return 0;
    *elem = ps->pilha[ps->topo];
    ps->topo--;
    return 1;
}

int main(){
    struct tPilha p1, pPar, pImpar;

    inicializaPilha(&p1);
    inicializaPilha(&pPar);
    inicializaPilha(&pImpar);

    int i=0 , a, j = 0;

    printf("\nPilha:\n");
    do{
        printf("v[%d]: ", i);
        scanf("%d", &a);
        insereNaPilha(&p1, a);
        if(p1.pilha[i]==0)
            break;     
        i++;
        j++;
    }while(i<TAM);

    i=0;

    printf("\nMembros da pilha:\n");
    do{
        printf("v[%d]: %d\t", i, p1.pilha[i]);
        i++;
    }while(i<TAM && p1.pilha[i] != 0);

    for(i=0; i<j; i++){
        if(p1.pilha[i]%2 == 0){
            removeNaPilha(&p1, &a);
            insereNaPilha(&pPar, a);
        }else {
            removeNaPilha(&p1, &a);
            insereNaPilha(&pImpar, a);
        }
    }

    puts("");
    printf("\nPilha P1: \n");
    for(i=0; i<j; i++){
        printf("v[%d]: %d\t", i, p1.pilha[i]);
    }

    puts("");
    printf("\nPilha Par: \n");
    for(i=0; i<j; i++){
        if(pPar.pilha[i]%2 == 0)
            printf("v[%d]: %d\t", i, pPar.pilha[i]);
    }

    puts("");
    printf("\nPilha Impar: \n");
    for(i=0; i<j; i++){
        if(pImpar.pilha[i]%2 == 1)
            printf("v[%d]: %d\t", i, pImpar.pilha[i]);
    }

    return 1;
}

