#ifndef Tlinkedh
#define Tlinkedh

#include<stdlib.h>
#include<stdio.h>
#include "aluno.h"

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct list List;
typedef struct node Node;

int list_print(List *li); //Imprime a lista
List *list_create(); //Cria a lista 
int list_free(List *li); //Libera a lista e seus nós
int list_push_front(List *li, Aluno al); //Insere no inicio
int list_push_back(List *li, Aluno al); //Insere no final 
int list_pop_front(List *li); //Remove do inicio 
int list_pop_back(List *li); //Remove do Final
int list_size(List *li); //Calcula o tamanho da lista
int list_insert_sorted(List *li, Aluno al); //Insere numa lista ordenada de forma ordenada
int list_insert(List *li, int pos, Aluno al); //Insere em uma determinada posição 
int list_get_pos(List *li, int nmat, int *pos); //Dado um número de matrícula, retornar a posição na lista
int list_find_pos(List *li, int pos, Aluno *al); //Achar um aluno dado uma posição 
int list_find_mat(List *li, int nmat, Aluno *al); //Achar um aluno dado seu numero de matricula
int list_front(List *li, Aluno *al); //Pega o primeiro aluno da lista
int list_back(List *li, Aluno *al); //Pega o último aluno da lista
int list_erase_data(List *li, int mat); //Apaga um aluno dado um numero de matricula do mesmo 
int list_erase_pos(List *li, int pos); //Apaga um aluno dado sua posição na lista
int list_empty(List *li); //Retorna 0 se a lista estiver vazia e 1 caso o contrario!

#endif