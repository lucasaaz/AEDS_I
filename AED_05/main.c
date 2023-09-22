/*
 Exercicio_A01 - v0.0. - __ / __ / _____
 Matricula: ____ Author: _______________
*/
// dependencias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"


void questao01 ( void ){
	int n = 0, x = 0;
	n = IO_readint("\nInforme quantos numeros: ");
	do{
		x = IO_readint("\nInforme o numero: ");
		if(x % 2 == 0){
			if(x > 0){
				IO_printf("\nNumero par e positivo!");
			}else if(x < 0){
				IO_printf("\nNumero par e negativo!");
			}else{
				IO_printf("\nNumero igual a zero");
			}
		}else{
			if(x > 0){
				IO_printf("\nNumero impar e positivo!");
			}else if(x < 0){
				IO_printf("\nNumero impar e negativo!");
			}else{
				IO_printf("\nNumero igual a zero");
			}
		}
		n = n - 1;
	}while(n > 0);
}


void questao02 ( void ){
	int n = 0, x = 0, maior = 0, verifica = 0;
	n = IO_readint("\nInforme quantos numeros: ");
	do{
		x = IO_readint("\nInforme o numero: ");
		if(verifica == 0){
			maior = x;
		}
		if(maior < x){
			maior = x;
		}
		if(x % 2 == 0){
			if(x > 0){
				IO_printf("\nNumero par e positivo!");
			}else if(x < 0){
				IO_printf("\nNumero par e negativo!");
			}else{
				IO_printf("\nNumero igual a zero!");
			}
		}else{
			if(x > 0){
				IO_printf("\nNumero impar e positivo!");
			}else if(x < 0){
				IO_printf("\nNumero impar e negativo!");
			}else{
				IO_printf("\nNumero igual a zero!");
			}
		}
		n = n - 1;
		verifica ++;
	}while(n > 0);
	IO_printf("\nO maior numero foi: %d", maior);
}

void questao03 ( void ){
	chars palavra = IO_new_chars ( STR_SIZE );
	int tamanho = 0, posicao = 0;
	char simbolo = '_';
	palavra = IO_readstring ( "\nEntre com uma palavra: " );
	tamanho = strlen ( palavra );
	for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ){
		simbolo = palavra [ posicao ];
		if(simbolo == '&' || simbolo == '|' || simbolo == '!'){
			IO_printf("\n%c eh um operador logico", simbolo);
		}
		if(simbolo == '+' || simbolo == '-' || simbolo == '*' || simbolo == '/' ||
		simbolo == '%'){
			IO_printf("\n%c eh um operador aritmetico", simbolo);
		}
		if(simbolo == '>' || simbolo == '<' || simbolo == '='){
			IO_printf("\n%c eh um operador relacional", simbolo);
		}
		if(simbolo == ' ' || simbolo == '.' || simbolo == ',' || simbolo == ';' || simbolo == ':'|| simbolo == '_'){
			IO_printf("\n%c eh um operador separadores", simbolo);
		}		
	}
}


void questao04 ( void ){
	chars palavra = IO_new_chars ( STR_SIZE );
	int tamanho = 0, posicao = 0, contadorM = 0, contadorm = 0, contadorD = 0, contadorO = 0, contadorS = 0; ;
	char simbolo = '_';
	palavra = IO_readstring ( "\nEntre com uma palavra: " );
	tamanho = strlen ( palavra );
	for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ){
		simbolo = palavra [ posicao ];
		if(simbolo == '&' || simbolo == '|' || simbolo == '!'){
			contadorO ++;
		}
		if(simbolo == '+' || simbolo == '-' || simbolo == '*' || simbolo == '/' ||
		simbolo == '%'){
			contadorO ++;
		}
		if(simbolo == '>' || simbolo == '<' || simbolo == '='){
			contadorO ++;
		}
		if(simbolo == '\0' || simbolo == '.' || simbolo == ',' || simbolo == ';' || simbolo == ':'|| simbolo == '_'){
			contadorS ++;
		}
		if(simbolo >= 'A' && simbolo <= 'Z'){
			contadorM ++;
		}
		if(simbolo >= 'a' && simbolo <= 'z'){
			contadorm ++;
		}	
		if(simbolo >= '0' && simbolo <= '9'){
			contadorD ++;
		}	
	}
	IO_printf("Operadores: %d \nSeparadores: %d \nMaiusculas: %d \nMinusculas: %d \nDigitos: %d", contadorO, contadorS, contadorM, contadorm, contadorD);
	
}

void questao05 ( void ){
	int n = 0, contadorMenor = 0, contador = 0, contadorMaior = 0;
	double x = 0.0, calculoMenor = 0.0, mediaMenor = 0.0, calculo = 0.0, media = 0.0, calculoMaior = 0.0, mediaMaior = 0.0;
	n = IO_readint("\nInforme quantos numeros: ");
	do{
		x = IO_readdouble("\nInforme um valor real: ");
		if(x < -33.25){
			calculoMenor = calculoMenor + x;
			contadorMenor++;
		}	
		if(-33.25 <= x && x <= 65.75 ){
			calculo = calculo + x;
			contador++;
		}
		if(65.75 < x){
			calculoMaior = calculoMaior + x;
			contadorMaior++;
		}
		n--;
	}while(n > 0);
	mediaMenor = calculoMenor / contadorMenor;
	media = calculo / contador;
	mediaMaior = calculoMaior / contadorMaior;
	if(mediaMenor < media && mediaMenor < mediaMaior){
		IO_printf("Menor media: %.2f", mediaMenor);
		IO_printf("Numeros menores que -33.25");
	}
	if(media < mediaMenor && media < mediaMaior){
		IO_printf("Menor media: %.2f", media);
		IO_printf("Numeros entre -33.25 e 65.75");
	}
	if(mediaMaior < mediaMenor && mediaMaior < media){
		IO_printf("Menor media: %.2f", mediaMaior);
		IO_printf("Numeros maiores que 65.75");
	}
}

void questao06 ( void ){
	
}


void questao07 ( void ){
	
}

void questao08 ( void ){
	
}

void questao09 ( void ){
	
}

void questao10 ( void ){
	
}

 /*
   Acao principal
 */
int main ( void ){
    int option = 0;
	printf ( "723900 - Yan Pablo Santos Rodrigues " );
	do{
		printf ( "\n\nOption?\n" );
		scanf  ( "%d", &option ); getchar( );
		printf ( "option = %d", option );
		switch ( option ){
			case 0: break;
			case 1: questao01 ( ); break;
			case 2: questao02 ( ); break;
			case 3: questao03 ( ); break;
			case 4: questao04 ( ); break;
			case 5: questao05 ( ); break;
			case 6: questao06 ( ); break;
			case 7: questao07 ( ); break;
			case 8: questao08 ( ); break;
			case 9: questao09 ( ); break;
			case 10: questao10 ( ); break;
		}
	}
	while ( option != 0 );
	return ( 0 );
}
 
