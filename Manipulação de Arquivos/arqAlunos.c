/** Instruções para compilação
 * > gcc -std=c11 -c arqAlunos.c
 * > gcc arqAlunos.o -o arqAlunos.exe -lm
 * > ./arqAlunos.exe
 */

/**
 * @file arqAlunos.c
 * @brief Usado para manipulação de um arquivo .txt.
 *
 * @author Victor Hugo Buiatti
 * @date 21/06/2019
 * @bugs Nenhum conhecido
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 //Numero máximo de aluno que o programa pode receber
#define FREQ_MAX 20 //Numero máximo de frequencia que um aluno pode ter no semestre

typedef struct aluno Aluno;

struct aluno{
    char disciplina[30];
	char matricula[30];
	char nome[50];
	char freq[FREQ_MAX]; //P para presente e F para falta 
	int cont_freq; //Conta quantas frequencias um aluno ja possui 
};

//Prototipação
void inserir_aluno(Aluno al[], int *size);
void incluir_freq(Aluno T[], int size);
void mostra(Aluno T[], int tam);
void mostra1(Aluno T[], int size);
void freq_semestre(Aluno T[], int size);
void excluir_aluno(Aluno T[], int *size);
void calcula_situ(Aluno T[], int size);
int calcula_situ_aux(Aluno al);
void situ_alunos(Aluno T[], int size);
void salvar_alunos(Aluno P[], int size);
void elimina_buffer(char string[]);
void escreveEstudante(char name[], Aluno e);
void adiciona_turma(char name[], Aluno turma[], int size);
char leitura_char();
void menu();

void inserir_aluno(Aluno al[], int *size){
	int aux = *size;
	int tam, baux = aux;

	printf("\nDigite quantos alunos você deseja cadastrar: ");
	scanf("%d", &tam);
	getchar();
	aux += tam;
	if(aux>=MAX){
		printf("\nNão é possível inserir mais alunos!\n");
		return;
	}//if

	*size = aux;
	
	for(int i=baux; i<aux; i++){
		printf("\nDigite o nome do aluno: ");
		fgets(al[i].nome,50,stdin);
		elimina_buffer(al[i].nome);
		printf("Digite a matricula do aluno: ");
		fgets(al[i].matricula,30,stdin);
		elimina_buffer(al[i].matricula);
		printf("Digite a disciplina que o aluno esta cursando: ");
		fgets(al[i].disciplina,30,stdin);
		elimina_buffer(al[i].disciplina);
		al[i].cont_freq = 0; //Aluno que ainda não obteve frequencias
	}//for

	return;
}//insere alunos

void incluir_freq(Aluno T[], int size){
	char mat[30], frequencia;
	printf("\nNúmero de matricula do aluno que você seja inserir nova frequencia: ");
	fgets(mat,30,stdin);
	elimina_buffer(mat);

	printf("Digite a frequencia com P(para presente) ou F(para falta): ");
	scanf(" %c", &frequencia);
	frequencia = toupper(frequencia); //Caso o usuário digite um caractere minusculo

	for(int i=0;i<size;i++){
		if(strcmp(mat, T[i].matricula)==0){
               if(T[i].cont_freq==FREQ_MAX){
               	printf("\nAluno já possui todas as frequencias!\n");
               }else{
               	T[i].freq[T[i].cont_freq] = frequencia;
               	T[i].cont_freq++;
               }//if else
               return;
		}//if
	}//for

	printf("\nMatricula não encontrada!\n");
	return;
}//incluir frequencia

void mostra(Aluno T[], int tam){
		for(int i=0; i<tam; i++){
			printf("\nAluno: %s\n", T[i].nome);
			printf("Matricula: %s",T[i].matricula);
			printf("\nDisciplina do Aluno: %s",T[i].disciplina);
			if(T[i].cont_freq==0){
				printf("\nAluno ainda não possui frequencia!\n");
			}else{
				printf("\n---Frequencias do aluno---\n");
				for(int j=0;j<T[i].cont_freq;j++){
					printf("%c ",T[i].freq[j]);
				}//for
				printf("- Total de frequencias: %d\n",T[i].cont_freq);
			}//if else
		}//for	
	return;
}//mostra todos os alunos

void mostra1(Aluno T[], int size){  //buscar por matricula
    char mat[30];

    printf("\nDigite um número de matrícula: ");
    fgets(mat,30,stdin);
    elimina_buffer(mat);

	for(int i=0;i<size;i++){
        if(strcmp(mat,T[i].matricula)==0){
            printf("\nNome do Aluno: %s", T[i].nome);
            printf("\nDisciplina do Aluno: %s", T[i].disciplina);
            if(T[i].cont_freq==0){
				printf("\nAluno ainda não possui frequencia!\n");
			}else{
				printf("\n---Frequencias do aluno---\n");
				for(int j=0;j<T[i].cont_freq;j++){
					printf("%c ",T[i].freq[j]);
				}//for
				printf("- Total de frequencias: %d\n",T[i].cont_freq);
			}//if else
            return;
        }//if
	}//for
	printf("\nMatricula não encontrada!\n");
	return;
}//mostra 1 aluno a partir do seu numero de matricula

void freq_semestre(Aluno T[], int size){
    char mat[30];
    int faltas, presencas, frequencia, freq_disponivel;
    printf("\nDigite um número de matrícula: ");
    fgets(mat,30,stdin);
    elimina_buffer(mat);

    for(int i=0;i<size;i++){
        if(strcmp(mat,T[i].matricula)==0){
           	printf("\nQuantas faltas: ");
           	scanf("%d",&faltas);
           	printf("Quantas presenças: ");
           	scanf("%d",&presencas);
           	frequencia = faltas + presencas;
           	freq_disponivel = FREQ_MAX - T[i].cont_freq;
           	if((frequencia>freq_disponivel)){
           		printf("\nNão é possível inserir esse numero de frequencias para esse aluno!\n");
           		return;
           	}else{
           		for(int j=T[i].cont_freq;j<=frequencia;j++){
           			if(faltas!=0){
           				T[i].freq[T[i].cont_freq] = 'F';
           				faltas--;
           				T[i].cont_freq++;
           			}else if(presencas!=0){
           				T[i].freq[T[i].cont_freq] = 'P';
           				presencas--;
           				T[i].cont_freq++;
           			}//if else
           		}//for
           	}//if else
           	return;
        }//if
	}//for

    printf("\nMatricula não encontrada!\n");
    return;
}//seta a frequencia do aluno no semestre

void excluir_aluno(Aluno T[], int *size){
	char mat[30];
	int aux = *size;
	int i, j;
	printf("\nNúmero de matricula do aluno que você deseja excluir: ");
	fgets(mat,30,stdin);
	elimina_buffer(mat);

	for(i=0;i<aux;i++){ //Desloca todo o vetor para a esquerda
		if(strcmp(mat, T[i].matricula)==0){
			for(j=i+1;j<aux;j++,i++){
				T[i] = T[j];
			}//for
			*size -= 1;
			return;
		}//if
	}//for

	printf("\nMatricula não encontrada!\n");	
	return;
}//exclui um aluno, dado um numero de matricula

/*Definimos que para um aluno ser considerado aprovado no curso, ele deve ter 
  pelo menos 60% de presença nas aulas, isso considerando que o usuario ja tenha digitado as 
  20 frequencias possiveis para o aluno, ou seja, a frequencia do aluno deve ser maior ou igual
  a 60% de 20, para o mesmo ser aprovado
*/
void calcula_situ(Aluno T[], int size){
//No caso é evidente que essa conta sera igual a 12, mas caso o usuario deseje aumentar o numero de frequencias possiveis o calculo sempre sera feito
 	float frequencia = FREQ_MAX * 0.6; //Poderia ser do tipo int, já que o resultado já é conhecido, mas optei pelo tipo float nessa variável
 	int situ;
 	char mat[30];
 	printf("\nDigite um numero de matricula: ");
 	fgets(mat,30,stdin);
 	elimina_buffer(mat);

 	for(int i=0;i<size;i++){
 		if(strcmp(mat, T[i].matricula)==0){
 			situ = calcula_situ_aux(T[i]);
 			if(situ>=frequencia){
 				printf("\nO Aluno %s obteve %d presenças e está aprovado(a)!\n",T[i].nome,situ);
 			}else{
 				printf("\nO Aluno %s obteve %d presenças e está reprovado(a)!\n",T[i].nome,situ);
 			}//if else
 			return;
 		}//if
 	}//for

 	printf("\nMatricula não encontrada!\n");
 	return;
 }//calcula a situação de um aluno

