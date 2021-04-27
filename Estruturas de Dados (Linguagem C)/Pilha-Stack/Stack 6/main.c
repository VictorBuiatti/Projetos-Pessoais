#include "TStack.h"
#include "TStackInt.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *infix_to_postfix(char *infix);
int postfix_calculate(char *postfix, int *result);

int main(void){
	char *infix, *postfix;
	int tam, result, var;

	printf("\nQuantos caracteres/elementos serão lidos: (digite um tamanho maximo)");
	scanf("%d",&tam);
	getchar();
	infix = malloc(tam*sizeof(char));
	if(infix==NULL){
		return 0;
	}else{
		printf("\nDigite uma expressão infixa: ");
		fgets(infix,tam,stdin);
	}

	printf("\nExpressão posfixa:\n");
	postfix = infix_to_postfix(infix);
	if(postfix==NULL){
		printf("\nFunção não funcionou corretamente!\n");
	}else{
		for(int i=0;postfix[i]!='\0';i++){
			printf("%c ",postfix[i]);
		}//for
	}//if else

	var = postfix_calculate(postfix,&result);
	if(var==0){
		printf("\nSucesso!\n");
		printf("\nResultado da expressão posfixa: %d\n", result);
	}else{
		printf("\nA função não funcionou corretamente!\n");
	}
	
	
	return 0;
}//main

char *infix_to_postfix(char *infix){
	int tam = strlen(infix), j=0;
	TStack *st;
	char aux;

	if(infix==NULL){
		return NULL;
	}//if

	char *postfix = malloc((tam+1)*sizeof(char));
	st = stack_create(tam);
	if(st==NULL || postfix==NULL){
		return NULL;
	}//if

	stack_push(st,infix[0]);
	for(int i=1;i<tam;i++){
		if(infix[i]=='('){
			stack_push(st,infix[i]);
		}else if(infix[i]=='*' || infix[i]=='/'){
			stack_top(st,&aux);
			while(aux!='+' && aux!='-' && aux!='('){
				postfix[j++] = aux;
				stack_pop(st);
				stack_top(st,&aux);
			}//while
			stack_push(st,infix[i]);
		}else if(infix[i]=='+' || infix[i]=='-'){
			stack_top(st,&aux);
			while(aux!='('){
				postfix[j++] = aux;
				stack_pop(st);
				stack_top(st,&aux);
			}//while
			stack_push(st,infix[i]);
		}else if(infix[i]==')'){
			stack_top(st,&aux);
			while(aux!='('){
				postfix[j++] = aux;
				stack_pop(st);
				stack_top(st,&aux);
			}//while
			stack_pop(st);
		}else if(infix[i]!=' '){
			postfix[j++] = infix[i];
		}//if else
	}//for

	tam = strlen(postfix);
	postfix[tam+1] = '\0';

	stack_free(st);


	return postfix;
}//infix to postfix

int postfix_calculate(char *postfix, int *result){
	TStackInt *st; //criando uma pilha de inteiros
	int len, aux, baux;
	
	len = strlen(postfix);
	st = stack_createInt(len);
	if(st==NULL){
		return -1;
	}//if

	for(int i=0;i<len;i++){
		if(postfix[i]=='+'){
			stack_topInt(st,&aux);
			stack_popInt(st);
			stack_topInt(st,&baux);
			stack_popInt(st);
			aux = aux + baux;
			stack_pushInt(st,aux);
		}else if(postfix[i]=='-'){
			stack_topInt(st,&aux);
			stack_popInt(st);
			stack_topInt(st,&baux);
			stack_popInt(st);
			aux = baux-aux;
			stack_pushInt(st,aux);
		}else if(postfix[i]=='*'){
			stack_topInt(st,&aux);
			stack_popInt(st);
			stack_topInt(st,&baux);
			stack_popInt(st);
			aux = aux * baux;
			stack_pushInt(st,aux);
		}else if(postfix[i]=='/'){
			stack_topInt(st,&aux);
			stack_popInt(st);
			stack_topInt(st,&baux);
			stack_popInt(st);
			aux = baux/aux;
			stack_pushInt(st,aux);
		}else if(isdigit(postfix[i])){
			aux = postfix[i] - '0';
			stack_pushInt(st,aux);
		}
	}//for

	stack_topInt(st,&aux);
	stack_popInt(st);
	stack_freeInt(st);
	*result = aux;

	return 0;
}//calcula a função posfixa


