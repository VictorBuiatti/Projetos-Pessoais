#include "TLinkedList.h"
#include "TQueue.h"

struct tqueue{
	List *data;
};//struct fila

TQueue *queue_create(){
	TQueue *qu;

	qu = malloc(sizeof(TQueue));
	if(qu!=NULL){
		qu->data = list_create();
		if(qu->data==NULL){
			free(qu);
			qu = NULL;
		}//if
	}//if

	return qu;
}//queue create

int queue_push(TQueue *qu, Aluno al){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return list_push_back(qu->data, al);
}//queue push 

int queue_pop(TQueue *qu){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return list_pop_front(qu->data);
}//queue

int queue_top(TQueue *qu, Aluno *al){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return list_front(qu->data,al);
}//queue top

int queue_empty(TQueue *qu){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(list_size(qu->data)==0){
		return 1;
	}else{
		return 0;
	}//if else
}//queue empty 

int queue_size(TQueue *qu){

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return list_size(qu->data);
}//queue size

int queue_free(TQueue *qu){
	int var;

	if(qu==NULL){
		return INVALID_NULL_POINTER;
	}//if

	var = list_free(qu->data);
	if(var==INVALID_NULL_POINTER){
		return INVALID_NULL_POINTER;
	}//if
	free(qu);

	return SUCCESS;
}//queue free