/** Instruções para compilação
 * > gcc -std=c11 -c basesNumericas.c
 * > gcc basesNumericas.o -o basesNumericas.exe -lm
 * > ./basesNumericas.exe
 */

/**
 * @file basesNumericas.c
 * @brief Usado para conversão e operações de bases númericas.
 *
 * @author Victor Hugo Buiatti
 * @date 07/11/2019
 * @bugs na opção 9, de soma, se digitar um número, dar enter e digitar outro, não fica formatado corretamente. 
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 32

int dec_p_hexa(unsigned int num);
unsigned int bin_p_hexa(unsigned int num, int op);
int dec_p_bin(unsigned int num);
unsigned int bin_p_dec(unsigned int numb, int op);
unsigned int hexa_p_dec(void);
unsigned int hexa_p_bin(void);
double binfrac_p_dec(int op);
int decfrac_p_bin(int op, double soma);
double soma(int op);
unsigned int ler_op(void);
int converter_novo(int op);
int mostrar_result(int op, unsigned int *num);
int menu_sec(int op);
int menu(void);
int main(void);


int dec_p_hexa(unsigned int num){
	char hexa[MAX];  //recebe char pois hexadecimal possui caracteres
	int j = 0;
	int i = 0;
	unsigned int resto = 0;

	if (num==0){
		printf("0");
	}
	else {
		for (i=0; num>0; i++){
			resto = num%16; //pega o resto da divisão entre o num e 16

			if (resto<10){
				hexa[i] = resto+'0';}   //para que o número seja exibido como char
			else if (resto==10){
				hexa[i] = 'A';}
			else if (resto==11){
				hexa[i] = 'B';}
			else if (resto==12){
				hexa[i] = 'C';}
			else if (resto==13){
				hexa[i] = 'D';}
			else if (resto==14){
				hexa[i] = 'E';}
			else if (resto==15){
				hexa[i] = 'F';}

			num = num/16;  //atualiza o num para o quociente
		}
		printf(" ");
		for (j=i-1; j>=0; j--){   //inverte a ordem, para que seja mostrado o num realmente em hexadecimal
			printf("%c", hexa[j]);
		}
	}
	printf("_(16)");
	return 0;
}

unsigned int bin_p_hexa(unsigned int num, int op){
	unsigned int result;

	//o valor é passado para decimal e de decimal para hexadecimal, dessa forma aproveitando funções já existentes
	result = bin_p_dec(num, op);
	dec_p_hexa(result);

	return 0;
}

int dec_p_bin(unsigned int num){
	unsigned int bin[MAX];  //arranjo que armazena o resultado
	int j = 0;
	int i = 0;

	if (num==0){
		printf(" 0\n");  //caso o número seja 0, sua forma binária tb é 0
	}
	else {
		for (i=0; num>0; i++){
			bin[i]= num%2;  //armazena o resto da div por 2 no arranjo
			num = num/2;   //atualiza o num para que ele seja o quociente
		}
		for (j=i-1; j>=0; j--){  //mostra o arranjo ao contrário, para que seja realmente o número binário
			printf("%u", bin[j]);
		}
		printf("_(2)");
	}
	return 0;
}

unsigned int bin_p_dec(unsigned int numb, int op){
	int i = 0;
	unsigned int soma=0;
	unsigned int div;

	for (i=0; numb>0; i++){
		div = numb%10;	//pega o bit menos significativo
		numb /= 10;  //atualiza o número para o segundo bit menos significativo

			if (div==1){     //se o núm for zero, como no cálculo para binário será também igual a 0, será ignorado
				soma+= pow(2, i);   //efetua a soma, elevando 2 a posição do num
			}

			else if (div!=1 && div!=0){
				menu_sec(op);    //se o bit - significativo for diferente de 0 ou 1 ele volta a pedir um número binário
			}
	}

	return soma;
}

unsigned int hexa_p_dec(void){
	char numh[MAX];
	int i = 0;
	unsigned int result=0;
	unsigned int dig;
	int j=0;

	scanf("%s", numh);

	for(i=(strlen(numh)-1); i>=0; i--){

		switch(numh[i]){
			case 'a': case 'A':
				dig=10; break;

			case 'b': case 'B':
                dig=11; break;

            case 'c': case 'C':
                dig=12; break;

            case 'd': case 'D':
                dig=13; break;

            case 'e': case 'E':
                dig=14; break;

            case 'f': case 'F':
                dig=15; break;

            default:
            	dig = numh[i]-0x30; break;  //transforma o char em int
		}

		result += dig * pow(16, j);
		j++;
	}
	printf(" %s_(16) = ", numh);
	return result;
}

unsigned int hexa_p_bin(void){
	unsigned int dec;
	unsigned int result;

	dec = hexa_p_dec();  //já nessa função é mostrado o num em hexa
	dec_p_bin(dec); //o resultado já é impresso aquu
	return 0;
}

double binfrac_p_dec(int op){
	char binario[50];
	int somaDec=0; //Soma da parte decimal(Int)
	double somaFrac=0;
	int j=0; //Contator da parte fracionaria
	int k=0; //Contator da parte decimal
	int dec[32]; //armazena a parte inteira
	int frac[16]; //armazena a parte fracionária
	char p = 'a'; //condição para verificar se o número está antes da virgula
	double decimal; //resultado
	double cont=1.0;
	int exp;

	scanf("%s", binario);

	for(int i=0; i<strlen(binario); i++){
		if(binario[i]=='.'){  //quando chegar ao ponto, ele modifica a variável de forma que ela só faça a condição 'else'
			p='d';
		} else if(p=='a'){
			dec[i] = binario[i]-0x30;
			k++;
		} else {
			frac[j] = binario[i]-0x30;  //armazena a parte fracionária em um arranjo
			j++;
		}
	}


	exp = k-1;

	for(int y=0; y<k; y++){  //Convertendo a parte Int
		if(dec[y]==1){
			somaDec= somaDec + pow(2, exp);
		} 
		exp--;
	}

	for(int x=0; x<j; x++){  //Convertendo a parte fracionária
		if(frac[x]==1){
			somaFrac = somaFrac + 1/(pow(2, cont));
		} 
		cont++;
	}

	decimal = somaDec + somaFrac;

	if(op==7){   //essa condição é feita pois esta função também será utilizada para fazer a soma, e neste caso não pode imprimir nada
		printf(" %s_(2) = ",binario);
	}

	else if(op==9){
		printf("\t %s", binario);
	}

	return decimal;
}

int decfrac_p_bin(int op, double soma){
	char decimal[33];
	int p = 0;
	int pint[32];  //Parte inteira
	int mantissa[32];  //parte fracionária
	int count_pint = 0;   //Contador da parte inteira
	int count_mant = 0;  //Contador da parte fracionária
	float x = 0.0;  
	float aux=0.0;  //Variável auxiliar
	int y = 0; //Armazena a parte inteira
	int frac[16]; //Parte fracionaria de um binário (já na base 2)
	int bindec[32]; //Parte inteira do binário (já na base 2)
	int exp = 0;
	int resto = 0;
	int cont = 0; //Contador da conversão inteira

	if(op==9){  //na função soma o número dec está como double, aqui ele é passado para o arranjo decimal
		sprintf(decimal, "%f", soma);
	}

	else if (op==8){
		scanf("%s", decimal);
	}

	for(int i=0; i<strlen(decimal); i++){
		if(decimal[i] == '.')
			p = 1;
		else

		if(p==0) {
			pint[count_pint] = decimal[i]-0x30;
			count_pint++;
		} 
		else {
			mantissa[count_mant] = decimal[i]-0x30;
			count_mant++;
		}
	}

	//Convertendo a parte fracionária de arranjo para um número na variável X
	for(int i=0; i<count_mant; i++){
		exp = count_mant - i;
		x += mantissa[i] * pow(10, --exp);
	}//for

	x /= pow(10, count_mant); //Transformando o número para que ele seja menor que 1. EX: 0,X (onde X é o número)
	aux = x; //Copiando para a variável auxiliar

	for(int i=0; i<16; i++){  //Convertendo a parte fracionária. Sendo 16 o limite de digitos após a vírgula
		aux = aux * 2;
		if(aux < 1){
			frac[i] = 0;
		} else {
			frac[i] = 1;
			aux = aux - 1;
		}
	}//for

	//Transformando a parte inteira em um número (variável y)
	for(int i=0; i<count_pint; i++){
		exp = count_pint - i;
		y += pint[i] * pow(10, --exp);
	}//for

	//Converte a parte inteira da base 10 para a base 2 (binário) e armazena no arranjo (bindec[32])
	for(cont=0; y>0; cont++){
		resto = y%2;
		bindec[cont] = resto; //Imprimir arranjo ao contrário!
		y = y/2;
	}//for

/*essa função está sendo utlizada para duas opções, a de conversão 
e a de soma, por isso as formas de mostrar os results na tela são diferentes*/
	if (op==8){
		printf("%s_(10) = ", decimal);
	}

	else if (op==9){
		printf("\n----------------------\n\t"); 
	}

	for(int j=cont-1; j>=0; j--){
		printf("%d", bindec[j]);
	}//for

	printf(",");

	for(int i=0; i<16; i++){
		printf("%d", frac[i]);
	}//for

	printf("_(2)\n");

	return 0;
}