//Calcula a situação de um aluno e retorna a mesma
int calcula_situ_aux(Aluno al){
	int aux = 0;
	for(int i=0;i<al.cont_freq;i++){
		if(al.freq[i]=='P'){
			aux++;
		}//if
	}//for

	return aux;
 }//calcula situação de um aluno auxiliar

void situ_alunos(Aluno T[], int size){
	int situ;
	float frequencia = FREQ_MAX * 0.6;

	for(int i=0; i<size; i++){
			printf("\nAluno: %s\n", T[i].nome);
			printf("Matricula: %s",T[i].matricula);
			printf("\nDisciplina do Aluno: %s",T[i].disciplina);
			if(T[i].cont_freq==0){
				printf("\nAluno ainda não possui frequencia!\n");
			}else{
				printf("\n---Frequencias do aluno---\n");
				for(int j=0;j<T[i].cont_freq;j++){
					printf("%c ",T[i].freq[j]);
				}//for
				situ = calcula_situ_aux(T[i]);
				if(situ>=frequencia){
					printf("\nAluno Aprovado(a)!\n");
				}else{
					printf("\nAluno Reprovado(a)!\n");
				}//if else
			}//if else
		}//for		
	return;
}//situ alunos


void elimina_buffer(char string[]){ //Elimina o '\n' do final de uma string
	char aux = string[0];
	int i=0;
	while(aux!='\n'){
		i++;
		aux = string[i];
	}//while
	string[i] = '\0';

	return;
}//elimina

