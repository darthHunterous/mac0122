#include <stdio.h>
#include "carta.h"

char converte_naipe(int naipe){
  /*converte o naipe para um char
    ESPADAS = e
    OURO = o
    PAUS = p
    COPAS = c
  */
  switch(naipe){
    case ESPADAS:
      return 'e';
    case OURO:
      return 'o';
    case PAUS:
      return 'p';
    case COPAS:
      return 'c';
    default:
      return ' ';
  }
}

void imprime_carta(Carta carta){
  printf("%d", carta.valor);
  printf("%c", converte_naipe(carta.naipe));
}
