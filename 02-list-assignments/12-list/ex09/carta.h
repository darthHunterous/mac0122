#ifndef _CARTA_H
#define _CARTA_H

typedef struct carta Carta;

#define ESPADAS 1
#define OURO    2
#define PAUS    3
#define COPAS   4

#define NUM_NAIPES  4
#define NUM_VALORES 13

/*
  valores:
  A = 1
  J = 11
  Q = 12
  K = 13
*/

struct carta{
  int valor;
  int naipe;
};

void imprime_carta(Carta carta); /*imprime a carta (valor e naipe)*/

#endif