double soma(int op){
	double dec1=0;
	double dec2=0; 
	double soma=0;
	double result=0;

	dec1 = binfrac_p_dec(op); //primeiro num é convertido para dec
	printf("\n  +");
	dec2 = binfrac_p_dec(op); //segundo num é convertido para dec

	soma = dec1 + dec2; //é feito a soma em decimal

	decfrac_p_bin(op, soma); //o resultado em decimal é passsado para binário novamente
}

unsigned int ler_op(void){
	unsigned int op=0;
	printf("\n Digite uma opção: ");
	scanf("%u", &op);

	while(op<0 || op>9){
		printf("\n Opção inválida! Digite outra: ");
		scanf("%u", &op);
	}

	return op;
}

int converter_novo(int op){
	char op2;
	printf("\n\n");
	if (op==1 || op==5){ printf(" Deseja converter outro binário "); }
	else if (op==2 || op == 6){ printf(" Deseja converter outro hexadecimal "); }
	else if (op==3 || op==4){ printf(" Deseja converter outro natural "); }
	else if (op==7){ printf(" Deseja converter outro binário fracionário "); }
	else if (op==8){ printf(" Deseja converter outro real "); }
	else if (op==9){ printf(" Deseja somar outros binarios "); }

	printf("(s/n)? ");
	scanf(" %c", &op2);

		while (op2!= 's' && op2!= 'n'){
			printf(" Opção inválida! Digite 's' ou 'n': \n");
			scanf(" %c", &op2);
		}
		system("cls || clear");
		if(op2=='s'){
			menu_sec(op);  //se a pessoa quiser ler um novo número a função menu_sec irá ser chamada, para que ela armazene o novo núm
		}
		else if (op2=='n'){  //caso contrário, a main será chamada, que por sua vez mostrará o menu inicial
			main();
	}
return 0;
}

