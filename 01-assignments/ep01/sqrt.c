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

/* O programa recebe 4 valores digitados pelo usuario, equivalentes ao numero
S de que se deseja obter a raiz quadrada, o numero n de aproximacoes a serem
feitas pela recorrencia do metodo babilonico, e o numerador e denominador do
numero racional x0, que serve como estimativa para a aproximacao. Como saida,
imprime a aproximacao da raiz de S em representacao fracionaria */
int main () {

  int leitura;
  unsigned long S, n, i;
  Rational x0, xn, meio, Srat;

  /* Como a funcao scanf necessariamente retorna um valor referente ao estado
  da leitura do numero efetuada, a variavel leitura foi inserida para evitar
  o warning recebido sem sua utilizacao, todavia, conforme enunciado, ela nao
  se preocupa em obter consistencia plena dos dados inseridos pelo usuario.
  Pressupoe-se a insercao de dados validos. */
  printf("Insira o numero de qual deseja obter-se a raiz, o numero de");
  printf(" aproximacoes por recorrencia, o numerador e denominador do chute ");
  printf("inicial racional, separados por um espaco: ");
  leitura = scanf("%lu %lu %lu %lu", &S, &n, &x0.num, &x0.den);
  while (!leitura) {
    printf("\nAlgum dos valores nao e' valido. Insira novamente: ");
    leitura = scanf("%lu %lu %lu %lu", &S, &n, &x0.num, &x0.den);
  }

  xn = x0;
  meio = RATinit(1,2);
  Srat = RATinit(S,1);

  for (i = 0; i < n; i++) {
    xn = RATmul(meio, RATadd(x0, RATdiv(Srat,x0)));
    x0 = xn;
  }

  RATshow(xn);

  return 0;
}
