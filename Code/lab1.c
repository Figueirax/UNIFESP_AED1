
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################
struct listaES {
  int cont;
  int cont1, cont2;
  int tamanhoLista;
  int lista[10];
};
typedef struct listaES tipoLista;

void inicializaLista(tipoLista *listaAux) {
  listaAux->tamanhoLista = 0;
  for (int i = 0; i <= 10; i++) {
    listaAux->lista[i] = 0;
  }
}

void insereElemento(tipoLista *listaAux) {
  listaAux->tamanhoLista++;
  scanf("%d", &listaAux->lista[listaAux->tamanhoLista - 1]);
  if (listaAux->tamanhoLista > 10) {
    printf("Lista de reserva cheia\n");
    listaAux->tamanhoLista--;
  } else {
    if (listaAux->tamanhoLista <= 10) {
      printf("Sua reserva foi realizada\n");
      listaAux->cont1++;
    }
  }
}

void retiraElemento(tipoLista *listaAux) {
  int variavel2;
  listaAux->cont2 = 0;
  scanf("%d", &variavel2);
  for (int i = 0; i <= listaAux->tamanhoLista - 1; i++) {
    if (variavel2 == listaAux->lista[i]) {
      for (int j = i; j < listaAux->tamanhoLista - 1; j++) {
        listaAux->lista[j] = listaAux->lista[j + 1];
      }
      listaAux->tamanhoLista--;
      listaAux->cont++;
      listaAux->cont2++;
      printf("O livro foi retirado com sucesso\n");
    }
  }
  if (listaAux->cont2 == 0) {
    printf("Voce nao possui reserva desse livro\n");
  }
}

// ############################ Principal ###################################
int main() {
  tipoLista Lista;
  Lista.cont = 0;
  Lista.cont1 = 0;
  int nLivros, variavel1;
  inicializaLista(&Lista);

  scanf("%d", &nLivros);
  for (int i = 0; i < nLivros; i++) {
    scanf("%d", &variavel1);
    if (variavel1 == 1) {
      insereElemento(&Lista);
    }

    if (variavel1 == 2) {
      retiraElemento(&Lista);
    }
    if (variavel1 != 1 && variavel1 != 2) {
      break;
    }
  }
  printf("Voce realizou %d reservas e %d retiradas\n", Lista.cont1, Lista.cont);

  return 0;
}