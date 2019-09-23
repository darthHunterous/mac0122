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

/* Funcao que recebe dois numeros inteiros, correspondentes ao numerador e
denominador de um numero racional e retorna esse numero numa variavel estrutura
do tipo racional, simplificando a razao entre numerador e denominador se
possivel */
Rational RATinit(unsigned long numerator, unsigned long denominator) {

  Rational r, r_aux;
  unsigned long aux;

  r.num = numerator;
  r.den = denominator;
  r_aux = r;

  while(r_aux.num % r_aux.den != 0) {
      aux = r_aux.num % r_aux.den;
      r_aux.num = r_aux.den;
      r_aux.den = aux;
  }

  r.num /= r_aux.den;
  r.den /= r_aux.den;

  return r;
}

/* Funcao que recebe um numero racional e o imprime na forma p/q */
void RATshow(Rational r) {

  printf("%lu/%lu ", r.num, r.den);

}

/* Funcao que recebe dois numeros racionais e devolve sua soma, simplificando
a fracao se possivel */
Rational RATadd(Rational r1, Rational r2){

  Rational r, r_aux;
  unsigned long mmc = 1, i, r1den_aux = r1.den, r2den_aux = r2.den, aux;

  for (i = 2; r1den_aux > 1 || r2den_aux > 1; i++) {
    while (r1den_aux % i == 0 || r2den_aux % i == 0){
      mmc *= i;
      if (r1den_aux % i == 0)
        r1den_aux /= i;
      else
        r2den_aux /= i;
    }
  }

  r.den = mmc;
  r.num = (r.den/r1.den) * r1.num + (r.den/r2.den) * r2.num;

  r_aux = r;
  while(r_aux.num % r_aux.den != 0) {
      aux = r_aux.num % r_aux.den;
      r_aux.num = r_aux.den;
      r_aux.den = aux;
  }

  r.num /= r_aux.den;
  r.den /= r_aux.den;

  return r;
}

/* Funcao que recebe dois numeros racionais e devolve sua multiplicacao,
simplificando a fracao retornada, se possivel */
Rational RATmul(Rational r1, Rational r2) {

  Rational r, r_aux;
  unsigned long aux;

  r.num = r1.num * r2.num;
  r.den = r1.den * r2.den;

  r_aux = r;
  while(r_aux.num % r_aux.den != 0) {
      aux = r_aux.num % r_aux.den;
      r_aux.num = r_aux.den;
      r_aux.den = aux;
  }

  r.num /= r_aux.den;
  r.den /= r_aux.den;

  return r;
}

/* Funcao que recebe dois numeros racionais, invertendo numerador e denominador
do segundo, devolvendo a multiplicacao desses novo par de racionais, o que
equivale a divisao entre os numeros originalmente inseridos. A saida da funcao
equivale a uma fracao simplificada devido ao uso da funcao RATmul */
Rational RATdiv(Rational r1, Rational r2) {

  unsigned long aux;

  aux = r2.num;
  r2.num = r2.den;
  r2.den = aux;

  return RATmul(r1,r2);
}
