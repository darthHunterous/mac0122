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

--A compilacao dos arquivos referente ao exercicio-programa deve ser efetuada
com a utilizacao dos parametros:
-Wall -ansi -pedantic -O2
Os testes apos a conclusao demonstraram nenhum erro de sintaxe ou warning,
incluindo a utilizacao de uma variavel para armazenar o valor retornado pela
funcao scanf, evitando assim um warning desnecessario.

--Nao foi utilizado a IDE Codeblocks para fim de desenvolvimento deste EP, logo
nao foi enviado arquivo com o formato .cbp correspondente ao projeto.

--O arquivo da interface RAT.h nao foi alterado como pedido pelo enunciado,
todavia isso implicou que nao foi desenvolvida uma funcao adicional para a
simplificacao de fracoes cujos numeradores e denominadores sao multiplos entre
si. O mesmo e' valido para uma eventual funcao de calculo de MMC, todavia essa
omissao nao foi prejudicial em forma alguma a execucao do programa em si.

--A compilacao foi efetuada por meio do Terminal do sistema Linux, com as opcoes
gcc -Wall -ansi -O2 -pedantic rat.c e.c -o e
gcc -Wall -ansi -O2 -pedantic ratbetter.c e.c -o e
gcc -Wall -ansi -O2 -pedantic rat.c sqrt.c -o sqrt
gcc -Wall -ansi -O2 -pedantic ratbetter.c sqrt.c -o sqrt
Todas apresentaram sucesso de compilacao e execucao como esperado do cliente.

--Dada as simplificacoes das fracoes cujos numeradores e denominadores tem
divisor comum diferente de 1 na implementacao ratbetter.c, foi possivel notar
uma nitida melhora na eficiencia dos programas "e" e "sqrt". A velocidade de
calculo para um maior numero de interacoes aumentou, bem como a capacidade das
variaveis "unsigned int" apresentaram indicios de overflow apenas para maior
numero de aproximacoes efetuadas. Como a maior parte dos numeros racionais
utilizados pode ser simplificada, lidar com operacoes de fracoes menores foi
crucial para obter maior eficiencia, tanta na velocidade do calculo quanto no
armazenamento na memoria.
