#ifndef TStackh
#define TStackh

#include "aluno.h"
#include <stdlib.h>

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_RANGE -2
#define ELEM_NOT_FOUND -3

typedef struct TStack TStack;

TStack *stack_create();
int stack_free(TStack *st); 
//Função de inserção:
int stack_push(TStack *st, aluno al);
//Função de remoção:
int stack_pop(TStack *st);

int stack_top(TStack *st, aluno *al); //Acessando o aluno que esta no topo da lista

int stack_empty(TStack *st); //Retorna 0 caso a lista esteja vazia e retorna 1 caso não esteja, e retorna um numero negativo em caso de erro
int stack_size(TStack *st); //Tamanho da lista

#endif
