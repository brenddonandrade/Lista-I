// 7) Escreva um programa que leia 30 números inteiros e insira-os numa fila f1. Imprima a fila f1.Logo após, inverta o conteúdo de f1 nela mesma utilizando uma pilha auxiliar. Imprima a fila f1 invertida.

#include <stdio.h>
#define TAM 4


struct tFila{
  int R, F;
  int fila [TAM];
};

void inicializaFila(struct tFila *pf){
  pf->R = -1;
  pf->F = 0;
}

int filaVazia(struct tFila *pf){
  if(pf->F > pf->R)
    return 1;
  return 0;
}

int filaCheia(struct tFila *pf){
  if(pf->R == TAM-1)
    return 1;
  return 0;
}

int insereNaFila(struct tFila *pf, int valor){
  if(filaCheia(pf))
    return 0;
  pf->R++;
  pf->fila[pf->R] = valor;
  return 0;
}

int removeNaFila(struct tFila *pf, int *elem) {
  if(filaVazia(pf))
    return 0;
  *elem = pf->fila[pf->F];
  pf->F++;
  return 1;
}

struct tPilha{
  int topo;
  int pilha[TAM];
};

void inicializaPilha(struct tPilha *ps){
  ps->topo = -1;
}

int pilhaVazia(struct tPilha *ps){
  if(ps->topo == -1)
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

int removeNaPilha(struct tPilha *ps, int *elem){
  if(pilhaVazia(ps))
    return 0;
  *elem = ps->pilha[ps->topo];
  ps->topo--;
  return 1;
}

int main(){
  struct tFila f1;
  struct tPilha p1;

  int i, a;


  inicializaFila(&f1);
  inicializaPilha(&p1);

  printf("\nFila:");
  puts("");
  for(i=0 ; i < TAM ; i++){
      printf("v[%d]: ", i);
      scanf("%d", &a);
      insereNaFila(&f1, a);
      insereNaPilha(&p1, a);
  }

  printf("\nFila sem a mudanca:\n");
  for(i=0 ; i<TAM ; i++)
    printf("v[%d]: %d\t", i, f1.fila[i]);

  for(i=0; i<TAM ; i++){
      removeNaFila(&f1, &a);
      insereNaPilha(&p1, a);
  }

  puts("");
  printf("\nPilha que recebeu os valores de f1:\n");
  for(i=0 ; i<TAM ; i++)
    printf("v[%d]: %d\t",i, p1.pilha[i]);


  inicializaFila(&f1);

  for(i=0; i<TAM ; i++){
    removeNaPilha(&p1, &a);
    insereNaFila(&f1, a);
  }

  puts("");
  printf("\nFila Apos a mudanca: \n");
  for(i=0; i<TAM ; i++) {
    printf("v[%d]: %d\t", i, f1.fila[i]);
  }

  return 0;
}
