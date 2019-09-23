#include <stdlib.h>
#include <stdio.h>
#include "Room.h"
#include "STACK.h"

int main (int argc, char *argv[]) {

  /* a variavel leitura foi inserida para conter o valor da funcao fscanf,
  testando se a leitura do arquivo txt foi feita corretamente */
  int n, m, i, corredorInicio, corredorFim, salaAtual, leitura;
  FILE* arquivo;
  Room *mapa;
  Item* y;

  /* testa se o nome do arquivo foi digitado */
  if (argc != 2) {
    printf ("Execute novamente com o arquivo txt a ser lido.\n");
    return 0;
  }

  /* testa se o arquivo digitado foi encontrado */
  arquivo = fopen(argv[1], "r");
  if (arquivo == NULL) {
    printf ("O arquivo nao foi encontrado. Execute novamente.\n");
    return 0;
  }

  /* le do arquivo txt externo o numero de sala e corredores */
  leitura = fscanf(arquivo, "%d", &n); /* salas */
  if (!leitura) {
    printf("A leitura do numero de salas falhou\n");
    return 0;
  }
  leitura = fscanf(arquivo, "%d", &m); /* corredores */
  if (!leitura) {
    printf("A leitura do numero de corredores falhou\n");
    return 0;
  }

  /* aloca um vetor de ponteiros para listas ligadas, cada elemento do vetor
  corresponde a uma sala. Cada elemento da lista ligada ao elemento do vetor
  representa uma sala adjacente */
  mapa = malloc(n * sizeof *mapa);

  /* linhas 35 a 53 leem do arquivo txt os corredores existentes e armazenam no
  vetor de listas ligadas que representa o labirinto */
  mapa[corredorInicio].adj = newNode(corredorFim);
  for (i = 0; i < n; i++) {
    mapa[i].adj = NULL;
  }

  for (i = 0; i < m; i++) {

    leitura = fscanf(arquivo, "%d", &corredorInicio);
    if (!leitura) {
      printf("A leitura do inicio do corredor %d falhou\n", i+1);
      return 0;
    }

    leitura = fscanf(arquivo, "%d", &corredorFim);
    if (!leitura) {
      printf("A leitura do final do corredor %d falhou\n", i+1);
      return 0;
    }

    if (mapa[corredorInicio].adj == NULL) {
      mapa[corredorInicio].adj = newNode(corredorFim);
    }
    else {
      y = mapa[corredorInicio].adj;
      while(y->next != NULL)
        y = y->next;
      y->next = newNode(corredorFim);
    }
  }
  y = NULL;

  /* linhas 57 a 77 percorrem o labirinto com o metodo equivalente a sempre
  estar com a mao direita na parede, percorrendo-o com o metodo da busca
  expandida */
  salaAtual = 0;
  printf("%d ", salaAtual);
  STACKinit();

  while(salaAtual != n-1) {
    y = mapa[salaAtual].adj;
    if (y == NULL || y->id == -1) {
      salaAtual = STACKpop();
      printf("%d ", salaAtual);
    }
    else {
      while (y->next != NULL && (y->next)->id != -1)
        y = y->next;
      STACKpush(salaAtual);
      salaAtual = y->id;
      printf("%d ", y->id);
      y->id = -1;
    }
  }
  y = NULL;

  /* desaloca o vetor */
  free(mapa);

  /* printf para separar a linha da saida do programa e linha de comando no
  terminal do Ubuntu 16.04 LTS */
  printf("\n");
  return 0;
}
