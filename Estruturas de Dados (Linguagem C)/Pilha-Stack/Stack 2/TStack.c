#include "TStack.h"
#include "TLinkedList.h"

struct TStack{
	List *data;
};//struct pilha

TStack *stack_create(){
	TStack *st;

	st = malloc(sizeof(TStack));
	if(st!=NULL){
		st->data = list_create();
		if(st->data==NULL){
			free(st);
			st = NULL;
		}
	}

	return st;
}//stack create

int stack_push(TStack *st, Aluno al){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return list_push_front(st->data, al); 
}//stack push 

int stack_pop(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return list_pop_front(st->data);
}//stack pop

int stack_size(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return list_size(st->data);
}//stack size

int stack_top(TStack *st, Aluno *al){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return list_front(st->data, al); 
}//stack top

int stack_empty(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return list_empty(st->data);
}//stack empty

int stack_free(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	int var = list_free(st->data);
	if(var==INVALID_NULL_POINTER){
		return INVALID_NULL_POINTER;
	}else{
		free(st);
		return SUCCESS;
	}
}//stack free