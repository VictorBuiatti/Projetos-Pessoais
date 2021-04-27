#include "TStack.h"
#include <stdio.h>
#include <string.h>

int bem_formada(char array[]);

int main(void){
	char array[50];
	int var;

	printf("\nDigite uma sequencia de parênteses e colchetes: ");
	fgets(array,50,stdin);

	var = bem_formada(array);
	if(var==0){
		printf("\nSequencia mal formada!\n");
	}else if(var==1){
		printf("\nSequencia bem formada!\n");
	}//if else


	return 0;
}//main

int bem_formada(char array[]){ //Retorna 0 se esta mal formada e 1 se esta bem formada
	TStack *st;
	int tam = strlen(array);
	char aux;

	st = stack_create(tam);
	if(st==NULL){
		return INVALID_NULL_POINTER;
	}//if

	for(int i=0;i<tam;i++){
		if(array[i]=='('){
			stack_push(st, array[i]);
		}else if(array[i]==')'){
			stack_top(st, &aux);
			if(aux!='(' || stack_empty(st)==0){
				return 0;
			}else{
				stack_pop(st);
			}//if else
		}else if(array[i]=='['){
			stack_push(st,array[i]);
		}else if(array[i]==']'){
			stack_top(st,&aux);
			if(aux!='[' || stack_empty(st)==0){
				return 0;
			}else{
				stack_pop(st);
			}
		}
	}//for

	tam = stack_empty(st);
	if(tam==0){
		return 1;
	}else{
		return 0;
	}
}//bem formada