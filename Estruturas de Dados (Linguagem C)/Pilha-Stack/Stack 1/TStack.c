#include "TStack.h"
#include "ListaSequencial.h"

struct TStack{
	Lista *data;
};//struct

TStack *stack_create(){
	TStack *st;

	st = malloc(sizeof(TStack));
	if(st!=NULL){
		st->data = cria_lista();
		if(st->data == NULL){
			free(st);
			st = NULL;
		}//if
	}//if

	return st;
}//create

int stack_free(TStack *st){
	int var;

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	var = libera_lista(st->data);
	if(var==INVALID_NULL_POINTER){
		return INVALID_NULL_POINTER;
	}else{
		free(st);
	}
	
	return SUCCESS;
}//stack free

int stack_push(TStack *st, aluno al){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return insere_lista_final(st->data, al);
}//stack push 

int stack_pop(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return remove_lista_final(st->data);
}//stack pop

int stack_top(TStack *st, aluno *al){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return consulta_lista_final(st->data, al);
}//stack pop

int stack_empty(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return lista_vazia(st->data);
}//stack empty 

int stack_size(TStack *st){

	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return tamanho_lista(st->data);
}//stack size