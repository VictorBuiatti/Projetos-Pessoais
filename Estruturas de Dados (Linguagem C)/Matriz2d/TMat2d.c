#include"TMat2d.h"

struct TMat2d{
	int nlin;
	int ncol;
	double *data;
};

TMat2d *cria_mat_copia(TMat2d *mat){
	if(mat==NULL){
		return NULL;
	}

	TMat2d *mat2;
	mat2 = create(mat->nlin,mat->ncol);

	int tam = mat->nlin * mat->ncol;
	for(int i=0;i<tam;i++){
		mat2->data[i] = mat->data[i];
	}//for

	return mat2;
}

TMat2d *create(int linha, int coluna){

	if(linha<=0 || coluna<=0){
		return NULL;
	}

	TMat2d *mat;
	mat = (TMat2d *)malloc(sizeof(TMat2d));

	if(mat==NULL){
		return NULL;
	}

	mat->data = (double *) malloc(sizeof(double)*linha*coluna);

	if(mat->data==NULL){
		free(mat);
		return NULL;
	}

	mat->nlin = linha;
	mat->ncol = coluna;


	return mat;
}//create

int destroy(TMat2d *mat){

	free(mat->data);
	free(mat);

	return 0;

}//destroy

int set_value(int lin, int col, TMat2d *mat, double num){
	int pos;

	if(mat==NULL){
		return -1;
	}

	if(lin>mat->nlin || col>mat->ncol){
		return -1;
	}

	pos = mat->nlin*col + lin;

	mat->data[pos] = num;

	return 0;

}//set

int get_value(int lin, int col, double *num, TMat2d *mat){
	int pos;

	if(mat==NULL){
		return -1;
	}

	if(lin>mat->nlin || col>mat->ncol){
		return -1;
	}

	pos = mat->nlin*col + lin;

	*num = mat->data[pos];

	return 0;
}//get

int random(double min, double max, TMat2d *mat){
	int tam;

	if(min>max){
		return -1;
	}

	tam = mat->nlin*mat->ncol;
	srand(time(NULL));
	for(int i=0;i<tam;i++){
		mat->data[i] = min + (rand()/(RAND_MAX/(max-min)));
	}//for

	return 0;

}//random

int sum(TMat2d *mat, TMat2d *mat2, TMat2d *mat3){
	int tam;

	if(mat->nlin!=mat2->nlin || mat->ncol!=mat2->ncol){
		return -1;
	}

	tam = mat->nlin*mat->ncol;

	for(int i=0;i<tam;i++){
		mat3->data[i] = mat2->data[i] + mat->data[i];
	}//for

	return 0;

}//sum


int multiplies(TMat2d *mat, TMat2d *mat2, TMat2d *mat3){
	int linha, coluna, linha2;
	double soma=0.0;

	if(mat->ncol!=mat2->nlin){
		return -1;
	}	

	mat3->nlin = mat->nlin;
	mat3->ncol = mat2->ncol;

	linha2 = mat2->nlin;
	linha = mat3->nlin;
	coluna = mat3->ncol;

	for(int i=0;i<linha;i++){
		for(int j=0;j<coluna;j++){
			for(int x=0, y=0;y<linha2;x++,y++){
				soma = soma + (mat->data[(x*linha)+i] * mat2->data[(j*linha)+y]);
			}
			mat3->data[(j*linha)+i] = soma;
			soma = 0.0;
		}
	}

	return 0;

}//multiplies

int mult_escalar(TMat2d *mat, TMat2d *mat_result, double num){
	int linha = mat_result->nlin;

	for(int i=0;i<mat_result->nlin;i++){
		for(int j=0;j<mat_result->ncol;j++){
			mat_result->data[(j*linha)+i] = mat->data[(j*linha)+i] * num;
		}//for
	}//for

	return 0;

}//escalar 

int calculate_dash(TMat2d *mat, double *result){
	*result = 0.0;
	int linha = mat->nlin;

	if(mat->nlin!=mat->ncol){
		return -1;
	}

	for(int i=0, j=0; i<mat->nlin;i++,j++){
		*result += mat->data[(j*linha)+i];
	}

	return 0;
}//calculate

double *vector_sum_lines(TMat2d *mat){
	double *vet;
	int linha = mat->nlin;
	int coluna = mat->ncol;

	vet = (double *) calloc(linha,sizeof(double));

	for(int i=0;i<linha;i++){
		for(int j=0;j<coluna;j++){
			vet[i] += mat->data[(j*linha)+i];
		}
	}//for

	return vet;
}//vector

double *vector_sum_column(TMat2d *mat){
	double *vet;
	int linha = mat->nlin;
	int coluna = mat->ncol;

	vet = (double *) calloc(coluna,sizeof(double));

	for(int j=0;j<coluna;j++){
		for(int i=0;i<linha;i++){
			vet[j] += mat->data[(j*linha)+i];
		}
	}//for

	return vet;
}
