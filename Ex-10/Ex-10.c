// 10) Escreva um programa que leia 20 valores inteiros e insira-os numa pilha. Em seguida, leia um número 20 valores inteiros e insira-os numa fila circular com contador. Logo após, forneça o Maior, o menor e a média aritmética dos elementos na pilha e na fila, respectivamente.

#include <stdio.h>
#define TAM 20

struct tPilha{
  int topo;
  int pilha[TAM];
};

void inicializaPilha(struct tPilha *ps){
  ps->topo = -1;
}

int pilhaVazia(struct tPilha *ps){
  if(ps->topo == -1 )
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


struct tFilaCircular{
  int ini; 
  int fim; 
  int cont;
  int fila[TAM];
};

void inicializaFila(struct tFilaCircular *pf){
  pf->ini = 0;
  pf->fim = -1;
  pf->cont = 0;
}

int filaVazia(struct tFilaCircular *pf){
  if(pf->cont == 0)
    return 1;
  return 0;
}

int filaCheia(struct tFilaCircular *pf){
  if(pf->cont == TAM)
    return 1;
  return 0;
}

int insereNaFila(struct tFilaCircular *pf, int valor){
  if(filaCheia(pf))
    return 0;
  pf->cont++;
  pf->fim = (pf->fim == TAM-1) ? 0 : pf->fim+1;
  pf->fila[pf->fim] = valor;
  return 1; 
}

int removeNaFila(struct tFilaCircular *pf, int *elem){
  if(filaVazia(pf))
    return 0;
  pf->cont--;
  *elem = pf->fila[pf->ini];
  pf->ini = (pf->ini == TAM -1) ? 0 : pf->ini+1;
  return 1;
}


int main(){
  struct tPilha p1;
  struct tFilaCircular f1;
  int i=0, a, maiorFila, maiorPilha, menorFila, menorPilha;
  float mediaFila=0, mediaPilha=0;


  inicializaPilha(&p1);
  inicializaFila(&f1);
  
  printf("\nP1:\n");
  for(; i<TAM ; i++){
    printf("v[%d]: ",i);
    scanf("%d", &a);
    insereNaPilha(&p1, a);
  }

  puts("");
  printf("P1:\n");
  for(i=0 ; i<TAM ; i++)
    printf("v[%d]: %d\t", i, p1.pilha[i]);
  
  puts("");
  printf("\nFila:\n");
  for(i=0; i<TAM ; i++){
    printf("v[%d]: ", i);
    scanf("%d", &a);
    insereNaFila(&f1, a);
  }

  puts("");
  printf("\nF1:\n");
  for(i=0 ; i<TAM ; i++)
    printf("v[%d]: %d\t", i, f1.fila[i]);
  puts("");

  for(i=0; i<TAM ; i++){
      if(i==0){
        maiorPilha = p1.pilha[i];
        menorPilha = p1.pilha[i];
      }
      if( maiorPilha < p1.pilha[i])
        maiorPilha = p1.pilha[i];
      if( menorPilha > p1.pilha[i])
        menorPilha = p1.pilha[i];
  }

  for(i=0; i<TAM ; i++){
      if(i==0){
        maiorFila = f1.fila[i];
        menorFila = f1.fila[i];
      }
      if( maiorFila < f1.fila[i])
        maiorFila = f1.fila[i];
      if( menorFila > f1.fila[i])
        menorFila = f1.fila[i];
  }

  for(i=0; i<TAM ; i++){
    mediaFila += f1.fila[i];
    mediaPilha += p1.pilha[i];
    if(i==TAM-1){
      mediaFila /= (i+1); 
      mediaPilha /= (i+1); 
    }
  }
  
  
  puts("");
  printf("Maior da Fila F1: %d\nMenor: %d\nMedia: %.2f", maiorFila, menorFila, mediaFila);

  puts("");
  printf("\nMaior da Pilha P1: %d\nMenor: %d\nMedia: %.2f", maiorPilha, menorPilha, mediaPilha);

  puts("");


  return 1;
}

