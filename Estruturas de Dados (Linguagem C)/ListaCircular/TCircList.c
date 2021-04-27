#include "TCircList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;

struct list{
	Node *end;
	int size;
	int next_elem; //Usada para a função de percorrer o proximo elemento
};

struct node{
	Node *next;
	Aluno data;
};

List *list_create(){
	List *li;

	li = malloc(sizeof(List));
	if(li!=NULL){
		li->size = 0;
		li->next_elem = 1;
		li->end = NULL;
	}//if 

	return li;
}//list create

int list_free(List *li){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else{
		Node *aux = li->end->next;
		Node *baux = li->end;
		int i=1;
		while(i<li->size){
			baux = aux;
			aux = aux->next;
			free(baux);
			i++;
		}//while
		free(aux);
		free(li);
		return SUCCESS;
	}//if else
}//list free

int list_next_elem(List *li, Aluno *al){
	int i=1;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE;
	}else if(li->next_elem>li->size){
		li->next_elem = 1;
	}//if else

	Node *aux = li->end->next;
	while(i<li->next_elem){
		aux = aux->next;
		i++;
	}//while
	*al = aux->data;
	li->next_elem++;

	return SUCCESS;
}//list next elem

int list_push_front(List *li, Aluno al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *no = malloc(sizeof(Node));
	if(no==NULL){
		return OUT_OF_MEMORY;
	}else{
		no->data = al;
		if(li->size==0){ //Caso a lista esteja vazia
			li->end = no;
			no->next = li->end;
		}else{
			no->next = li->end->next;
			li->end->next = no;
		}//if else/inserindo o elemento
		li->size++;
		return SUCCESS;
	}//if else
}//list push front

int list_push_back(List *li, Aluno al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *no = malloc(sizeof(Node));
	if(no==NULL){
		return OUT_OF_MEMORY;
	}else{
		no->data = al;
		if(li->size==0){
			li->end = no;
			no->next = li->end;
		}else{
			no->next = li->end->next;
			li->end->next = no;
			li->end = no;
		}//if else/inserindo o elemento
		li->size++;
		return SUCCESS;
	}//if else
}//list push back

int list_front(List *li, Aluno *al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE; //Lista vazia
	}else{
		Node *aux = li->end->next;
		*al = aux->data;
		return SUCCESS;
	}//if else
}//list front

int list_back(List *li, Aluno *al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE; //Lista vazia
	}else{
		Node *aux = li->end;
		*al = aux->data;
		return SUCCESS;
	}//if else
}//list back

void list_print(List *li){
	if(li->size!=0){
		int pos=1;
		Node *aux = li->end->next;
		while(pos<=li->size){
			printf("\n%s - %d - %.2f %.2f %.2f", aux->data.nome,aux->data.matricula,aux->data.n1,aux->data.n2,aux->data.n3);
			aux = aux->next;
			pos++;
		}//while
	}//if
	return;
}//list print

int list_size(List *li){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return li->size;
}//list size

//Fazendo o cálculo do tamanho da lista sem utilizar a variável li->size, da estrutura da lista
int list_size_alternative(List *li){
	int tam=0;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->end==NULL){
		return tam;
	}else{
		Node *aux = li->end->next;
		Node *baux = aux->next;
		tam++;
		while(baux!=aux){
			baux = baux->next;
			tam++;
		}//while
		return tam;
	}//if else
}//list size alternative

int list_pop_front(List *li){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE;
	}//if else

	Node *aux = li->end->next;
	if(li->size==1){
		free(aux);
		li->end = NULL;
	}else{
		li->end->next = aux->next;
		free(aux);
	}//if else

	li->size--;
	return SUCCESS;
}//list pop front

int list_pop_back(List *li){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE;
	}//if else

	Node *aux = li->end;
	if(li->size==1){
		free(aux);
		li->end = NULL;
	}else{
		Node *baux = li->end->next;
		while(baux->next!=aux){
			baux = baux->next;
		}//while
		li->end = baux;
		li->end->next = aux->next;
		free(aux);
	}//if else
	li->size--;
	return SUCCESS;
}//list pop back

