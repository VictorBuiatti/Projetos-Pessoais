# informa o nome do compilador
CC := gcc

# opções de compilação
CFLAGS := -O0 -std=c11 -Wall -Wextra -pedantic -lm

# adicione os arquivos de cabeçalho aqui
HDRS := TStack.h 

# adicione os arquivos fonte aqui
SRCS := ListaSequencial.c TStack.c main.c 

# gera os nomes dos arquivos objeto
OBJS := $(SRCS:.c=.o)

# nome do executável
EXEC := trab.exe

# receita padrão
all: $(EXEC)

# receita para construir o executável final
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# receita para remover do diretório os arquivos gerados
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
