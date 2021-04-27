#include<stdlib.h>
#include<unistd.h> 
#include<time.h>

typedef struct TMat2d TMat2d;

TMat2d *create(int linha, int coluna); //Cria a matriz
int destroy(TMat2d *mat); //"Destroi" a matriz
int set_value(int lin, int col, TMat2d *mat, double num);
int get_value(int lin, int col, double *num, TMat2d *mat);
int random(double min, double max, TMat2d *mat); 
int sum(TMat2d *mat, TMat2d *mat2, TMat2d *mat3); //mat3 é o resultado da soma das duas matrizes
int multiplies(TMat2d *mat, TMat2d *mat2, TMat2d *mat3); //mat3 é o resultado da multiplicação de mat por mat2
int mult_escalar(TMat2d *mat, TMat2d *mat_result, double num); //mat_result é a matriz original multiplicada pelo escalar
int calculate_dash(TMat2d *mat, double *result); //Result retorna o valor do traço da matriz
double *vector_sum_lines(TMat2d *mat); //Retorna o vetor com a soma das linhas
double *vector_sum_column(TMat2d *mat); //Retorna o vetor com a soma das colunas (cada posição do vetor equivale a 1 coluna, por exemplo, a posição 1, equivale a coluna 1)