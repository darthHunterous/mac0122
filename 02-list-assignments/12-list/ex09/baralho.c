#include "carta.h"
#include "baralho.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Carta *inicializa_baralho(){
  Carta *baralho;
  int valor, naipe, i;

  baralho = malloc(NUM_CARTAS*sizeof(Carta));

  i = 0;
  for(naipe = 1; naipe <= NUM_NAIPES; naipe++ ){
    for(valor = 1; valor <= NUM_VALORES; valor++){
      baralho[i].valor = valor;
      baralho[i].naipe = naipe;
      i++;
    }
  }
  return baralho;
}

void imprime_baralho(Carta *baralho){
  int i;
  printf("Baralho:\n");
  for(i = 0; i < NUM_CARTAS; i++){
    imprime_carta(baralho[i]);
    printf(" ");
  }
  printf("\n\n");
}

void troca_cartas(Carta *baralho, int x, int y){
  Carta aux;
  aux = baralho[x];
  baralho[x] = baralho[y];
  baralho[y] = aux;
}

void embaralha(Carta *baralho){
  int i, x, y;
  srand(time(NULL));

  for(i = 0; i < N; i++){
    x = rand()%NUM_CARTAS;
    y = rand()%NUM_CARTAS;
    troca_cartas(baralho, x, y);
  }
}

void libera_baralho(Carta **baralho){
  free(*baralho);
  *baralho = NULL;
}
