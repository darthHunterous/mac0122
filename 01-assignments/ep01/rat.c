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

/* Funcao que recebe dois numeros inteiros, correspondentes ao numerador
e denominador de um numero racional e os aloca em uma estrutura do tipo
numero racional, retornando-a */
Rational RATinit(unsigned long numerator, unsigned long denominator) {

  Rational r;

  r.num = numerator;
  r.den = denominator;

  return r;
}

/* Funcao que recebe um numero racional e o imprime na forma p/q */
void RATshow(Rational r) {

  printf("%lu/%lu ", r.num, r.den);

}

/* Funcao que recebe dois numeros racionais e devolve outro equivalente
a sua soma */
Rational RATadd(Rational r1, Rational r2){

  Rational r;
  unsigned long mmc = 1, i, r1_aux = r1.den, r2_aux = r2.den;

  for (i = 2; r1_aux > 1 || r2_aux > 1; i++) {
    while (r1_aux % i == 0 || r2_aux % i == 0){
      mmc *= i;
      if (r1_aux % i == 0)
        r1_aux /= i;
      else
        r2_aux /= i;
    }
  }

  r.den = mmc;
  r.num = (r.den/r1.den) * r1.num + (r.den/r2.den) * r2.num;

  return r;
}

/* Funcao que recebe dois numeros racionais e devolve outro equivalente
a sua multiplicacao */
Rational RATmul(Rational r1, Rational r2) {

  Rational r;

  r.num = r1.num * r2.num;
  r.den = r1.den * r2.den;

  return r;
}

/* Funcao que recebe dois numeros racionais e devolve outro correspondente
a divisao entre eles */
Rational RATdiv(Rational r1, Rational r2) {

  Rational r;
  unsigned long aux;

  aux = r2.num;
  r2.num = r2.den;
  r2.den = aux;

  r.num = r1.num * r2.num;
  r.den = r1.den * r2.den;

  return r;
}