int list_insert(List *li, Aluno al, int pos){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if((li->size==0 && pos!=1) || pos<=0 || pos>li->size+1){ //A Lista esta vazia e o usuario
		return INVALID_POS;        //digitou uma posição que não é a primeira, posição invalida
	}//if else

	Node *no = malloc(sizeof(Node));
	if(no==NULL){
		return OUT_OF_MEMORY;
	}else{
		no->data = al;
		if(pos==li->size+1){
			return list_push_back(li, al);
		}else if(pos==1){
			return list_push_front(li, al);
		}else{
			int i=1;
			Node *aux = li->end->next;
			while(i<pos-1){
				aux = aux->next;
				i++;
			}//while
			no->next = aux->next;
			aux->next = no;
			li->size++;
			return SUCCESS;
		}//if else
	}//if else
}//list insert

int list_find_pos(List *li, int pos, Aluno *al){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){  //Lista vazia
		return OUT_OF_RANGE;
	}else if(pos<=0 || pos>li->size){
		return INVALID_POS; //Posição inválida
	}else if(pos==li->size){
		*al = li->end->data;
	}else{
		Node *aux = li->end->next;
		int i=1;
		while(i<pos){
			aux = aux->next;
			i++;
		}//while
		*al = aux->data;
	}//if else

	return SUCCESS;
}//list find pos

int list_find_mat(List *li, int nmat, Aluno *al){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE; //Lista vazia
	}else{
		Node *aux = li->end->next;
		if(aux->data.matricula==nmat){
			*al = aux->data;
		}else{
			aux = aux->next;
			while(aux->data.matricula!=nmat && aux!=li->end->next){
				aux = aux->next;
			}//while
			if(aux==li->end->next){
				return ELEM_NOT_FOUND;
			}else{
				*al = aux->data;
			}//if else
		}
	}

	return SUCCESS;
}//list find mat

int list_get_pos(List *li, int nmat, int *pos){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE;
	}else{
		Node *aux = li->end->next;
		int i=1;
		while(i<=li->size && aux->data.matricula!=nmat){
			aux = aux->next;
			i++;
		}//while
		if(i>li->size){
			return ELEM_NOT_FOUND;
		}else{
			*pos = i;
		}//if else
		return SUCCESS;
	}//if else
}//list get pos

int list_erase_pos(List *li, int pos){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE;
	}else if(pos<=0 || pos>li->size){
		return INVALID_POS;
	}//if else

	if(pos==li->size){
		return list_pop_back(li);
	}else if(pos==1){
		return list_pop_front(li);
	}else{
		Node *aux = li->end->next;
		Node *baux = li->end;
		int i=1;
		while(i<pos){
			aux = aux->next;
			baux = baux->next;
			i++;
		}//while
		baux->next = aux->next;
		free(aux);
		li->size--;
		return SUCCESS;
	}//if else
}//list erase pos

int list_erase_data(List *li, int nmat){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE;
	}//if else

	Node *aux = li->end->next;
	Node *baux = li->end;
	if(aux->data.matricula==nmat){
		return list_pop_front(li);
	}else if(baux->data.matricula==nmat){
		return list_pop_back(li);
	}else{
		aux = aux->next;
		baux = baux->next;
		while(aux->data.matricula!=nmat && aux!=li->end->next){
			aux = aux->next;
			baux = baux->next;
		}//while
		if(aux==li->end->next){
			return ELEM_NOT_FOUND;
		}else{
			baux->next = aux->next;
			free(aux);
			li->size--;
			return SUCCESS;
		}//if else
	}//if else
}//list erase data

int list_empty(List *li){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->end==NULL){  //Sem usar a li->size
		return 1;
	}else{
		return 0;
	}//if else
	/*Usando li->size:
	if(li->size==0){
		return 1;
	}else{
		return 0;
	} */
}//list empty 
