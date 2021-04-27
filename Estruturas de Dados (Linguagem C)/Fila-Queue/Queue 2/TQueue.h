#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3

#include "aluno.h"

typedef struct queue Queue;

Queue *queue_create(); //Cria a fila
int queue_free(Queue *qu); //Libera a fila

int queue_push(Queue *qu, Aluno al); //Insere na fila
int queue_pop(Queue *qu); //Remove da fila

int queue_top(Queue *qu, Aluno *al); //Retorna o primeiro elemento inserido, aquele que esta a mais tempo na fila

int queue_empty(Queue *qu); //Retorna 1 se a lista está vazia, e 0 caso contrário
int queue_size(Queue *qu); //Retorna o tamanho da fila

