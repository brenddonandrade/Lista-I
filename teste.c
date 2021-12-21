#include <stdio.h>

struct tPilha{
  int topo;
  int pilha[3];
};

int main(){
  struct tPilha p1, *ps;
  
  int a;

  ps->topo = 0;

  ps->topo++;

  printf("\n%d\n", p1.topo);

  ps->topo = 0;

  ps->topo+1;

  printf("\n%d\n", p1.topo);


  return 1;
}