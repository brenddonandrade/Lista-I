// 13) Escreva um programa que contenha uma estrutura de lista sequencial não ordenada com dados de 40 alunos (nome, matricula e média) e forneça as seguintes opções:
// 1) Inserir um aluno na lista; (ler nome, matricula e média) 
// 2) Excluir um aluno da lista; 
// 3) Calcular média da turma;
// 4) Imprimir os dados dos alunos acima da média;
// 5) Imprimir lista;
// 6) Sair. 
// O programa termina quando for digitado a opção 6.

#include <stdio.h>
#include <string.h>
#define TAM 2

struct tno{
  char nome[100];
  int matricula;
  float media;
};

struct tlista{
  int qtnos;
  struct tno lista[TAM];
};

void inicializaLista(struct tlista *pl){
  pl->qtnos = 0;
}

int listaVazia(struct tlista *pl){
  if(pl->qtnos == 0)
    return 1;
  return 0;
}

int listaCheia(struct tlista *pl){
  if(pl->qtnos == TAM)
    return 1;
  return 0;
}

void percurso(struct tlista *pl){
  int i;
  for(i=0 ; i < pl->qtnos ; i++)
    printf("\n Nome: %s\n Matricula: %d\n Media: %.2f\n\n", pl->lista[i].nome, pl->lista[i].matricula, pl->lista[i].media);
}

int buscaMatricula(struct tlista *pl, int mat){
  int i;
  for(i=0 ; i<pl->qtnos ; i++){
    if(mat == pl->lista[i].matricula)
      return i;
  }
  return -1;
}

int buscaNome(struct tlista *pl, char nome[]){
  int i;
  for(i=0 ; i<pl->qtnos; i++) {
    if(!strcmp(nome, pl->lista[i].nome))
      return i;
  }
  return -1;
}

int insereNaLista(struct tlista *pl, char nome[], int mat, float media){
  int i;
  if(listaCheia(pl))
    return 0;
  i = buscaMatricula(pl, mat);
  if(i>=0)
    return -1;//matricula existe -> não tem como adicionar o mesmo aluno
  strcpy(pl->lista[pl->qtnos].nome, nome);
  pl->lista[pl->qtnos].matricula = mat;
  pl->lista[pl->qtnos].media = media;
  pl->qtnos++;
  return 1; 
}

int removeNaLista(struct tlista *pl, int mat){
  int i;
  if(listaVazia(pl))
    return 0;
  i = buscaMatricula(pl, mat);
  if(i<0)
    return -1;
  pl->qtnos--;
  strcpy(pl->lista[i].nome, pl->lista[pl->qtnos].nome);
  pl->lista[i].matricula = pl->lista[pl->qtnos].matricula;
  pl->lista[i].media = pl->lista[pl->qtnos].media;
  return 1;
}

float calcMedia(struct tlista *pl){
  int i;
  float med = 0;
  if(listaVazia(pl)){
    printf("\n Lista vazia.\n");
    return 0;
  }
  for(i=0 ; i<pl->qtnos ; i++){
    med +=  pl->lista[i].media;
  }
  med /= i;
  return med;
}

int alunoAcimaDaMedia(struct tlista *pl){
  int i, nAlunosAcimaDaMedia = 0;

  if(pl->qtnos == 0){
    printf("\n Lista vazia.\n");
    return 0;
  }

  for(i=0; i<pl->qtnos ; i++){
    if(pl->lista[pl->qtnos].media >= 6.0){
      if(i==0)
        printf("\n Alunos acima da media:\n");
      printf("\n Nome: %s\n Matricula: %d\n Media: %.2f", pl->lista[pl->qtnos].nome, pl->lista[pl->qtnos].matricula, pl->lista[pl->qtnos].media); 
      nAlunosAcimaDaMedia++; 
    }
  }
  return nAlunosAcimaDaMedia;
}


int main(){
  int op, mat, i, nAlunos;
  float p1, p2, med, mediaTurma;
  char nome[60];
  struct tlista l1;
  
  inicializaLista(&l1);

  for(i=0 ; i<TAM ; i++){
    printf("\n Digite seu nome: ");
    gets(nome);
    printf("\n Digite sua matricula: ");
    scanf("%d", &mat);
    printf("\n Digite a primeira e segunda nota: ");
    scanf("%f %f", &p1, &p2);
    med = (p1 + p2)/2;
    insereNaLista(&l1, nome, mat, med);
    fgetc(stdin);
  }

  do{
    printf("\n 1) Inserir um aluno na lista;\n 2) Excluir um aluno da lista; \n 3) Calcular media da turma;\n 4) Imprimir os dados dos alunos acima da media; \n 5)Imprimir a lista; \n 6) Sair; \n Digite uma das opcoes: ");
    scanf("%d", &op);
    switch(op){
      case 1:
        insereNaLista(&l1, nome, mat, med);
        break;
      case 2:
        printf("\n Digite a matricula a ser removida: ");
        scanf("%d", &mat);
        i = removeNaLista(&l1, mat);
        if(i>0)
          printf("\n Elemento Removido. \n");
        else
          printf("\n Elemento nao encontrado ou lista vazia. \n");
        break;

      case 3:
        mediaTurma = calcMedia(&l1); 
        printf("\n Media da turma: %.2f\n", mediaTurma);
        break;

      case 4:
        nAlunos = alunoAcimaDaMedia(&l1);
        if(nAlunos == 0)
          printf("\n Nenhum aluno esta acima da media.\n");
        break;

      case 5:
        percurso(&l1);
        break;
      default:
        printf("\n Opcao invalida.\n");
    }
  }while(op!=6);
  
  return 1;
}


// 1) Inserir um aluno na lista; (ler nome, matricula e média) 
// 2) Excluir um aluno da lista; 
// 3) Calcular média da turma;
// 4) Imprimir os dados dos alunos acima da média;
// 5) Imprimir lista;
// 6) Sair. 







