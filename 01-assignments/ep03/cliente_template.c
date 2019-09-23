#include <stdio.h>
#include "interface.h"

void prompt(){
  int operacao;
  int tamanho;
  int imprimir;
  char nome[MAX];

  imprimir = 1;

  /* inicializa a raiz do diretorio, alocando memoria */
  inicializaRaiz();

  do{
    imprimeDiretorioAtual();
    imprimeOperacoes(imprimir);
    leInt(&operacao);
    switch (operacao){
      case 1:
        imprimeNomeDiretorio(imprimir);
        leString(nome);
        criaDiretorio(nome);
        printf("\n  Diretorio %s criado!\n", nome);
        break;
      case 2:
        imprimeNomeArquivo(imprimir);
        leString(nome);
        imprimeTamanho(imprimir);
        leInt(&tamanho);
        criaArquivo(nome, tamanho);
        printf("\n  Arquivo %s criado! (%d KB)\n", nome, tamanho);
        break;
      case 3:
        if(!imprimeFilhos()) {
          printf("\n  Nao ha diretorios filhos\n");
          break;
        }
        imprimeMudaDiretorio(imprimir);
        leInt(&tamanho);
        if(!mudaDiretorio(tamanho))
          break;
        printf("\n  Mudou para o diretorio ");
        imprimeStringDiretorioAtual();
        printf("!\n");
        break;
      case 4:
        retornaRaiz();
        printf("\n  Mudou para o diretorio raiz!\n");
        break;
      case 5:
        if(!imprimeFilhos())
          printf("\n  Nao ha diretorios filhos\n");
        break;
      case 6:
        printf("\n  Hierarquia do diretorio atual:\n\n");
        imprimeHierarquia();
        break;
      case 7:
        calculaTamanho();
        break;
      case 8:
        apagaArquivos();
        printf("\n  Todos os itens do diretorio atual foram removidos!\n");
        break;
      case 9:
        imprimir = !imprimir;
        printf("\n  Variavel imprimir modificada para %d!\n", imprimir);
        break;
      case 0:
        printf("\n  O programa foi encerrado.\n");
        break;
      default:
        printf("\n  Operacao invalida (%d)!\n", operacao);
        break;
    }
  } while(operacao != 0);

  /* retorna o diretorio atual a raiz para em seguida, apagar todos os nos e
  liberar a memoria devidamente */
  retornaRaiz();
  apagaArquivos();

}

int main(){
  prompt();

  printf("\n");
  return 0;
}
