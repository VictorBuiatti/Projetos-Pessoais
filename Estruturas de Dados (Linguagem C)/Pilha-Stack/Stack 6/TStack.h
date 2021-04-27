#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_RANGE -2

typedef struct TStack TStack;

TStack *stack_create(int max); //Cria a pilha
int stack_free(TStack *st); //Libera a pilha

int stack_push(TStack *st, char a); //Insere na pilha (por ser um vetor, insere na ultima posição)
int stack_pop(TStack *st); //Remove um elemento (por ser um vetor, remove na ultima posição)

int stack_top(TStack *st, char *a); //Retorna o elemento que esta no topo da pilha

int stack_size(TStack *st); //Tamanho da pilha
int stack_empty(TStack *st); //Retorna 0 se a pilha esta vazia e retorna 1 caso contrario 