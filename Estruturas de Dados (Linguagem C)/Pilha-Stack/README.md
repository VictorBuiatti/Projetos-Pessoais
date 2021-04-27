# Pilha-Stack
Implementação da estrutura de Pilha (Stack) na Linguagem C.
Existem diversas formas de se implementar uma Pilha em C, tentei explorar ao máximo isso e consequentemente cada pasta corresponde a uma forma de se implementar uma Pilha e casos práticos de resolução de problemas utilizando uma Pilha. Segue uma breve descrição sobre as particularidades de cada pasta:
Stack 1: Implementação da Pilha na forma de um wrapper para uma lista sequencial estática.
Stack 2: Implementação da Pilha na forma de um wrapper para uma lista encadeada dinâmica.
Stack 3: Implementação da Pilha utilizando alocação sequencial.
Stack 4: Utilizando uma Pilha para resolver o seguinte problema; "Considere o problema de decidir se uma dada sequência de parênteses e colchetes está bem-formada (ou seja, parênteses e colchetes são fechados na ordem inversa àquela em que foram abertos). Por exemplo, a sequência ( ( ) [ ( ) ] ) está bem-formada, enquanto ( [ ) ] está malformada. Suponha que a sequência de parênteses e colchetes está armazenada em uma string ASCII." Fonte: https://www.ime.usp.br/~pf/algoritmos/aulas/pilha.html
Stack 5: Utilizando uma Pilha para resolução do seguinte problema; "Implemente o algortimo que converte uma expressão matemática infix para postfix."
Stack 6: Utilização da Pilha para resolução do seguinte problema; "Implemente um algoritmo que, dada uma expressão matemática na forma postfix, informe o resultado da operação. Use o programa do exercício anterior para a conversão de Infix para postfix
Exemplo de saída:
 Digite a operação:
 5 * ( ( (9 + 8) * (4 * 6) ) + 7)
 Forma postfix: 5 9 8 + 4 6 * * 7 + *
 Resultado: 2075
