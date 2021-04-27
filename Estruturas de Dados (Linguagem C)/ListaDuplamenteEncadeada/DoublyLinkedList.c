#include "DoublyLinkedList.h"

typedef struct Node Node;

struct TDList{
	Node *begin;
	Node *end;
	int size; //Tamanho da lista
};

struct Node{
	Aluno data;
	Node *next;
	Node *prev;
}; //node

TDList *list_create(){
	TDList *li;

	li = (TDList *) malloc(sizeof(TDList));

	if(li!=NULL){
		li->begin = NULL;
		li->end = NULL;
		li->size = 0;
	}//if

	return li;
}//create 

int list_push_front(TDList *li, Aluno al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *no = (Node *) malloc(sizeof(Node));
	if(no==NULL){
		return OUT_OF_MEMORY;
	}//if

	no->data = al;
	no->prev = NULL; 
	no->next = li->begin;

	if(li->size==0){ //Testa se a lista esta vazia ou não 
		li->begin = no;
		li->end = no;
	}else{
		li->begin->prev = no;
		li->begin = no;
	}//if else

	li->size++;

	return SUCCESS;
}//push front

int list_push_back(TDList *li, Aluno al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *no = (Node *) malloc(sizeof(Node));
	if(no==NULL){
		return OUT_OF_MEMORY;
	}//if

	no->data = al;
	no->next = NULL;

	if(li->size==0){ //Caso a lista esteja vazia
		li->begin = no;
		li->end = no;
		no->prev = NULL;
	}else{
		li->end->next = no;
		no->prev = li->end;
		li->end = no;
	}//if else

	li->size++;

	return SUCCESS;
}//push back

int list_insert(TDList *li, int pos, Aluno al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *no = (Node *) malloc(sizeof(Node));

	if(no==NULL){
		return OUT_OF_MEMORY;
	}else if(pos<=0 || pos>li->size+1){ //Posição inválida
		return OUT_OF_RANGE;
	}//if else 

	no->data = al;

	if(li->size==0){ //Inserindo caso a lista esteja vazia(somente é válido caso o usuario digitar a posição 1)
		no->prev = NULL;
		no->next = NULL;
		li->begin = no;
		li->end = no;
	}else if(pos==1){ //Inserindo no inicio 
		no->prev = NULL;
		no->next = li->begin;
		li->begin->prev = no;
		li->begin = no;
	}else if(pos==li->size+1){ //Inserindo no final 
		no->prev = li->end;
		li->end->next = no;
		no->next = NULL;
		li->end = no;
	}else{
		Node *aux = li->begin;
		for(int i=1;i<pos;i++){
			aux = aux->next;
		}//for
		aux->prev->next = no;
		no->prev = aux->prev;
		aux->prev = no;
		no->next = aux;
	}//else/Caso generico

	li->size++;

	return SUCCESS;
}//insert

int list_pop_back(TDList *li){

	if(li==NULL) {
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE;
	}

	Node *aux = li->end;

	if(li->size==1){
		li->begin =NULL;
		li->end = NULL;
	} else{
		li->end = aux->prev;
		aux->prev->next = NULL;
	} 

	free(aux);
	li->size--;

	return SUCCESS;
}//pop back

int list_pop_front(TDList *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->size==0){
		return OUT_OF_RANGE;
	}

	Node *aux = li->begin;

	if(li->size==1){
		li->begin = NULL;
		li->end = NULL;
	}else {
		li->begin = aux->next;
		aux->next->prev = NULL;
	}// if else

	free(aux);
	li->size--;

	return SUCCESS;
}//pop front

int list_print_forward(TDList *li){ //E caso a lista seja vazia? REVISAR DEPOIS

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *aux = li->begin;

	printf("\n");
	while(aux!=NULL){
		printf("Aluno(a): %s - Matricula: %d - Notas: %.2f %.2f %.2f\n",aux->data.nome,aux->data.matricula,aux->data.n1,aux->data.n2,aux->data.n3);
		aux = aux->next;
	}//while

	return SUCCESS;
}//print forward

int list_print_reverse(TDList *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *aux = li->end;

	while(aux!=NULL){
		printf("Aluno(a): %s - Matricula: %d - Notas: %.2f %.2f %.2f\n",aux->data.nome,aux->data.matricula,aux->data.n1,aux->data.n2,aux->data.n3);
		aux = aux->prev;
	}//while

	return SUCCESS;
}//print reverse

int list_find_pos(TDList *li, int pos, Aluno *al){
	int i=1;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(pos<=0 || pos>li->size){
		return OUT_OF_RANGE; //Posição invalida
	}//if else

	Node *aux = li->begin;

	while(aux!=NULL && i<pos){
		aux = aux->next;
		i++;
	}//while

	*al = aux->data;

	return SUCCESS;
}//find pos

int list_find_mat(TDList *li, int nmat, Aluno *al){
	int i=0;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *aux = li->begin;

	while(aux!=NULL && i==0){
		if(aux->data.matricula == nmat){
			i++;
		}else{
			aux = aux->next;
		}//if else
	}//while

	if(aux==NULL){
		return ELEM_NOT_FOUND; //Não existe aquele numero de matricula nessa lista
	}else{
		*al = aux->data;
		return SUCCESS;
	}//if else

}//find mat

int list_front(TDList *li, Aluno *al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->begin==NULL){
		return OUT_OF_RANGE;
	}//if else

	*al = li->begin->data;

	return SUCCESS;
}//list front

int list_back(TDList *li, Aluno *al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->end==NULL){
		return OUT_OF_RANGE;
	}//if else

	*al = li->end->data;

	return SUCCESS;
}//list back 

int list_size(TDList *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return li->size;
}//list size

