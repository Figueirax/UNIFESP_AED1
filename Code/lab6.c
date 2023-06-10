#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct elemento {
  int valor;
  struct elemento *ant;
};
typedef struct elemento tipoElemento;

struct pilha {
  int tamanhoPilha;
  tipoElemento *topo;
  int cont;
};
typedef struct pilha tipoPilha;

void inicia(tipoPilha *pilhaAux) {
  pilhaAux->topo = NULL;
  pilhaAux->tamanhoPilha = 0;
}

void imprime(tipoPilha *pilhaAux) {
  int i = 0, j = 0;
  tipoElemento *novo;

  novo = pilhaAux->topo;
  while (i < pilhaAux->tamanhoPilha) {
    // printf("\n%d\n", novo->valor);
    novo = novo->ant;
    i++;
  }
}

void binario(tipoPilha *pilhaAux) {
  int num;
  scanf("%d", &num);
  int temp_num = num;
  tipoElemento *temp;
  pilhaAux->cont = 0;

  while (num > 0) {
    tipoElemento *novo = (tipoElemento *)malloc(sizeof(tipoElemento));
    if (pilhaAux->tamanhoPilha == 0) {
      novo->valor = num % 2;
      novo->ant = NULL;
      pilhaAux->topo = novo;
      num = num / 2;
      pilhaAux->cont++;
      // printf("%d",num);
    } else {
      novo->valor = num % 2;
      novo->ant = pilhaAux->topo;
      pilhaAux->topo = novo;
      num = num / 2;
      pilhaAux->cont++;
    }
    pilhaAux->tamanhoPilha++;
  }
  printf("%d ", temp_num);

  int j = pilhaAux->cont - 1;

  temp = pilhaAux->topo;
  while (j >= 0) {
    printf("%d", temp->valor);
    temp = temp->ant;
    j--;
  }
}

void imprime_inverso(tipoPilha *pilhaAux) {
  tipoElemento *temp;
  temp = pilhaAux->topo;
  int i = pilhaAux->cont - 1;
  printf(" ");
  while (i >= 0) {
    if (temp->valor == 0) {
      temp->valor = 1;
    } else {
      temp->valor = 0;
    }
    printf("%d", temp->valor);
    temp = temp->ant;
    i--;
  }
}

void decimal(tipoPilha *pilhaAux) {
  tipoElemento *temp;
  tipoElemento *aux;

  int i = pilhaAux->cont - 1;
  int j = pilhaAux->cont - 1;
  int soma;
  int v[100];
  printf(" ");
  temp = pilhaAux->topo;
  while (i >= 0) {

    int num = (int)pow(2, i);
    int dec = temp->valor * num;
    temp->valor = dec;
    // printf("%d", temp->valor);
    temp = temp->ant;
    i--;
  }
  aux = pilhaAux->topo;
  while (j >= 0) {
    soma = aux->valor + soma;
    aux = aux->ant;
    j--;
  }
  printf("%d", soma);
  /*aux = pilhaAux->topo;
  while(j < pilhaAux->tamanhoPilha){
    if (aux->valor != 0){
      for(int i = 0; i<=j ; i++){
        if (v[i] != 0){
        v[i] = aux->valor;
          }
      }
    }
    aux = aux->ant;
    j++;
  }*/
}

int main(void) {
  int variavel;
  tipoPilha Pilha;
  inicia(&Pilha);
  scanf("%d", &variavel);
  for (int i = 0; i < variavel; i++) {
    binario(&Pilha);
    imprime_inverso(&Pilha);
    decimal(&Pilha);
    printf("\n");
    // imprime(&Pilha);

    // empilhar(&Pilha);
    // printf("\n");
    // imprime(&Pilha);
  }
  // printf("\nHello World\n");
  return 0;
}