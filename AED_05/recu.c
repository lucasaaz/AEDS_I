/*
 Exercicio_A01 - v0.0. - 13 / 05 / 2021
 Matricula: 712433 Author: lucas augusto azevedo
*/
// dependencias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"


void questao01 ( void ){
   int n = 0; 
   int x = 0;
   
   n = IO_readint("\nInforme quantos numeros: ");
   
   do{
      x = IO_readint("\n\nInforme o numero: ");
      if(x % 2 == 0){
         if(x > 0){
            IO_printf("Numero par e positivo!");
         }
         else if(x < 0){
            IO_printf("Numero par e negativo!");
         }
         else{
            IO_printf("Numero igual a zero");
         }
      }
      else{
         if(x > 0){
            IO_printf("Numero impar e positivo!");
         }
         else if(x < 0){
            IO_printf("Numero impar e negativo!");
         }
         else{
            IO_printf("Numero igual a zero");
         }
      }
      n = n - 1;
   }while(n > 0);
}


void questao02 ( void ){
   int        n = 0;
   int        x = 0;
   int    maior = 0;
   int verifica = 0;
   int      par = 0;
   int    impar = 0;
   int     posi = 0;
   int      neg = 0;
   int     zero = 0;
   
   n = IO_readint("\nInforme quantos numeros: ");
   
   do{
      x = IO_readint("\n\nInforme o numero: ");
      if(verifica == 0){
         maior = x;
      }
      if(maior < x){
         maior = x;
      }
      if(x % 2 == 0){
         if(x > 0){
            IO_printf("Numero par e positivo!");
            par = par + 1;
            posi = posi + 1;
         }
         else if(x < 0){
            IO_printf("Numero par e negativo!");
            par = par + 1;
            neg = neg + 1;
         }
         else{
            IO_printf("Numero igual a zero!");
            zero = zero + 1;
         }
      }
      else{
         if(x > 0){
            IO_printf("Numero impar e positivo!");
            impar = impar + 1;
            posi = posi + 1;
         }
         else if(x < 0){
            IO_printf("Numero impar e negativo!");
            impar = impar + 1;
            neg = neg + 1;
         }
      }
      n = n - 1;
      verifica ++;
   }while(n > 0);
   IO_printf("\n\n O maior numero foi: %d",maior);
   IO_printf("\n Numero(s) positivo(s): %d",posi);
   IO_printf("\n Numero(s) negativo(s): %d", neg);
   IO_printf("\n Numero(s) par: %d",         par);
   IO_printf("\n Numero(s) impar: %d",     impar);
   IO_printf("\n Numero(s) zero(s): %d",    zero);
}

void questao03 ( void ){
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   
   printf ( "\nEntre com uma palavra: " );
   fgets  ( palavra, STR_SIZE, stdin );  // ler uma linha
   palavra [ strlen (palavra)-1 ] = EOS; // reposicionar o fim de linha
   tamanho = strlen ( palavra );
   
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ){
      simbolo = palavra [ posicao ];
      if(simbolo == '&' || simbolo == '|' || simbolo == '!'){
         IO_printf("\n%c e' um operador logico", simbolo);
      }
      if(simbolo == '+' || simbolo == '-' || simbolo == '*' || simbolo == '/' ||
      simbolo == '%'){
         IO_printf("\n%c e' um operador aritmetico", simbolo);
      }
      if(simbolo == '>' || simbolo == '<' || simbolo == '='){
         IO_printf("\n%c e' um operador relacional", simbolo);
      }
      if(simbolo == ' ' || simbolo == '.' || simbolo == ',' || simbolo == ';' || simbolo == ':'|| simbolo == '_'){
         IO_printf("\n%c e' um operador separadores", simbolo);
      }		
   }
}


