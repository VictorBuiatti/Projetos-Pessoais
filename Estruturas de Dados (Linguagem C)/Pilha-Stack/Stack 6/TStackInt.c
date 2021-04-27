#include <stdlib.h>
#include "TStackInt.h"

struct TStackInt{
	int *data;
	int qtd;
	int max;
};

TStackInt *stack_createInt(int max){
	TStackInt *st;

	st = (TStackInt *) malloc(sizeof(TStackInt));
	if(st!=NULL){
		st->data = malloc(max*sizeof(int));
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

int stack_pushInt(TStackInt *st, int a){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}else if(st->qtd==st->max){
		return OUT_OF_RANGE; //Pilha cheia
	}//if else

	st->data[st->qtd] = a;
	st->qtd++;

	return SUCCESS;
}//stack push 

int stack_popInt(TStackInt *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}else if(st->qtd==0){
		return OUT_OF_RANGE; //Pilha vazia
	}//if else

	st->qtd--;

	return SUCCESS;
}//stack pop

int stack_topInt(TStackInt *st, int *a){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}else if(st->qtd==0){
		return OUT_OF_RANGE; //Pilha vazia
	}//if else

	*a = st->data[st->qtd-1];

	return SUCCESS;
}//stack top

int stack_sizeInt(TStackInt *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return st->qtd;
}//stack size

int stack_emptyInt(TStackInt *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(st->qtd==0){
		return 0;
	}else{
		return 1;
	}
}//stack empty 

int stack_freeInt(TStackInt *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	free(st->data);
	free(st);

	return SUCCESS;
}//stack free