#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "interface.h"

/* ponteiro para a estrutura que representa o diretorio atual*/
link diretorioAtual = NULL;
/* ponteiro para a estrututa que representa a raiz dos diretorios */
link raiz = NULL;

/* funcao chamada no comeco, que inicializa a raiz do diretorio, alocando a
memoria adequadamente e inicializando seus elementos*/
void inicializaRaiz () {
  diretorioAtual = malloc(sizeof(*diretorioAtual) + sizeof(char) * MAX);
  strcpy(diretorioAtual->name, "ROOT");
  diretorioAtual->size = 0;
  diretorioAtual->sibling = NULL;
  diretorioAtual->child = NULL;
  raiz = diretorioAtual;
}

/* funcao que recebe uma string correspondente ao nome do diretorio
a ser criado. O diretorio e' representado como um arquivo de tamanho nulo,
sendo criado no diretorio atual */
void criaDiretorio(char nome[]) {
  criaArquivo(nome, 0);
}

/* funcao que recebe uma string e um inteiro, criando um arquivo no diretorio
atual com tal nome e tamanho especificado em KB */
void criaArquivo(char nome[], int tamanho) {
  link t;

  t = diretorioAtual;

  if(t->child == NULL) {
    t->child = malloc(sizeof(*t) + MAX);
    t = t->child;

  }
  else {
    t = t->child;
    while (t->sibling != NULL)
      t = t->sibling;
    t->sibling = malloc(sizeof(*t) + MAX);
    t = t->sibling;
  }

  strcpy(t->name, nome);
  t->size = tamanho;

  t = NULL;
}

/* funcao que imprime todos os filhos do diretorio atual, retornando o valor
zero caso nao haja e 1 caso eles existam */
int imprimeFilhos() {
  int i;
  link t;

  t = diretorioAtual->child;

  if(t == NULL)
    return 0;

  printf("\n  Arquivos em %s:", diretorioAtual->name);

  for(i = 0; t != NULL; i++){
    printf("\n(%d)    %s", i, t->name);
    if (t->size != 0)
      printf(" (%d KB)", t->size);
    t = t->sibling;
  }

  t = NULL;
  return 1;
}

/* funcao que recebe o indice equivalente ao diretorio filho que se deseja
mudar para, retornando zero caso tal diretorio nao seja valido para
transferencia (arquivo) e retornando 1 em caso de exito */
int mudaDiretorio(int indice){
  int i;
  link t = diretorioAtual;

  diretorioAtual = diretorioAtual->child;
  for (i = 0; i < indice; i++)
    diretorioAtual = diretorioAtual->sibling;

  if(diretorioAtual->size != 0){
    printf("\n  Indice inserido equivale a um arquivo. Repita a operacao\n");
    diretorioAtual = t;
    return 0;
  }

  t = NULL;
  return 1;
}

/* funcao que torna a raiz dos diretorios o diretorio atual */
void retornaRaiz() {
  diretorioAtual = raiz;
}

/* funcao que imprime os elementos no diretorio atual, evocando outra, de
maneira a manter a modelagem da ADT como um tipo opaco de dados, ou seja,
impede o acesso direto do cliente a estrutura de dados */
void imprimeHierarquia() {
  imprimeArvoreRecursivamente(diretorioAtual, 1);
}

/* funcao que recebe um ponteiro para uma arvore e a indentacao necessaria
para imprimir a hierarquia do diretorio recursivamente */
void imprimeArvoreRecursivamente (link t, int indentacao) {
  int i;
  link aux = t;

  if(aux == NULL)
    return;
  if(aux == diretorioAtual->sibling)
    return;

  for (i = 0; i < indentacao; i++)
    printf("  ");
  printf("%s", aux->name);
  if(aux->size != 0)
    printf(" (%dKB)", aux->size);
  printf("\n");
  indentacao++;

  imprimeArvoreRecursivamente(aux->child, indentacao);
  imprimeArvoreRecursivamente(aux->sibling, indentacao - 1);
}

