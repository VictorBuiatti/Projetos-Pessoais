#include "TLinkedList.h"

struct list{
	Node *head;
	int size; // quantidade de elementos na lista
};

struct node{
	Aluno data;
	Node *next;
};

List *list_create(){
	List *li;

	li = (List *) malloc(sizeof(List));

	if(li!=NULL){
		li->head = NULL;
		li->size = 0;
	}//if

	return li;
}//create

int list_push_front(List *li, Aluno al){
	Node *no;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	no = (Node *) malloc(sizeof(Node));

	if(no==NULL){
		return OUT_OF_MEMORY;
	}

	no->data = al;

	no->next = li->head;
	li->head = no;
	li->size++;

	return SUCCESS;
}//push front

int list_print(List *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(li->head==NULL){
		return OUT_OF_RANGE;
	}

	Node *aux = li->head;

	do{
		printf("\nAluno: %s - Matricula: %d - Notas: %.2f %.2f %.2f\n", aux->data.nome, aux->data.matricula, aux->data.n1, aux->data.n2, aux->data.n3);
		aux = aux->next;
	}while(aux!=NULL);

	return SUCCESS;
}//print 

int list_push_back(List *li, Aluno al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *no = (Node *) malloc(sizeof(Node));

	if(no==NULL){
		return OUT_OF_MEMORY;
	}

	no->data = al;
	no->next = NULL;

	if(li->head == NULL){
		li-> head = no;
		li->size++;
		return SUCCESS;
	}//if

	Node *aux = li->head;
	
	while(aux->next != NULL){
		aux = aux->next;
	}//while

	aux->next = no;
	li->size++;

	return SUCCESS;
}//push back

int list_pop_front(List *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(li->head==NULL){
		return OUT_OF_RANGE;
	} 

	Node *aux = li->head;
	li->head = aux->next;
	li->size--;

	free(aux); //Libera o primeiro elemento 

	return SUCCESS;
}//pop front

int list_pop_back(List *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(li->head==NULL){
		return OUT_OF_RANGE;
	}//if

	
	if(li->head==NULL){
		free(li->head);
		li->head = NULL;
		li->size--;
		return SUCCESS;
	}//Caso a lista tenha somente um elemento

	Node *aux = li->head;
	Node *aux22 = aux->next;

	while(aux22->next != NULL){
		aux22 = aux22->next;
		aux = aux->next;
	}//while

	li->size--;
	aux->next = NULL;
	free(aux22);

	return SUCCESS;
}//pop back

int list_free(List *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *aux = li->head;
	Node *baux = NULL;

	while(aux != NULL){
		baux = aux;
		aux = aux->next;
		free(baux);
	}//while

	free(li);

	return SUCCESS;
}//list free

int list_size(List *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	return li->size;
}//list size


int list_insert(List *li, int pos, Aluno al){
	int i = 1;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *no = (Node *) malloc(sizeof(Node));
	if(no==NULL){
		return OUT_OF_MEMORY;
	}//if

	no->data = al; 

	if(pos<=0 || pos>li->size+1){
		return OUT_OF_RANGE;
	}//posição é inválida

	Node *aux = li->head;
	Node *prev;

	if(pos==1 || li->head==NULL){ //Para inserção no inicio 
		li->head = no;
		no->next = aux;
	}else{
		while(i<pos){
			prev = aux;
			aux = aux->next;
			i++;
		}//while
		prev->next = no;
		no->next = aux;
	}//else

	li->size++;

	return SUCCESS;
}//insert pos

int list_get_pos(List *li, int nmat, int *pos){ //Dado um número de matrícula, retornar a posição na lista
	int j=1;
	int i = 0; //Pra sair do laço while, caso ja tenha encontrado o número de matricula

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(li->head==NULL){
		return OUT_OF_RANGE;
	}// Caso a lista esteja vazia

	Node *aux = li->head;

	while(aux!=NULL && i==0){
		if(aux->data.matricula == nmat){
			i++;
		}else{
			j++;
			aux = aux->next;
		}
	}//while

	*pos = j;

	if(aux==NULL){
		return ELEM_NOT_FOUND; //Não existe aquele número de matricula na lista
	}

	return SUCCESS;
}//get pos

int list_find_pos(List *li, int pos, Aluno *al){
	int j = 1;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(pos<=0 || pos>li->size){
		return OUT_OF_RANGE;
	}// Caso a posição digitada seja inválida

	Node *aux = li->head;

	while(j<pos){
		aux = aux->next;
		j++;
	}//while

	*al = aux->data;

	return SUCCESS;
}//find pos

int list_find_mat(List *li, int nmat, Aluno *al){
	int i=0;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	Node *aux = li->head; 

	while(aux!=NULL && i==0){
		if(aux->data.matricula == nmat){
			*al = aux->data;
			i++;
		}else{
			aux = aux->next;
		}//if else
	}//while

	if(aux==NULL){
		return ELEM_NOT_FOUND;
	}

	return SUCCESS;
}//find mat 

int list_front(List *li, Aluno *al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(li->head==NULL){
		return OUT_OF_RANGE;
	}//caso a lista esteja vazia

	Node *aux = li->head;
	*al = aux->data;

	return SUCCESS;
}//list front 

int list_back(List *li, Aluno *al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(li->head==NULL){
		return OUT_OF_RANGE;
	}//caso a lista esteja vazia

	Node *aux = li->head;

	while(aux->next != NULL){
		aux = aux->next;
	}//while

	*al = aux->data;

	return SUCCESS;
}//list back 

int list_erase_data(List *li, int mat){
	int i=0;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(li->head==NULL){
		return OUT_OF_RANGE;
	}//lista vazia

	Node *aux = li->head;

	if(aux->data.matricula == mat){
		li->head = aux->next;
		li->size--;
		free(aux);
		return SUCCESS;
	}//Caso o número de matricula seja o primeiro elemento da lista

	Node *prev;
	while(i==0 && aux!=NULL){
		if(aux->data.matricula == mat){
			prev->next = aux->next;
			free(aux);
			i++;
		}//if
		prev = aux;
		aux = aux->next;
	}//while

	if(i==0){
		return ELEM_NOT_FOUND;
	}//Caso não ache o aluno com o numero de matricula determinado 

	li->size--;

	return SUCCESS;
}//erase data

int list_erase_pos(List *li, int pos){
	int j=1;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}//if

	if(pos<=0 || pos>li->size){
		return OUT_OF_RANGE;
	}//Posição inválida

	if(li->head==NULL){
		return OUT_OF_RANGE;
	}//Lista vazia

	Node *aux = li->head;
	if(pos==1){
		li->head = aux->next;
		li->size--;
		free(aux);
		return SUCCESS;
	}//Tirando do inicio

	Node *prev;
	while(j<pos){
		prev = aux;
		aux = aux->next;
		j++;
	}//while

	li->size--;
	prev->next = aux->next;
	free(aux);

	return SUCCESS;
}//erase pos