//Verifica se o caractere lido é válido
char leitura_char(){
  char op = '\0';
  scanf(" %c",&op);

  while(op != 's' && op != 'S' && op != 'n' && op != 'N'){
    printf("valor inválido! Digite novamente: ");
    scanf(" %c",&op);
  }//while

  return op;
}//leitura char

void escreveEstudante(char name[], Aluno e){
	int situ;
	char a[30] = "Frequencias:";
	char situacao[30];
	float aprov = FREQ_MAX * 0.6;
	situ = calcula_situ_aux(e);
	if(situ>=aprov){
		strcpy(situacao,"\nAluno(a) Aprovado(a)!");
	}else{
		strcpy(situacao,"\nAluno(a) Reprovado(a)!");
	}//if else


	FILE *fp = fopen(name, "a");
    if(fp == NULL){
        fprintf(stderr, "Erro ao acessar o arquivo %s!\n", name);
        menu();
    }

  fprintf(fp, "%s\n", e.nome);
  fprintf(fp, "%s\n", e.matricula);
  fprintf(fp, "%s\n", e.disciplina);
  fprintf(fp, "%s\n", a);
  for(int i=0;i<e.cont_freq;i++){
  	fprintf(fp, "%c ", e.freq[i]);
  }//for
  fprintf(fp, "%s\n", situacao);

  fclose(fp);

  return;
}//escreve estudante

void adiciona_turma(char name[], Aluno turma[], int size){
  for(int i = 0; i < size; i++)
  {
    escreveEstudante(name, turma[i]);
  }//for
  return;
}//adiciona turma

void salvar_alunos(Aluno turma[], int size){
	char name[30];
	printf("\nDigite o nome do arquivo: ");
	fgets(name,30,stdin);
	elimina_buffer(name);

  FILE *fp = fopen(name, "r");
  char opt = '@';
  if(fp == NULL)
  {
    fprintf(stderr, "O arquivo %s não existe. Deseja criar um novo? (S/N) ", name);
    opt = leitura_char();
    switch(opt)
    {
      case 's':
      case 'S':
      {
         fp = fopen(name, "w");
         if(fp == NULL)
         {
           fprintf(stderr, "Erro ao criar o arquivo %s!\n",name);
           return;
         } else {
           adiciona_turma(name, turma, size);
           return;
         }
      }
    }

  } else {
    fprintf(stderr, "O arquivo %s já existe. Deseja sobrescreve-lo? (S/N) ", name);
    opt = leitura_char();
    switch(opt)
    {
      case 's':
      case 'S':
      {
         fp = fopen(name, "w");
         if(fp == NULL)
         {
           fprintf(stderr, "Erro ao criar o arquivo %s!\n",name);
           return;
         } else {
           adiciona_turma(name, turma, size);
           return;
         }
      }
    }//switch
  }

  return;
} //salvarESair

void menu(){
	int opcao;
	Aluno P[MAX];
	int tam = 0; //Guarda o número de alunos registrados

	while(1){
		printf("\nBem vindo ao Sistema de controle de presenca de alunos nas disciplinas da UFU");
		printf("\n1- Inserir um ou mais alunos"); 
		printf("\n2- Excluir um aluno");
		printf("\n3- Registrar presença do aluno na aula"); 
		printf("\n4- Registrar presenca do aluno no semestre");
		printf("\n5- Mostrar presença de um aluno"); 
		printf("\n6- Mostrar presença de todos os alunos"); 
		printf("\n7- Calcular situação de um aluno no semestre");
		printf("\n8- Mostrar situação de todos os alunos");
		printf("\n9- Salvar"); //Salva os alunos em um aquivo.txt
		printf("\n10- Sair ");
		printf("\n11- Carregar um arquivo");

		printf("\nDigite opção: ");
		scanf("%d", &opcao);
		getchar(); //Pega o buffer do teclado '\n'

		if(opcao == 1) inserir_aluno(P, &tam); 
		if(opcao == 2) excluir_aluno(P, &tam);
		if(opcao == 3) incluir_freq(P, tam);
		if(opcao == 4) freq_semestre(P, tam);
		if(opcao == 5) mostra1(P, tam); 
		if(opcao == 6) mostra(P, tam); 
		if(opcao == 7) calcula_situ(P, tam);
		if(opcao == 8) situ_alunos(P, tam);
		if(opcao == 9) salvar_alunos(P, tam);
		if(opcao == 10){
		 printf("Obrigada por usar o programa!\n"); 
		 return;
		}
		if(op==11) carregar_arq(P,&tam);
	}//while
}//menu


int main(){
	menu();
}//main
