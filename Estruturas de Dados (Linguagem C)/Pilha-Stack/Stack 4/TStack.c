#include <stdlib.h>
#include "TStack.h"

struct TStack{
	char *data;
	int qtd;
	int max;
};

TStack *stack_create(int max){
	TStack *st;

	st = (TStack *) malloc(sizeof(TStack));
	if(st!=NULL){
		st->data = malloc(max*sizeof(char));
		if(st->data==NULL){
			free(st);
			st = NULL;
		}else{
			st->qtd = 0;
			st->max = max;
		}
	}//if st

	return st;
}//stack create 

int stack_push(TStack *st, char a){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}else if(st->qtd==st->max){
		return OUT_OF_RANGE; //Pilha cheia
	}//if else

	st->data[st->qtd] = a;
	st->qtd++;

	return SUCCESS;
}//stack push 

int stack_pop(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}else if(st->qtd==0){
		return OUT_OF_RANGE; //Pilha vazia
	}//if else

	st->qtd--;

	return SUCCESS;
}//stack pop

int stack_top(TStack *st, char *a){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}else if(st->qtd==0){
		return OUT_OF_RANGE; //Pilha vazia
	}//if else

	*a = st->data[st->qtd-1];

	return SUCCESS;
}//stack top

int stack_size(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return st->qtd;
}//stack size

int stack_empty(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(st->qtd==0){
		return 0;
	}else{
		return 1;
	}
}//stack empty 

int stack_free(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	free(st->data);
	free(st);

	return SUCCESS;
}//stack free