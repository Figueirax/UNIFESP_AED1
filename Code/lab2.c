// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################
struct info {
  int RA;
  int prox;
};
typedef struct info tipoInfo;

struct lista {
  int tamanhoLista;
  int primeiro;
  int ultimo;
  int posLivre[10];
  tipoInfo elemento[10];
  int cont, cont1, cont2, cont3, cont4, cont5, cont6, cont7;
};
typedef struct lista tipoLista;

void iniciaLista(tipoLista *listaAux) {
  listaAux->tamanhoLista = 0;
  listaAux->primeiro = -1;
  listaAux->ultimo = -1;
  for (int i = 0; i < 10; i++) {
    listaAux->elemento[i].RA = 0;
    listaAux->elemento[i].prox = -1;
    listaAux->posLivre[i] = 1;
  }
}
void imprime(tipoLista *listaAux) {
  int temp, i = 0;
  temp = listaAux->primeiro;
  while (i < listaAux->tamanhoLista) {
    printf("%d ", listaAux->elemento[temp].RA);
    temp = listaAux->elemento[temp].prox;
    i++;
  }
}

void insere(tipoLista *listaAux) {
  int i;
  for (int aux = 0; aux < 10; aux++) {
    if (listaAux->posLivre[aux] == 1) {
      i = aux;
      listaAux->posLivre[aux] = 0;
      break;
    }
  }
  scanf("%d", &listaAux->elemento[i].RA);

  if (listaAux->tamanhoLista == 0) {
    listaAux->elemento[i].prox = -1;
    listaAux->primeiro = i;
    listaAux->ultimo = i;
    listaAux->tamanhoLista++;
  } else if (listaAux->elemento[i].RA <
             listaAux->elemento[listaAux->primeiro].RA) {
    listaAux->elemento[i].prox = listaAux->primeiro;
    listaAux->primeiro = i;
    listaAux->tamanhoLista++;
  } else {
    int temp;
    temp = listaAux->primeiro;
    while (listaAux->elemento[temp].prox != -1 &&
           listaAux->elemento[i].RA >
               listaAux->elemento[listaAux->elemento[temp].prox].RA) {
      temp = listaAux->elemento[temp].prox;
    }
    listaAux->elemento[i].prox = listaAux->elemento[temp].prox;
    listaAux->elemento[temp].prox = i;
    listaAux->ultimo = i;
    listaAux->tamanhoLista++;
  }

  if (listaAux->elemento[i].RA > 66000 && listaAux->elemento[i].RA < 67000) {
    listaAux->cont++;
  }
  if (listaAux->elemento[i].RA > 76000 && listaAux->elemento[i].RA < 77000) {
    listaAux->cont1++;
  }
  if (listaAux->elemento[i].RA > 86000 && listaAux->elemento[i].RA < 87000) {
    listaAux->cont2++;
  }
  if (listaAux->elemento[i].RA > 96000 && listaAux->elemento[i].RA < 97000) {
    listaAux->cont3++;
  }
  if (listaAux->elemento[i].RA > 106000 && listaAux->elemento[i].RA < 107000) {
    listaAux->cont4++;
  }
  if (listaAux->elemento[i].RA > 116000 && listaAux->elemento[i].RA < 117000) {
    listaAux->cont5++;
  }
  if (listaAux->elemento[i].RA > 126000 && listaAux->elemento[i].RA < 127000) {
    listaAux->cont6++;
  }
  if (listaAux->elemento[i].RA > 136000 && listaAux->elemento[i].RA < 137000) {
    listaAux->cont7++;
  }
}

void remover(tipoLista *listaAux) {
  int variavel2, temp, aux;
  int i = 0;

  scanf("%d", &variavel2);

  temp = listaAux->primeiro;
  while (listaAux->elemento[temp].prox != -1 &&
         variavel2 != listaAux->elemento[listaAux->elemento[temp].prox].RA) {
    temp = listaAux->elemento[temp].prox;
  }
  if (variavel2 == listaAux->elemento[listaAux->primeiro].RA) {
    listaAux->posLivre[listaAux->primeiro] = 1;
    listaAux->primeiro = listaAux->elemento[listaAux->primeiro].prox;
    listaAux->tamanhoLista--;
  } else if (variavel2 ==
             listaAux->elemento[listaAux->elemento[temp].prox].RA) {
    listaAux->elemento[temp].prox =
        listaAux->elemento[listaAux->elemento[temp].prox].prox;
    listaAux->posLivre[listaAux->elemento[temp].prox] = 1;
    if (variavel2 == listaAux->elemento[listaAux->ultimo].RA) {
      listaAux->ultimo = temp;
      listaAux->posLivre[listaAux->ultimo] = 1;
    }
    listaAux->tamanhoLista--;
  } else {
    printf("nao existe\n");
  }
}

// ############################ Principal ###################################
int main(void) {
  tipoLista Lista;
  iniciaLista(&Lista);
  Lista.cont = 0;
  Lista.cont1 = 0;
  Lista.cont2 = 0;
  Lista.cont3 = 0;
  Lista.cont4 = 0;
  Lista.cont5 = 0;
  Lista.cont6 = 0;
  Lista.cont7 = 0;
  int nReservas, variavel1, posicao, temp;
  scanf("%d", &nReservas);
  for (int i = 0; i < nReservas; i++) {
    scanf("%d", &variavel1);
    if (variavel1 == 1) {
      if (Lista.tamanhoLista == 10) {
        scanf("%d", &temp);
        printf("lista cheia\n");
        imprime(&Lista);
        printf("\n");
      } else {
        insere(&Lista);
        imprime(&Lista);
        printf("\n");
      }
    }
    if (variavel1 == 2) {
      remover(&Lista);
      imprime(&Lista);
      printf("\n");
    }
  }
  printf("2011: %d\n", Lista.cont);
  printf("2012: %d\n", Lista.cont1);
  printf("2013: %d\n", Lista.cont2);
  printf("2014: %d\n", Lista.cont3);
  printf("2015: %d\n", Lista.cont4);
  printf("2016: %d\n", Lista.cont5);
  printf("2017: %d\n", Lista.cont6);
  printf("2018: %d", Lista.cont7);
  return 0;
}