#include "TQueue.h"
#include <stdlib.h>

typedef struct dqnode DQNode;

struct dqnode{
	DQNode *next;
	Aluno data;
};

struct queue{
	DQNode *begin;
	DQNode *end;
	int size;
};

Queue *queue_create(){
	Queue *qu;

	qu = malloc(sizeof(Queue));
	if(qu!=NULL){
		qu->begin = NULL;
		qu->end = NULL;
		qu->size = 0;
	}//if

	return qu;
}//queue create

int queue_free(Queue *qu){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	DQNode *aux = qu->begin;
	DQNode *baux = NULL;
	while(aux!=NULL){
		baux = aux;
		aux = aux->next;
		free(baux);
	}//while
	free(qu);

	return SUCCESS;
}//queue free

int queue_push(Queue *qu, Aluno al){ //Inserindo sempre no final

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	DQNode *no;
	no = malloc(sizeof(DQNode));
	if(no==NULL){
		return OUT_OF_MEMORY;
	}//não foi possivel criar o no

	no->data = al;
	if(qu->size==0){
		qu->begin = no;
		qu->end = no;
		no->next = NULL;
	}else{
		qu->end->next = no;
		no->next = NULL;
		qu->end = no;
	}//if else
	qu->size++;

	return SUCCESS;
}//queue push

int queue_pop(Queue *qu){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}else if(qu->size==0){
		return OUT_OF_RANGE; //Caso a lista esta vazia 
	}//if else

	DQNode *aux = qu->begin;
	if(qu->size==1){
		qu->begin = NULL;
		qu->end = NULL;
	}else{
		qu->begin = aux->next;
	}//if else
	free(aux);
	qu->size--;

	return SUCCESS;
}//queue pop

int queue_top(Queue *qu, Aluno *al){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}else if(qu->size==0){
		return OUT_OF_RANGE; //Caso a lista esta vazia 
	}//if else

	*al = qu->begin->data;

	return SUCCESS;
}//queue top

int queue_empty(Queue *qu){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(qu->size==0){
		return 1;
	}else{
		return 0;
	}//if else
}//queue empty

int queue_size(Queue *qu){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}else{
		return qu->size;
	}//if else
}//queue size