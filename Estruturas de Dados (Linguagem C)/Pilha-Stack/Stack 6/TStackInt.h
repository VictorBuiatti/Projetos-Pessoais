#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_RANGE -2

typedef struct TStackInt TStackInt;

TStackInt *stack_createInt(int max); //Cria a pilha
int stack_freeInt(TStackInt *st); //Libera a pilha

int stack_pushInt(TStackInt *st, int a); //Insere na pilha (por ser um vetor, insere na ultima posição)
int stack_popInt(TStackInt *st); //Remove um elemento (por ser um vetor, remove na ultima posição)

int stack_topInt(TStackInt *st, int *a); //Retorna o elemento que esta no topo da pilha

int stack_sizeInt(TStackInt *st); //Tamanho da pilha
int stack_emptyInt(TStackInt *st); //Retorna 0 se a pilha esta vazia e retorna 1 caso contrario 

