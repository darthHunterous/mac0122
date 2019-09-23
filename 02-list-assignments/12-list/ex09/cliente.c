#include "carta.h"
#include "baralho.h"

int main(){
  Carta *baralho; /*baralho e' um vetor de cartas*/
  baralho = inicializa_baralho();
  embaralha(baralho);
  /*TODO: chamar os algoritmos de ordenacao*/
  imprime_baralho(baralho);

  libera_baralho(&baralho);

  return 0;
}
