/*
O efeito observado de cair pela metade foi explicado melhor nos comentarios
do programa do ex15, todavia, nota-se que tal efeito advem do fato de estarmos
executando a transformacao dos multiplos em zero, uma vez que nao sao primos,
apenas para os valores ainda nao transformados.
A partir do momento em que um multiplo ja recebeu o valor zero, é redundante
percorrer os seus multiplos, exemplo:
Apos zerar todos os multiplos de 2, faz-se redundante zerar todos os multiplos
dos multiplos de 2, como 4, 8, etc, uma vez que todos os multiplos desses
numeros tambem sao multiplos de 2
*/
