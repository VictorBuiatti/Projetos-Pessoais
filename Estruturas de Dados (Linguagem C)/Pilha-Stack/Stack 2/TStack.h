#ifndef TStackh
#define TStackh

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3

#include "aluno.h"
#include <stdlib.h>

typedef struct TStack TStack;

TStack *stack_create(); //Cria a pilha
int stack_free(TStack *st); //Libera a pilha

int stack_push(TStack *st, Aluno al); //Insere 
int stack_pop(TStack *st); //Remove um aluno

int stack_top(TStack *st, Aluno *al); //Retorna o aluno que esta no topo da pilha

int stack_size(TStack *st); //Tamanho da pilha
int stack_empty(TStack *st); //Retorna 0 se a pilha esta vazia e retorna 1 caso contrario 

#endif