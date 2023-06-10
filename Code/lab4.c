#include <stdio.h>
#include <stdlib.h>

struct elemento {
  int info;
  struct elemento *prox;
  struct elemento *ant;
};
typedef struct elemento tipoElemento;

struct lista {
  tipoElemento *primeiro;
  tipoElemento *ultimo;
  int tamanhoLista;
};
typedef struct lista tipoLista;

void iniciaLista(tipoLista *listaAux) {
  listaAux->primeiro = NULL;
  listaAux->ultimo = NULL;
  listaAux->tamanhoLista = 0;
}

void insereFinal(tipoLista *listaAux) {
  tipoElemento *novo = (tipoElemento *)malloc(sizeof(tipoElemento));
  scanf("%d", &novo->info);
  if (listaAux->tamanhoLista == 0) {
    novo->prox = NULL;
    novo->ant = NULL;
    listaAux->primeiro = novo;
    listaAux->ultimo = novo;
  } else {
    novo->prox = NULL;
    novo->ant = listaAux->ultimo;
    listaAux->ultimo->prox = novo;
    listaAux->ultimo = novo;
  }
  listaAux->tamanhoLista++;
}

void inserePosicao(tipoLista *listaAux) {
  tipoElemento *novo = (tipoElemento *)malloc(sizeof(tipoElemento));
  tipoElemento *temp;
  int posicao, cont = 0, num;
  scanf("%d", &num);
  scanf("%d", &posicao);
  if (novo) {
    novo->info = num;
    temp = listaAux->primeiro;
    while (posicao != cont) {
      if(temp == listaAux->ultimo){
        temp = listaAux->ultimo;
        break;    
      }
      temp = temp->prox;
      cont++;
    }
    if (temp) {
      if (temp == listaAux->primeiro) {
        novo->prox = listaAux->primeiro;
        listaAux->primeiro->ant = novo;
        listaAux->primeiro = novo;
        novo->ant = NULL;
        listaAux->tamanhoLista++;}
        
        else if (temp == listaAux->ultimo) {
        novo->ant = listaAux->ultimo->ant;
        listaAux->ultimo->ant->prox = novo;
        listaAux->ultimo->ant = novo;
        novo->prox = listaAux->ultimo;
        listaAux->tamanhoLista++;
      } /*else if(temp->info == NULL){
        printf("oi");
        novo->ant = listaAux->ultimo;
        listaAux->ultimo->prox = novo;
        listaAux->ultimo = novo;
        novo->prox = NULL;
        listaAux->tamanhoLista++;
      } */
      else {
        novo->prox = temp;
        novo->ant = temp->ant;
        temp->ant->prox = novo;
        temp->ant = novo;
        listaAux->tamanhoLista++;
      }
    }

  } else {
    printf("Erro");
  }
}

void remover(tipoLista *listaAux) {
  int tamanho2 = 0;
  tipoElemento *temp;
  tipoElemento *novo;

  while (listaAux->tamanhoLista >= 3 && tamanho2 != listaAux->tamanhoLista) {
    tamanho2 = listaAux->tamanhoLista;
    if (listaAux->tamanhoLista == 3 &&
        listaAux->primeiro->info + listaAux->primeiro->prox->info +
                listaAux->primeiro->prox->prox->info ==
            10) {
      listaAux->primeiro->prox = NULL;
      listaAux->ultimo = NULL;
      listaAux->primeiro = NULL;
      listaAux->tamanhoLista = listaAux->tamanhoLista - 3;

    } else {
      if (listaAux->ultimo->info + listaAux->primeiro->info +
              listaAux->primeiro->prox->info ==
          10) { // ultimo + primeiro + segundo
        // printf("alo");
        // listaAux->primeiro->prox = NULL;
        listaAux->primeiro->prox->prox->ant = NULL;
        listaAux->ultimo->ant->prox = NULL;
        listaAux->primeiro = listaAux->primeiro->prox->prox;
        listaAux->ultimo = listaAux->ultimo->ant;
        listaAux->tamanhoLista = listaAux->tamanhoLista - 3;

      } else if (listaAux->primeiro->info + listaAux->primeiro->prox->info +
                     listaAux->primeiro->prox->prox->info ==
                 10) { // primeiro + segundo + terceiro
        // printf("alo2");
        listaAux->primeiro->prox->prox->prox->ant = NULL;
        listaAux->primeiro = listaAux->primeiro->prox->prox->prox;
        listaAux->tamanhoLista = listaAux->tamanhoLista - 3;
      } else if (listaAux->ultimo->info + listaAux->ultimo->ant->info +
                     listaAux->ultimo->ant->ant->info ==
                 10) { // antepenutimo + penultimo + ultimo
                       // printf("alo3");
        listaAux->ultimo->ant->ant->ant->prox = NULL;
        listaAux->ultimo = listaAux->ultimo->ant->ant->ant;
        listaAux->tamanhoLista = listaAux->tamanhoLista - 3;

      } else if (listaAux->ultimo->info + listaAux->ultimo->ant->info +
                     listaAux->primeiro->info ==
                 10) { // penultimo + ultimo + primeiro
                       // printf("alo4");
        listaAux->ultimo->ant->ant->prox = NULL;
        // listaAux->ultimo->ant = NULL;
        listaAux->ultimo = listaAux->ultimo->ant->ant;
        listaAux->primeiro->prox->ant = NULL;
        listaAux->primeiro = listaAux->primeiro->prox;
        listaAux->tamanhoLista = listaAux->tamanhoLista - 3;

      }

      else {
        int cont = 3;
        temp = listaAux->primeiro->prox->prox;
        while (cont < listaAux->tamanhoLista - 1 &&
               temp->info + temp->ant->info + temp->prox->info != 10) {
          temp = temp->prox;
          cont++;
        }
        if (temp->info + temp->ant->info + temp->prox->info == 10 &&
            cont < listaAux->tamanhoLista - 1) {
          temp->ant->ant->prox = temp->prox->prox;
          temp->prox->prox->ant = temp->ant->ant;
          temp->prox = NULL;
          temp->ant = NULL;
          temp = NULL;
          listaAux->tamanhoLista = listaAux->tamanhoLista - 3;
        }
      }
    }
  }
}

void imprime(tipoLista *listaAux) {
  int i = 0;
  tipoElemento *novo;

  novo = listaAux->primeiro;
  while (i < listaAux->tamanhoLista) {
    printf("%d ", novo->info);
    novo = novo->prox;
    i++;
  }
}
int main(void) {
  tipoLista Lista;
  iniciaLista(&Lista);
  for (int i = 0; i < 10; i++) {
    insereFinal(&Lista);
  }
  imprime(&Lista);
  printf("\n");
  for (int i = 0; i < 5; i++) {
    if (Lista.tamanhoLista <= 0) {
      break;
    } else {
      inserePosicao(&Lista);
      remover(&Lista);
      if (Lista.tamanhoLista > 0) {
        imprime(&Lista);
        printf("\n");
      }
    }
  }
  if (Lista.tamanhoLista <= 0) {
    printf("ganhou");
  } else {
    printf("perdeu");
  }
  return 0;
}