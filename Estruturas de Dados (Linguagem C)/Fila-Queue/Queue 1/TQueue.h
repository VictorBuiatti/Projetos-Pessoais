#ifndef tqueueh
#define tqueueh

#include "aluno.h"
#include <stdlib.h>

typedef struct tqueue TQueue;

TQueue *queue_create(); //Cria a fila
int queue_free(TQueue *qu); //Libera a fila

int queue_push(TQueue *qu, Aluno al); //Insere na fila
int queue_pop(TQueue *qu); //Remove da fila

int queue_top(TQueue *qu, Aluno *al); //Retorna o primeiro elemento inserido 

int queue_empty(TQueue *qu); //Retorna 1 se a lista está vazia, e 0 caso contrário
int queue_size(TQueue *qu); //Retorna o tamanho da fila

#endif
 
