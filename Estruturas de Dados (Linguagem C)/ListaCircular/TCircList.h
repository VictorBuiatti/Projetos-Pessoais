#include "aluno.h"

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define INVALID_POS -5

typedef struct list List;

List *list_create(); //Cria a Lista
int list_free(List *li); //Libera a lista

int list_push_front(List *li, Aluno al); //Insere no inicio da lista
int list_push_back(List *li, Aluno al); //Insere no final da lista
int list_insert(List *li, Aluno al, int pos); //Insere na lista dada uma posição

int list_pop_front(List *li); //Remove o primeiro elemento da lista
int list_pop_back(List *li); //Remove o ultimo elemento da lista
int list_erase_pos(List *li, int pos); //Remove um elemento dado a sua posição 
int list_erase_data(List *li, int nmat); //Remove um aluno dado a sua matricula 

int list_front(List *li, Aluno *al); //Retorna o primeiro elemento da lista
int list_back(List *li, Aluno *al); //Retorna o ultimo elemento da lista
int list_find_pos(List *li, int pos, Aluno *al); //Retorna um aluno dada a sua posição
int list_find_mat(List *li, int nmat, Aluno *al); //Retorna um aluno dado o seu numero de matricula
int list_get_pos(List *li, int nmat, int *pos); //Dado um número de matrícula, retornar a posição a lista

int list_size(List *li); 
int list_empty(List *li); //Retorna 1 se a lista está vazia, e 0 caso o contrário!

//Fazendo o cálculo do tamanho da lista sem utilizar a variável li->size, da estrutura da lista
int list_size_alternative(List *li); 

void list_print(List *li); //Printa a lista, apenas para testes

/* Função exigida no exercicio 2 da prática, função que
retornará sempre o próximo elemento. Por exemplo, se a lista não foi percorrida ainda, o
próximo elemento é a cabeça. */
int list_next_elem(List *li, Aluno *al); 



