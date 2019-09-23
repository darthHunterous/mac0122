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
  * client.c, implement.c, itnerface.h
  *
  * Referências: Com exceção das rotinas fornecidas em sala
  * de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  * para que o seu programa não seja considerada plágio.
  * 
  * - Algorithms in C, Sedgewick
  * - Notas de Aula, MAC0122   
  *
  */
  
1. A ADT foi composta por meio de um tipo opaco de dados, ou seja, o cliente nao acessa diretamente a estrutura de dados usada para representar a arvore do diretorio, como ponteiros, etc.
  Cada no da arvore e' uma estrutura composta por um inteiro, que representa o tamanho do arquivo (ou zero em caso de diretorios), um ponteiro para outra estrutura (link), que aponta para um eventual diretorio filho (link child) e outro que aponta para um eventual no irmao (link sibling). Tambem ha uma string alocada dinamicamente, de acordo com o tamanho do diretorio a ser criado quando tal funcao e' chamada.
  
2. O Sistema Operacional utilizado para compilar o programa foi o Ubuntu 16.04 LTS

3. O programa foi compilado atraves do terminal.

4. O programa foi compilado com o comando
  gcc -Wall -ansi -pedantic -O2 client.c implement.c -o directory
  E depois executado com
  ./directory
  (Supoe-se o usuario estar no diretorio em que se encontram os arquivos do programa)
  Nao houveram erros de sintaxe ou warnings, compilando e executando conforme o esperado.