void questao04 ( void ){
   chars palavra = IO_new_chars ( STR_SIZE );
   int   tamanho = 0; 
   int   posicao = 0;
   int contadorM = 0;
   int contadorm = 0;
   int contadorD = 0;
   int contadorO = 0;
   int contadorS = 0;
   char simbolo = '_';
   
   printf ( "\nEntre com uma palavra: " );
   fgets  ( palavra, STR_SIZE, stdin );  // ler uma linha
   palavra [ strlen (palavra)-1 ] = EOS; // reposicionar o fim de linha   
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
   int             n = 0;
   int      controle = 0;
   int contadorMenor = 0;
   int      contador = 0;
   int contadorMaior = 0;
   double           x = 0.0;
   double calculoMenor = 0.0;
   double   mediaMenor = 0.0;
   double      calculo = 0.0;
   double        media = 0.0;
   double calculoMaior = 0.0;
   double   Menortotal = 0.0;
   double   mediaMaior = 0.0;
   
   n = IO_readint("\nInforme quantos numeros: ");
   
   for (controle=0; controle<n; controle = controle + 1)
   {
      x = IO_readdouble("\nInforme um valor real: ");
      if(x < -33.25)
      {
         calculoMenor = calculoMenor + x;
         contadorMenor++;
      }	
      else{
         if(-33.25 <= x && x <= 65.75 )
         {
            calculo = calculo + x;
            contador++;
         }
         else{
            if(65.75 < x)
            {
               calculoMaior = calculoMaior + x;
               contadorMaior++;
            }     
         }
      } 
   } 

   mediaMenor = calculoMenor / contadorMenor;
   media = calculo / contador;
   mediaMaior = calculoMaior / contadorMaior;
   
   if ( mediaMenor < Menortotal )
   {
      Menortotal = mediaMenor;
   }
   else
   {
      if (media > -33.25 && media < 65.75)
      {  
         Menortotal = media;
      }
      else
      {
         Menortotal = mediaMaior;
      }
   }
   
   if(mediaMenor < -33.25 )
   {
      IO_printf("\n Media: %.2f", mediaMenor);
      IO_printf(" dos numeros menores que -33.25");
   }
   if(media > -33.25 && media < 65.75)
   {
      IO_printf("\n Media: %.2f", media);
      IO_printf(" dos numeros entre -33.25 e 65.75");
   }
   if(mediaMaior > 65.75)
   {
      IO_printf("\n Media: %.2f", mediaMaior);
      IO_printf(" dos numeros maiores que 65.75");
   }
   IO_printf("\n Menor mediade de todas: %.2f", Menortotal);
}    

void questao06 ( void ){
   int limitem     = 0;
   int limiteM     = 0;
   double potencia = 0.0;
   double verso    = 0.0;
   double valorf   = 0.0;
   double x        = 0.0;
   
   limitem = IO_readint("\n Infome um limite inferior: ");
   limiteM = IO_readint("\n Infome um limite superior:  ");
   
   do 
   {
      x = IO_readint("\n Infome valores inteiros: ");
            
      if ( limitem < x && x < limiteM )
      {
      
         potencia = pow (x, 3);
         verso    = potencia / 1000000;
         valorf   = verso + valorf;
         printf (" %lf = ", verso);
      
      }  
    
      printf ("\n\n Para sair digite (-1)"); 
   }while( x != -1  );
   
   printf ("\n Soma dos cubos dos inversos (1/x3) = %lf", valorf);
  
}


void questao07 ( void ){
   int limitem      = 0;
   int limiteM      = 0;
   double contarDentro = 0.0;
   double contarFora   = 0.0;
   double contarBaixo  = 0.0;
   double contarCima   = 0.0;
   double porcetagemB  = 0.0;
   double porcetagemC  = 0.0;
   double x            = 0.0;
   
   limitem = IO_readint("\n Infome um limite inferior: ");
   limiteM = IO_readint("\n Infome um limite superior:  ");
   
   do 
   {
      x = IO_readint("\n Infome valores inteiros: ");
            
      if ( limitem < x && x < limiteM )
      {
         contarDentro = contarDentro + 1;
      } 
   
      if ( (x < limitem OR x > limiteM) && (x != 0) )
      {
         contarFora = contarFora + 1;
      }   
   
   
      if ( x < limitem && x !=0 )
      {
         contarBaixo = contarBaixo + 1; 
      }
      else
      {
         if ( x > limiteM )
         {
            contarCima = contarCima + 1; 
         }
         else
         {
         
         }
      }   
    
      printf ("\n\n Para sair digite (0)"); 
   }while( x != 0  );

   porcetagemB = contarBaixo / contarFora ;
   porcetagemC = contarCima / contarFora  ;
   
   printf ("\n Valores que estao dentro = %.1lf", contarDentro);
   printf ("\n %.1lf estao fora e %.1lf acima, assim a porcentagem que estao acima e' %.2lf ", contarFora, contarCima, porcetagemC);
   printf ("\n %.1lf estao fora e %.1lf abaixo, assim a porcentagem que estao abaixo e' %.2lf ", contarFora, contarBaixo, porcetagemB);
}

