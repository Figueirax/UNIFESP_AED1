// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <stdlib.h>


// ########################## TAD X.h ######################################

struct Fila {
  int primeiro;
  int ultimo;
  int tamanhoFila;
  int elementos[100];
};
typedef struct Fila tipoFila;

void iniciaFila(tipoFila *filaAux) {
  filaAux->primeiro = -1;
  filaAux->ultimo = -1;
  filaAux->tamanhoFila = 0;
  for (int i = 0; i < 100; i++) {
    filaAux->elementos[i] = 0;
  }
}
int filaVazia(tipoFila *filaAux) {
  if ((filaAux->primeiro == filaAux->ultimo) && (filaAux->ultimo == -1)) {
    return 1; // fila vazia
  } else
    return 0; // fila nao esta vazia
}

int filaCheia(tipoFila *filaAux) {
  if (((filaAux->ultimo + 1) % 100) == filaAux->primeiro) {
    return 1; // fila cheia
  } else
    return 0; // fila nao esta cheia
}
void insere(tipoFila *filaAux) {
  int info;
  scanf("%d", &info);
  if (filaVazia(filaAux) == 1) {
    filaAux->primeiro = 0;
    filaAux->ultimo = 0;
    filaAux->elementos[0] = info;
    filaAux->tamanhoFila++;
  } else if (filaCheia(filaAux) == 0) {
    int posicao = ((filaAux->ultimo + 1) % 100);
    filaAux->elementos[posicao] = info;
    filaAux->ultimo = posicao;
    filaAux->tamanhoFila++;
  }
}

void remover(tipoFila *filaAux) {
  if (filaAux->tamanhoFila > 1) {
    filaAux->primeiro = filaAux->primeiro + 1;
    filaAux->tamanhoFila--;
  } else {
    filaAux->ultimo = -1;
    filaAux->primeiro = -1;
    filaAux->tamanhoFila--;
  }
}

void imprime(tipoFila *filaAux) {
  for (int i = filaAux->ultimo; i >= filaAux->primeiro; i--) {
    printf("%d ", filaAux->elementos[i]);
  }

}



// ###################### Funcoes e Procedimentos do programa ##############
void organiza(tipoFila *filaAux) {
  int temp;
  temp = filaAux->elementos[filaAux->primeiro];
  for (int i = filaAux->primeiro; i < filaAux->ultimo; i++) {

    filaAux->elementos[i] = filaAux->elementos[i + 1];
  }
  filaAux->elementos[filaAux->ultimo] = temp;
}



// ############################ Principal ###################################
int main(void) {
  int variavel, variavel1;
  tipoFila Fila;
  iniciaFila(&Fila);
  scanf("%d", &variavel);
  for (int i = 0; i < variavel; i++) {
    scanf("%d", &variavel1);
    if (variavel1 == 1) {
      insere(&Fila);
    }
    if (variavel1 == 2) {
      if (filaVazia(&Fila) == 1) {
        printf("vazia\n");
      } else {
        remover(&Fila);
      }
    }
    if (variavel1 == 3) {
      if (filaVazia(&Fila) == 1) {
        printf("vazia\n");
      } else {
        organiza(&Fila);
      }
    }
  }
  if (filaVazia(&Fila) == 1)
  {
    return 0;
  }
  else{
  imprime(&Fila);
    }
  return 0;
}