int mostrar_result(int op, unsigned int *num){
	unsigned int num2 = *num;  //passa uma cópia do num, pois nesses casos não se deseja trabalhar com o endereço e sim com uma cópia
	unsigned int result;  //armazena os resultados inteiros que não sejam arranjos
	double result_d;

	switch(op){
		case 1:
			result = bin_p_dec(num2, op);
			printf(" %u_(2) = %u_(10)", *num, result); break;
		case 2:
		    result = hexa_p_dec();
		    printf("%u_(10)", result);
            break;
		case 3:
			printf(" %u_(10) = ", *num); dec_p_bin(num2); break;  //result final foi mostrado na função dec_p_bin, pois é um arranjo
		case 4:
			printf(" %u_(10) = ", *num); dec_p_hexa(num2); break;
		case 5:
			printf(" %u_(2) = ", *num); bin_p_hexa(num2, op); break;
		case 6:
			hexa_p_bin(); //o resultado é mostrado na função chamada por essa
			break;
		case 7:
			result_d = binfrac_p_dec(op);
			printf("%lf_(10)", result_d); break;
		case 8:
			decfrac_p_bin(op, 0); break;
		case 9:
			soma(op);
			break;
		case 0:
			printf(" Obrigada por usar o programa! \n"); exit(0);
	}
		converter_novo(op);
		return 0;
}

int menu_sec(int op){ //armazena o núm que será convertido e chama a função que mostrará o resultado
	unsigned int num=0;   //para números inteiros
	//nos casos "2", "6", "7", "8" e "9" o números serão lidos nas suas respectivas funções pois são lidos em formas de arranjo
	printf(" \n");
	if (op==1 || op==5){ printf(" Digite um binário: "); scanf("%u", &num); }
	else if (op==2 || op == 6){ printf(" Digite um hexadecimal: "); } 
	else if (op==3 || op==4){ printf(" Digite um natural: "); scanf("%u", &num); }
	else if (op==7){ printf(" Digite um binário fracionário: "); }
	else if (op==8){ printf(" Digite um real: "); }
	else if (op==9){ printf(" Digite os números binários: "); }

	mostrar_result(op, &num);

	return 0;
}

int menu(void){

	printf(" ***************************************\n");
	printf(" *              Conversor              *\n");
	printf(" ***************************************\n");

	printf("\n Opções: \n");
	printf(" 1 - converter de binário para decimal \n");
	printf(" 2 - converter de hexadecimal para decimal \n");
	printf(" 3 - converter de decimal para binário \n");
	printf(" 4 - converter de decimal para hexadecimal \n");
	printf(" 5 - converter de binário para hexadecimal \n");
	printf(" 6 - converter de hexadecimal para binário \n");
	printf(" 7 - converter de fração binária para decimal \n");
	printf(" 8 - converter de fração decimal para binário \n");
	printf(" 9 - somar dois binários sem sinal \n");
	printf(" 0 - sair \n");

	return 0;
}

int main(void){
	unsigned int op;

	menu();
	op = ler_op();
	menu_sec(op);
	return 0;
}