void questao08 ( void ){
   int    x = 0;
   double a = 0;
   double b = 0;
   double c = 0;
   double maior = 0;
   double menor = 0;
   
   a = IO_readdouble("\n Infome um valor real: ");
   b = IO_readdouble("\n Infome um segundo valor real: ");
   c = IO_readdouble("\n Infome um terceiro valor real: ");
   
   if ( a < b && b < c )  
   {
      printf ("\n Esses valores estao em ordem crescente");
   }
   else
   {
      if ( a > b && b > c )  
      {
         printf ("\n Esses valores estao em ordem decrescente");
      }
      else
      {
         printf ("\n Esses valores estao em nenhuma ordem");
      }   
   }
   


   for ( x=0; x<1; x++ )
   {
      maior = a;
      if ( b > maior)
      {
         maior = b;   
      }
      if ( c > maior)
      {
         maior = c;
      }
   }


   
   for ( x=0; x<2; x++ )
   {
      menor = a;
      if ( b < menor)
      {
         menor = b;   
      }
      if ( c < menor)
      {
         menor = c;
      }
   }   
   
   printf ("\n Maior valor = %.2lf", maior);
   printf ("\n Menor valor = %.2lf", menor);
   
   // 2 4 6 - 2 6 4 - 4 2 6 - 4 6 2 - 6 2 4 - 6 4 2  
}

void questao09 ( void ){
   int        x = 0;
   int tamanhoa = 0; 
   int tamanhob = 0;
   int tamanhoc = 0; 
   int   maior2 = 0; 
   int   menor2 = 0; 
   chars a = IO_new_chars ( STR_SIZE );
   chars b = IO_new_chars ( STR_SIZE );
   chars c = IO_new_chars ( STR_SIZE );
   chars maior = IO_new_chars ( STR_SIZE );
   chars menor = IO_new_chars ( STR_SIZE );

   printf ( "\n Infome um caracter:  " );
   fgets  ( a, STR_SIZE, stdin );  
   a [ strlen (a)-1 ] = EOS;   
   printf ( "\n Infome um segundo caracter:  " );
   fgets  ( b, STR_SIZE, stdin );  
   b [ strlen (b)-1 ] = EOS;   
   printf ( "\n Infome um terceiro caracter:  " );
   fgets  ( c, STR_SIZE, stdin );  
   c [ strlen (c)-1 ] = EOS;    
   
   tamanhoa = strlen ( a );
   tamanhob = strlen ( b );
   tamanhoc = strlen ( c );
   
   if ( a < b && b < c )  
   {
      printf ("\n Esses caracteres estao em ordem crescente");
   }
   else
   {
      if ( a > b && b > c )  
      {
         printf ("\n Esses caracteres estao em ordem decrescente");
      }
      else
      {
         printf ("\n Esses caracteres estao em nenhuma ordem");
      }   
   }
   

   
   // a b c - a c b - b a c - b c a - c a b - c b a	
}

void questao10 ( void ){
	
}

 /*
   Acao principal
 */
int main ( void ){
   int option = 0;
   printf ( "712433 - Lucas Augusto Azevedo " );
   do{
      printf ( "\n\nOption?\n" );
      scanf  ( "%d", &option ); getchar( );
      printf ( "option = %d", option );
      switch ( option ){
         case 0: 
            break;
         case 1: questao01 ( ); 
            break;
         case 2: questao02 ( ); 
            break;
         case 3: questao03 ( ); 
            break;
         case 4: questao04 ( ); 
            break;
         case 5: questao05 ( ); 
            break;
         case 6: questao06 ( ); 
            break;
         case 7: questao07 ( ); 
            break;
         case 8: questao08 ( ); 
            break;
         case 9: questao09 ( ); 
            break;
         case 10: questao10 ( ); 
            break;
      }
   }
   while ( option != 0 );
   return ( 0 );
}
 
