#ifndef ListaSequencialh
#define ListaSequencialh

#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include"aluno.h"

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_RANGE -2
#define ELEM_NOT_FOUND -3

#define MAX 100

typedef struct Lista Lista;

Lista *cria_lista();
int libera_lista(Lista *li);
void imprime_lista(Lista *li);
int insere_lista_final(Lista *li, aluno al);
int insere_lista_inicio(Lista *li, aluno al);
int insere_lista_ordenada(Lista *li, aluno al);
int consulta_lista_pos(Lista *li, int pos, aluno *al);
int consulta_lista_final(Lista *li, aluno *al);
int consulta_lista_mat(Lista *li, int mat, aluno *al);
int remove_lista(Lista *li, int mat);
int remove_lista_otimizado(Lista *li, int mat);
int remove_lista_inicio(Lista *li);
int remove_lista_final(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);


#endif