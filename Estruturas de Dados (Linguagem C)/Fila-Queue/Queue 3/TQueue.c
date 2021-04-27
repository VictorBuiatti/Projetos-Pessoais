#include "TQueue.h"
#include <stdlib.h>
#include <math.h>

struct queue{
	int front;
	int rear;
	int size;
	Aluno *data;
	int max, actual; //Max é o tamanho inicial, o digitado pelo usuário na criação da fila, actual é o tamanho máximo atual da fila
};

Queue *queue_create(int value){
	if(value<=0){
		return NULL;
	}//Tamanho de Fila Inválido

	Queue *qu;

	qu = malloc(sizeof(Queue));
	if(qu!=NULL){
		qu->data = malloc(sizeof(Aluno)*value);
		if(qu->data!=NULL){
			qu->max = value;
			qu->actual = value;
			qu->size = 0;
			qu->front = 0;
			qu->rear = 0;
		}else{
			free(qu->data);
		}//if else
	}//if

	return qu;
}//queue create

int queue_push(Queue *qu, Aluno al){
	int var;

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(qu->size==qu->actual){
		var = queue_realloc(qu);
		if(var!=0){
			return var;
		}//if
	}//if

	qu->data[qu->rear] = al;
	qu->rear = (qu->rear+1)%qu->actual;
	qu->size++;

	return SUCCESS;
}//queue push

int queue_pop(Queue *qu){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}else if(qu->size==0){
		return OUT_OF_RANGE; //Fila vazia, não tem o que remover
	}//if else

	qu->front = (qu->front+1)%qu->actual;
	qu->size--;

	return SUCCESS;
}//queue pop

int queue_top(Queue *qu, Aluno *al){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}else if(qu->size==0){ //Caso a Lista esteja vazia
		return OUT_OF_RANGE;
	}//if else

	*al = qu->data[qu->front];

	return SUCCESS;
}//queue top

int queue_realloc(Queue *qu){
	void *test;

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	qu->actual += qu->max;
	test = realloc(qu->data,qu->actual*sizeof(Aluno));
	if(test==NULL){
		qu->actual = qu->actual - qu->max;
		return OUT_OF_MEMORY;
	}else{
		qu->data = test;
	}

	if(qu->front!=0){
		int j=qu->size;
		for(int i=0;i<qu->front;i++,j++){
			qu->data[j] = qu->data[i];
		}//for
		qu->rear = j;
	}else if(qu->rear==0){
		qu->rear = qu->size;
	}

	return SUCCESS;
}//queue realloc

int queue_compact(Queue *qu){
	int comp;

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}else if(qu->size>qu->actual-qu->max){
		return MAX_COMPRESSED_QUEUE; //Não é possível compactar mais a fila, ela já esta da forma mais compactada
	}//if else

	comp = (ceil((double)(qu->size/qu->max)))*qu->max;

	Aluno *new_data = malloc(sizeof(Aluno)*comp);
	if(new_data==NULL){
		return OUT_OF_MEMORY;
	}else{
		for(int i=0,j=qu->front;i<qu->size;i++){
			new_data[i] = qu->data[j];
			j = (j+1)%qu->actual;
		}//for
		free(qu->data);
		qu->data = new_data;
		qu->front = 0;
		qu->rear = qu->size;
		qu->actual = comp;
		return SUCCESS;
	}//if else
}//queue compact

int queue_free(Queue *qu){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}else{
		free(qu->data);
		free(qu);
		return SUCCESS;
	}//if else
}//queue free

int queue_size(Queue *qu){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return qu->size;
}//queue size

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