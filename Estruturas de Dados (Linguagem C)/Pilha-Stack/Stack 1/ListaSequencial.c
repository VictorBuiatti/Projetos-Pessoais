#include "ListaSequencial.h"

struct Lista{
	int qtd;
	aluno data[MAX];
};

Lista *cria_lista(){
	Lista *li;

	li = (Lista *) malloc(sizeof(Lista));

	if(li==NULL){
		return NULL;
	}

	li->qtd = 0;
	
	return li;
}//cria a lista

void imprime_lista(Lista *li){

	for(int i=0; i<li->qtd; i++){
		printf("\nNúmero de matrícula: %d\n",li->data[i].matricula);
		printf("Nome: %s\n", li->data[i].nome);
		printf("Notas: %.2f %.2f %.2f\n", li->data[i].n1, li->data[i].n2, li->data[i].n3);
	}//for

	return;
}//imprime a lista toda

/*Considerei que o usuario não espera manter a ordem da lista, ou seja, para inserir algum elemento no inicio
* caso já exista algum elemento no inicio, o mesmo vai para o final, e o novo elemento que deseja ser inserido vai
* para o inicio */
int insere_lista_inicio(Lista *li, aluno al){

	if(li==NULL){
		return SUCCESS;
	}

	if(li->qtd == MAX){
		return OUT_OF_RANGE;
	}

	if(li->qtd == 0){
		li->data[0] = al;
		li->qtd++;
		return SUCCESS;
	}

	li->qtd++;
	li->data[li->qtd-1] =  li->data[0];
	li->data[0] = al;

	return SUCCESS;
}//insere inicio

int insere_lista_final(Lista *li, aluno al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}

	if(li->qtd == MAX){
		return OUT_OF_RANGE;
	}

	li->data[li->qtd] = al;
	li->qtd++;

	return SUCCESS;
}//insere final 

int insere_lista_ordenada(Lista *li, aluno al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}

	if(li->qtd==MAX){
		return OUT_OF_RANGE;
	}

	int i=0;
	while(i<li->qtd){
		if(al.matricula>=li->data[i].matricula && al.matricula<=li->data[i+1].matricula){
			li->qtd++;
			for(int j=li->qtd-1;j!=i+1;j--){
				li->data[j] = li->data[j-1];
			}//for
			li->data[i+1] = al;
			return SUCCESS;
		}//if
		i++;
	}//while

	if(i==li->qtd){
		return ELEM_NOT_FOUND;
	}
	return SUCCESS;
}//insere ordenada

int consulta_lista_pos(Lista *li, int pos, aluno *al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(pos>li->qtd || pos<=0){
		return OUT_OF_RANGE;
	}

	*al = li->data[pos-1];

	return SUCCESS;
}//consulta posição

int consulta_lista_mat(Lista *li, int mat, aluno *al){
	if(li==NULL){
		return INVALID_NULL_POINTER;
	}

	int i=0;
	while(i<li->qtd){
		if(li->data[i].matricula==mat){
			*al = li->data[i];
			return SUCCESS;
		}
		i++;
	}//while

	return ELEM_NOT_FOUND; //O número de matricula digitado não foi encontrado na lista
}// consulta pelo número de matrícula 

int remove_lista(Lista *li, int mat){
	int pos = -1;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}

	int i=0;
	while(i<li->qtd){
		if(li->data[i].matricula==mat){
			pos = i;
		}
		i++;
	}

	if(pos<0){
		return ELEM_NOT_FOUND; //O número de matricula digitado não foi encontrado na lista
	}

	li->qtd--;
	for(int j=pos+1;j<=li->qtd;j++){
		li->data[j-1] = li->data[j];
	}//for

	return SUCCESS;
}//remove lista não otimizado, respeitando a ordem da lista

int remove_lista_otimizado(Lista *li, int mat){
	int pos = -1;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}

	int i=0;
	while(i<li->qtd){
		if(li->data[i].matricula==mat){
			pos = i;
		}
		i++;
	}

	if(pos<0){
		return ELEM_NOT_FOUND; //O número de matricula digitado não foi encontrado na lista
	}

	li->qtd--;
	li->data[pos] = li->data[li->qtd];

	return SUCCESS;
}//remove lista otimizado, não respeitando a ordem original da lista

int remove_lista_inicio(Lista *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}

	if(li->qtd==0){
		return OUT_OF_RANGE; //Lista vazia
	}

	li->qtd--;
	li->data[0] = li->data[li->qtd];

	return SUCCESS;
}//remove o elemento no inicio da lista e o substitui pelo ultimo elemento, decrementando o tamanho da lista

int remove_lista_final(Lista *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}

	if(li->qtd==0){
		return OUT_OF_RANGE; //Lista vazia
	}

	li->qtd--;

	return SUCCESS;
}//remove o último elemento da lista

int tamanho_lista(Lista *li){
	int tam;

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}

	tam = li->qtd;

	return tam;
}//Retorna o tamanho da lista

int lista_cheia(Lista *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}

	if(li->qtd == MAX){
		return SUCCESS; //Lista esta cheia
	}

	return OUT_OF_RANGE; //A Lista não esta cheia
}//verifica se a lista esta cheia

int lista_vazia(Lista *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}

	if(li->qtd==0){
		return 0; //Lista esta vazia
	}else{
		return 1; //Lista não esta vazia
	}
}//verifica se a lista esta vazia

int libera_lista(Lista *li){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else{
		free(li);
		return SUCCESS;
	}

}//libera a lista

int consulta_lista_final(Lista *li, aluno *al){

	if(li==NULL){
		return INVALID_NULL_POINTER;
	}else if(li->qtd==0){
		return OUT_OF_RANGE;
	}//if else

	*al = li->data[li->qtd-1];

	return SUCCESS;
}//retorna o ultimo elemento da lista