/* funcao que imprime o tamanho do diretorio atual atraves da execucao de uma
outra funcao recursiva, de forma a ocultar a estrutura de dados do cliente
(tipo opaco de dados) */
void calculaTamanho() {
  int tam;
  tam = calculaTamanhoRecursivamente(diretorioAtual);
  printf("\n  Tamanho do diretorio atual: %d KB\n", tam);
}

/* funcao que recebe um ponteiro para uma arvore (representando o diretorio
atual) e retorna recursivamente o tamanho em KB do diretorio e subdiretorios
somados */
int calculaTamanhoRecursivamente(link t) {
  link aux = t;
  int tam = 0;

  if(aux == NULL)
    return 0;
  if(aux == diretorioAtual->sibling)
    return 0;

  tam += aux->size;

  return (tam + calculaTamanhoRecursivamente(aux->child) + calculaTamanhoRecursivamente(aux->sibling));
}

/* funcao que evoca outra funcao recursiva, responsavel por apagar todo
o conteudo do diretorio atual, impedindo acesso direto do cliente a estrutura
de dados (tipo opaco de dados) */
void apagaArquivos() {
  apagaArquivosRecursivamente(diretorioAtual);
}

/* funcao que recebe um ponteiro para uma arvore e apaga todos os nos ligados
ao no passado como parametro, de forma recursiva, liberando a memoria ao final
do uso */
void apagaArquivosRecursivamente(link t) {
  link aux;

  if(t == NULL)
    return;

  if(t->child == NULL)
    apagaArquivosRecursivamente(t->sibling);
  if(t->sibling == NULL)
    apagaArquivosRecursivamente(t->child);

  if(t->sibling == NULL && t->child == NULL)
    return;

  aux = t->child;
  t->child = NULL;
  free(aux);
}

/* funcao que imprime o nome do diretorio atual */
void imprimeStringDiretorioAtual() {
    printf("%s", diretorioAtual->name);
}

/* as funcoes abaixo faziam parte do template fornecido para o cliente e foram
movidas para a implementacao dado a modelagem dos dados como um tipo abstrato
*/
void imprimeDiretorioAtual(){
  printf("\n====================================================\n");
  printf("\n  Diretorio atual: %s\n", diretorioAtual->name);
}

void imprimeOperacoes(int imprimir){
  if(imprimir){
    printf("\n  (1) Criar um diretorio\n");
    printf("  (2) Criar um arquivo\n");
    printf("  (3) Mudar diretorio atual\n");
    printf("  (4) Voltar para o diretorio raiz\n");
    printf("  (5) Imprimir os elementos no diretorio atual\n");
    printf("  (6) Imprimir hierarquia do diretorio atual\n");
    printf("  (7) Calcular o tamanho do diretorio atual\n");
    printf("  (8) Apagar todos os elementos do diretório atual\n");
    printf("  (9) Imprimir/nao imprimir estas instrucoes\n");
    printf("  (0) Sair do programa\n");
    printf("\n  Digite uma operacao: ");
  }
}

void imprimeNomeDiretorio(int imprimir){
  if(imprimir){
    printf("\n  Digite o nome do diretorio: ");
  }
}

void imprimeNomeArquivo(int imprimir){
  if(imprimir){
    printf("\n  Digite o nome do arquivo: ");
  }
}

void imprimeTamanho(int imprimir){
  if(imprimir){
    printf("\n  Digite o tamanho do arquivo: ");
  }
}

void imprimeMudaDiretorio(int imprimir){
  if(imprimir){
    printf("\n  Digite o indice do diretório: ");
  }
}

void leInt(int *v){
  if(scanf("%d", v) != 1){
    printf("\n  Erro de leitura de inteiro\n");
  }
}

void leString(char nome[]){
  if(scanf("%s", nome) != 1){
    printf("\n  Erro de leitura de string\n");
  }
}
