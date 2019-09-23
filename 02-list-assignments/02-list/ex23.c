#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float randFloat();
float distance (float **mat, int dim, int i, int j);

int main(int argc, char *argv[]) {

  float d, dmin = 2, dis;
  int i, j, k, cnt = 0, N, dim;

  printf("Insira o numero de pontos, distancia entre eles e dimensao: ");
  scanf ("%d %f %d", &N, &d, &dim);

  srand(time(NULL));

  float **mat = (float **)malloc(N*sizeof(float*));
  for (i = 0; i < N; i++) mat[i] = (float *)malloc(dim*sizeof(float));

  float *min1 = malloc(dim*sizeof(float*));
  float *min2 = malloc(dim*sizeof(float*));

  for (i = 0; i < N; i++)
    for (j = 0; j < dim; j++)
      mat[i][j] = randFloat();

  for (i = 0; i < N; i++)
    for (j = i+1; j < N; j++){
      dis = distance(mat, dim, i, j);
      if (dis < d) cnt++;
      if (dis < dmin) {
        dmin = dis;
        for (k = 0; k < dim; k++) {
        min1[k] = mat[i][k];
        min2[k] = mat[j][k];
        }
      }
    }

  printf("\n%d edges shorter than %f\n", cnt, d);

  printf("\nclosest points are (%f", min1[0]);
  for (i = 1; i < dim; i++)
    printf (", %f", min1[i]);
  printf (") and (%f", min2[0]);
  for (i = 1; i < dim; i++)
    printf (", %f", min2[i]);
  printf (")");

  printf("\n%f units far from each other", dmin);

  printf ("\n");
  return 0;
}

float randFloat() {
  return 1.0*rand()/RAND_MAX;
}

float distance (float **mat, int dim, int i, int j) {

  int k;
  float soma = 0;

  for (k = 0; k < dim; k++)
    soma += (mat[i][k]-mat[j][k])*(mat[i][k]-mat[j][k]);

  return sqrt(soma);
}
