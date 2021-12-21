// 11) Desenvolva um programa leia duas filas f1 e f2 circulares com nó bobo com 10 números reais cada uma. Imprima as filas. Em seguida, chame uma função para testar se as filas f1 e f2 são iguais, ou seja, se possuem os mesmos elementos, na mesma ordem. 

#include <stdio.h>
#define TAM 11

struct tFila {
  int F, R;
  float fila[TAM];
};

void inicializaFila(struct tFila *pf) {
  pf->F = 0;
  pf->R = 0;
}

int filaVazia(struct tFila *pf){
  if(pf->R == pf->F)
    return 1;
  return 0;
}

int filaCheia(struct tFila *pf){
  if((pf->R+1)%TAM == pf->F)
    return 1;
  return 0;
}

int insereNaFila(struct tFila *pf, int valor){
  if(filaCheia(pf))
    return 0;
  pf->R=(pf->R+1)%TAM;
  pf->fila[pf->R]=valor;
  return 1;
}

int removeNaFila(struct tFila *pf, int *elem){
  if(filaVazia(pf))
    return 0;
  pf->F = (pf->F+1)%TAM;
  *elem = pf->fila[pf->F];
  return 1;
}

int testeIgualdade(struct tFila *f1, struct tFila *f2, int i){
  if(f1->fila[i] == f2->fila[i])
    return 1;
  return 0;
}

int main(){
  struct tFila f1, f2;
  int i;
  float a;

  inicializaFila(&f1);
  inicializaFila(&f2);

  printf("\nValores F1:\n");
  for(i=1; i<TAM ; i++){
    printf("v[%d]: ", i);
    scanf("%f", &a);
    insereNaFila(&f1, a);
  }

  puts("");
  printf("\nFila F1:\n");
  for(i=1 ; i<TAM ; i++)
  printf("v[%d]: %.1f\t", i, f1.fila[i]);

  puts("");
  printf("\nValores F2:\n");
  for(i=1; i<TAM ; i++){
    printf("v[%d]: ", i);
    scanf("%f", &a);
    insereNaFila(&f2, a);
  }

  puts("");
  printf("\nFila F2:\n");
  for(i=1 ; i<TAM ; i++)
    printf("v[%d]: %.1f\t", i, f2.fila[i]);
  
  puts("");
  for(i=1 ; i<TAM ; i++){
    a = testeIgualdade(&f1, &f2, i);
    if(a == 0)
      printf("\nAs filas nao sao iguais.\n");
  }
  
    printf("\nAs filas sao iguais.\n"); 
    puts(""); 

  return 0;

}



