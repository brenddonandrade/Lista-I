#include <stdio.h>

struct tPilha {
  int topo;
  int pilha[100];
};

void incializaPilha(struct tPilha *ps){
  ps->topo = -1;
}

int pilhaVazia(struct tPilha *ps){
  if(ps->topo == -1)
    return 1;
  return 0;
}

int empilhar(struct tPilha *ps, int valor){
  ps->topo++;
  ps->pilha[ps->topo] = valor;
  return 1;
}

int desempilhar(struct tPilha *ps, int *elem){
  if(pilhaVazia(ps))
    return 0;
  *elem = ps->pilha[ps->topo];
  ps->topo--;
  return 1;
}

int main(){
  struct tPilha p1, p2;
  incializaPilha(&p1);
  incializaPilha(&p2);

  int i=0, a, b, c, aux;

  printf("\nDigite o numero que deseja transformar: ");
  scanf("%d", &a);

  printf("\nNumero: %d", a);
  puts("");

  do{
    aux = a % 2;
    empilhar(&p1, aux);
    a = a/2;
    a = a + aux;
    i++;
    printf("%d", a);
  }while(a%2==1 && a/2==1);

  aux = i;
/*
  for(i=0 ; i<aux; i++)
    printf("%d", p1.pilha[i]);
  */
  /*aux = i;

  for(i=0; i<=aux ; i++) {
    desempilhar(&p1, &b);
    c = b;
    empilhar(&p2, c);
  }

  puts("");
  printf("Numero em binario: ");
  
  for(i=0 ; i<=aux ; i++) 
    printf("%d", p2.pilha[i]);*/

  puts("");
  return 0;
}
