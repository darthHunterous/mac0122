/*
  *
  * AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP,
  * DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA.
  * TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM
  * DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  * E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  * POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  * SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM
  * REPROVAÇÃO DIRETA NA DISCIPLINA.
  *
  * Nome: Edio Cerati Neto
  * NUSP: 9762678
  *
  * readme.txt, rat.c, ratbetter.c, e.c, sqrt.c
  */

#include "RAT.h"
#include <stdio.h>

/* O programa recebe o valor de n digitado pelo usuario e exibe como saida as
primeiras n aproximacoes para o valor de e */
int main () {

  int leitura;
  unsigned long n, i;
  Rational e, r_next;

  e = RATinit(1, 1);
  r_next = RATinit(1,1);

  /* Como a funcao scanf necessariamente retorna um valor referente ao estado
  da leitura do numero efetuada, a variavel leitura foi inserida para evitar
  o warning recebido sem sua utilizacao, todavia, conforme enunciado, ela nao
  se preocupa em obter consistencia plena dos dados inseridos pelo usuario.
  Pressupoe-se a insercao de dados validos. */
  printf("Insira o valor das n aproximacoes de e a serem feitas: ");
  leitura = scanf("%lu", &n);
  while (!leitura) {
    printf("\nValor inserido invalido. Insira um novo: ");
    leitura = scanf("%lu", &n);
  }

  RATshow(e);

  for (i = 1; i < n; i++) {
      r_next.den *= i;
      e = RATadd(e, r_next);
      RATshow(e);
  }

  return 0;
}
