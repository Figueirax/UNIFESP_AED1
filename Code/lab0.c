#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct sapatos {
  int numero;
  int sexo;
};
typedef struct sapatos tipoSapatos;
tipoSapatos *pSapatos;

void converte(tipoSapatos *pSapatos, int nsapatos, float keep[100],
              float keep1[100], int cont, int cont1) {
  int i,contF=0,contM=0;
  float temp, tempo;
  float CV;
  float CA;
  for (int i = 0; i < nsapatos; i++) {
    if (pSapatos[i].sexo == 1 && pSapatos[i].numero != NULL) {
      CV = ((((pSapatos[i].numero * 6.67) + 19) / 25.4) * 3) - 23;
      CA = CV - floor(CV);
      if (CA >= 0 && CA < 0.4) {
        keep[i] = round(CV);
      } else if (CA >= 0.4 && CA < 0.8) {
        keep[i] = floor(CV) + 0.5;
      } else if (CA >= 0.8) {
        keep[i] = round(CV);
      }
      contF=1;
    }
  }

  if(contF>0){
    printf("F ");
  }
  
  for (i = 0; i < nsapatos; i++) {
    for (int j = i + 1; j < nsapatos; j++) {
      if (pSapatos[i].numero == pSapatos[j].numero && pSapatos[i].sexo == 1 &&
          pSapatos[j].sexo == 1) {
        cont1++;
        pSapatos[i].numero = NULL;
      }
    }

    if (pSapatos[i].sexo == 1 && pSapatos[i].numero != NULL) {
      printf("%.1f-(%d) ", keep[i], cont1);
      cont1=1;
    }
  }

  for (int i = 0; i < nsapatos; i++) {
    if (pSapatos[i].sexo == 0 && pSapatos[i].numero != NULL) {
      CV = ((((pSapatos[i].numero * 6.67) + 19) / 25.4) * 3) - 24;
      CA = CV - floor(CV);
      if (CA >= 0 && CA < 0.4) {
        keep1[i] = round(CV);
      } else if (CA >= 0.4 && CA < 0.8) {
        keep1[i] = floor(CV) + 0.5;
      } else if (CA >= 0.8) {
        keep1[i] = round(CV);
      }
      contM=1;
    }
  }
  if(contF>0 && contM>0){
    printf("\n");
  }
  if (contM>0) {
    printf("M ");
  }

  for (int i = 0; i < nsapatos; i++) {
    for (int j = i + 1; j < nsapatos; j++) {
      if (pSapatos[i].numero == pSapatos[j].numero && pSapatos[i].sexo == 0 &&
          pSapatos[j].sexo == 0) {
          cont++;
          pSapatos[i].numero = NULL;
      }
    }
    if (pSapatos[i].sexo == 0 && pSapatos[i].numero != NULL) {
      printf("%.1f-(%d) ", keep1[i], cont);
      cont=1;
    }
  }
}
int main() {
  int nsapatos, tempo, numero[100], sexo[100], cont = 1, cont1 = 1;
  float numeroc, numeroc1, temp, keep[100], keep1[100];
  scanf("%d", &nsapatos);
  pSapatos = (tipoSapatos *)malloc(sizeof(tipoSapatos) * nsapatos);

  for (int i = 0; i < nsapatos; i++) {
    scanf("%d", &pSapatos[i].numero);
    scanf("%d", &pSapatos[i].sexo);
  }

  for (int i = 0; i < nsapatos; i++) {
    for (int j = i + 1; j < nsapatos; ++j) {
      if (pSapatos[i].numero > pSapatos[j].numero) {
        int aux;
        int temp;
        temp = pSapatos[i].sexo;
        pSapatos[i].sexo = pSapatos[j].sexo;
        pSapatos[j].sexo = temp;
        aux = pSapatos[i].numero;
        pSapatos[i].numero = pSapatos[j].numero;
        pSapatos[j].numero = aux;
      }
    }
  }
  converte(pSapatos, nsapatos, keep, keep1, cont, cont1);
}