// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################
struct elemento {
  float info;
  int ID;
  int quant;
  struct elemento *prox;
  int cont;
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

void insere(tipoLista *listaAux) {
  float num;
  int id, quantidade, i = 0, id2;
  scanf("%d", &id);
  scanf("%d", &quantidade);
  scanf("%f", &num);
  tipoElemento *temp, *novoElem = malloc(sizeof(tipoElemento));

  temp = listaAux->primeiro;
  while (temp != NULL && id != temp->ID) {
    temp = temp->prox;
    id2 = temp->ID;
  }
  if (temp) {
    printf("ja existe\n");
  }

  else {

    if (novoElem) {
      novoElem->info = num;
      novoElem->ID = id;
      novoElem->quant = quantidade;
      if (listaAux->tamanhoLista == 0) {
        novoElem->prox = NULL;
        listaAux->primeiro = novoElem;
        listaAux->ultimo = novoElem;
        listaAux->tamanhoLista++;
      } else if (novoElem->info > listaAux->primeiro->info) {
        listaAux->ultimo = listaAux->primeiro;
        novoElem->prox = listaAux->primeiro;
        listaAux->primeiro = novoElem;
        listaAux->tamanhoLista++;
      } else {
        temp = listaAux->primeiro;
        while (temp->prox != NULL && temp->prox->info > novoElem->info) {
          temp = temp->prox;
        }
        novoElem->prox = temp->prox;
        temp->prox = novoElem;
        listaAux->ultimo = temp->prox;
        listaAux->tamanhoLista++;
      }

    } else {
      printf("Erro na memória");
    }
  }
}

void alteracao(tipoLista *listaAux) {
  int quant, id, i = 0;
  tipoElemento *novoElem = malloc(sizeof(tipoElemento));
  scanf("%d", &id);
  scanf("%d", &quant);
  novoElem = listaAux->primeiro;
  while (novoElem != NULL && id != novoElem->ID) {
    novoElem = novoElem->prox;
  }
  if (novoElem) {
    novoElem->quant = novoElem->quant + quant;
  } else {
    printf("nao existe\n");
  }
}

void compra(tipoLista *listaAux) {
  int id1, id2 = 0, i = 0;
  scanf("%d", &id1);
  tipoElemento *novoElem = malloc(sizeof(tipoElemento));
  novoElem = listaAux->primeiro;
  while (novoElem != NULL && novoElem->ID != id1) {
    novoElem = novoElem->prox;
    id2 = novoElem->ID;
  }
  if (novoElem) {
    if (novoElem->quant != 0) {
      novoElem->quant = novoElem->quant - 1;
      novoElem->cont++;

    } else {
      printf("nao existe\n");
    }

  } else {
    printf("nao existe\n");
  }
}

tipoElemento *remover(tipoLista *listaAux) {
  int id;
  scanf("%d", &id);
  tipoElemento *temp, *novoElem = malloc(sizeof(tipoElemento));
  if (novoElem) {
    if (listaAux->tamanhoLista != 0) {
      if (listaAux->primeiro->ID == id) {
        novoElem = listaAux->primeiro;
        listaAux->primeiro = novoElem->prox;
        listaAux->tamanhoLista--;
      } else {
        temp = listaAux->primeiro;
        while (temp->prox != NULL && temp->prox->ID != id) {
          temp = temp->prox;
        }
        if (temp->prox->ID == id) {
          novoElem = temp->prox;
          temp->prox = novoElem->prox;
          listaAux->tamanhoLista--;
        } else {
          printf("não existe\n");
        }
      }
    } else {
      printf("nao existe\n");
    }

  } else {
    printf("Erro ao alocar");
  }
  return novoElem;
}
void imprime(tipoLista *listaAux) {
  int i = 0;
  tipoElemento *novoElem = malloc(sizeof(tipoElemento));
  novoElem = listaAux->primeiro;
  while (i < listaAux->tamanhoLista) {
    printf("%d ", novoElem->ID);
    printf("%f\n", novoElem->cont * novoElem->info);
    novoElem = novoElem->prox;
    i++;
  }
}

// ############################ Principal ###################################
int main(void) {
  int variavel, variavel1;
  tipoLista Lista;
  iniciaLista(&Lista);
  tipoElemento *remove;
  scanf("%d", &variavel);
  for (int i = 0; i < variavel; i++) {
    scanf("%d", &variavel1);
    if (variavel1 == 1) {
      insere(&Lista);
    }
    if (variavel1 == 2) {
      alteracao(&Lista);
    }
    if (variavel1 == 3) {
      compra(&Lista);
    }
    if (variavel1 == 4) {
      remove = remover(&Lista);
      if (remove) {
        free(remove);
      } else {
        printf("nao existe");
      }
    }
  }
  imprime(&Lista);

  return 0;
}