#ifndef _BARALHO_H
#define _BARALHO_H

#include "carta.h"

#define NUM_CARTAS  (NUM_NAIPES*NUM_VALORES) /*numero de cards em um baralho*/
#define N           10000 /*numero de iteracoes no embaralhamento*/

Carta *inicializa_baralho(); /*cria um baralho no estado inicial*/
void imprime_baralho(Carta *baralho); /*imprime todas as cartas do baralho*/
void embaralha(Carta *baralho); /*embaralha um baralho*/
void troca_cartas(Carta *baralho, int x, int y); /*troca de posicao duas cartas
  do baralho (carta na posicao x com a carta na posicao y) */
void libera_baralho(Carta **baralho); /*libera um baralho*/

#endif
