#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct TDList TDList;

typedef struct{
	int matricula;
	char nome[50];
	float n1, n2, n3;
}Aluno;

TDList *list_create(); //Cria a lista

//Funções de Inserção 
int list_push_front(TDList *li, Aluno al); //Insere no inicio 
int list_push_back(TDList *li, Aluno al); //Insere no final
int list_insert(TDList *li, int pos, Aluno al); //Inserindo em uma determinada posição 
//Printando a lista
int list_print_forward(TDList *li); //Printa da forma convencional (do inicio ao final)
int list_print_reverse(TDList *li); //Printa a lista ao contrario (do ultimo elemento ao primeiro)
//Remoções
int list_pop_back(TDList *li); //Removendo do fim da lista
int list_pop_front(TDList *li); //Removendo do inicio (primeiro elemento da lista)
//Achando um aluno
int list_find_pos(TDList *li, int pos, Aluno *al); //Retorna um aluno em uma determinada posição 
int list_find_mat(TDList *li, int nmat, Aluno *al); //Retorna um aluno dado seu numero de matricula

int list_front(TDList *li, Aluno *al); //Retorna o Primeiro elemento da lista
int list_back(TDList *li, Aluno *al); //Retorna o ultimo elemento da lista
int list_size(TDList *li); //Retorna o tamanho da lista