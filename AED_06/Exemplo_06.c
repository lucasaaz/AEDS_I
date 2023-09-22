/*
Exemplo04 - v0.0. - 12 / 05 / 2021
Author: Lucas Augusto
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void Parar( ){ }

/**
 Quantidade em valores pares em ordem crescente começando em 5.
*/

void parCrescente( int x )
{
    if ( x > 0 )
    {
        parCrescente ( x - 1 );
        IO_printf( "%s%d\n", " Valor = ", 6 + ( 2 * ( x - 1 ) ) );
    }
    else
    {
        IO_printf( "%s\n", " Pares partindo de 5" );
    }
}

void Metodo01( )
{
    IO_id( "Exercicio0611 - v0.0" );

    int valor = 0;
    
    valor = IO_readint("\n Quantidade em valores pares: ");
    
    parCrescente( valor );
    
    IO_pause( "Apertar ENTER para continuar" );
}





/**
 Quantidade em múltiplos de 5 em ordem decrescente encerrando em 5.
*/

void multDecrescente( int x )
{
    if ( x > 0 )
    {
        IO_printf( "%s%d\n", "Valor = ", 5 * ( x ) );
        multDecrescente ( x - 1 );
    }
    else
    {
        IO_printf( "%s\n", "Multiplos de 5 decrescendo ate 5" );
    }
}

void Metodo02( )
{

    IO_id( "Exercicio0612 - v0.0" );

    int valor = 0;
    
    valor = IO_readint("\n Quantidade de valores: ");
    
    multDecrescente( valor );
    
    IO_pause( "Apertar ENTER para continuar" );
}







/**
 Quantidade em múltiplos de 3 em ordem crescente.
*/

void multTres( int x )
{
    if ( x > 0 )
    {
        multTres ( x - 1 );
        IO_printf( "%s%d\n", "Valor = ", 3 * ( x ) );
    }
    else
    {
        IO_printf( "%s\n", "Multiplos de 3" );
    }
}

void Metodo03( )
{
    IO_id( "Exercicio0613 - v0.0" );
    
    int valor = 0;

    valor = IO_readint( "Entrar com uma quantidade inteira: " );
    
    multTres( valor );
    
    IO_pause( "Apertar ENTER para continuar" );
}









/**
 Quantidade em valores decrescentes da sequência: ... 1/125 1/25 1/5 1.
*/

void divCinco( int x )
{
    if ( x > 0 )
    {
        IO_printf( "%s%lf\n", "Valor = ", pow( 5, -( x - 1 ) ) );
        divCinco ( x - 1 );
    }
    else
    {
        IO_printf( "%s\n", "Denominador exponencial de base 5 decrescente" );
    }
}

void Metodo04( )
{
    IO_id( "Exercicio0614 - v0.0" );
    
    int valor = 0;

    valor = IO_readint( "Entrar com uma quantidade inteira: " );
    
    divCinco( valor );

    IO_pause( "Apertar ENTER para continuar" );
}






/**
 Mostrar cada símbolo separadamente, um por linha.
*/

void separarSimbolo( char *x, int tamanho )
{
    char letra = '\0';
    letra = x[tamanho];

    if( tamanho > 0 )
    {
        separarSimbolo( x, tamanho - 1 );
        IO_printf( " %c\n", letra );
    }
}

void Metodo05( )
{
    int  tamanho = 0;
    char palavras[STR_SIZE];

    IO_id( "Exercicio0615 - v0.0" );
    
    IO_printf(" Entrar com uma cadeia de caracteres: ");
    IO_scanf("%s", palavras);
    
    tamanho = strlen(palavras);
    
    IO_printf("%c \n", palavras[0]);
    
    separarSimbolo(palavras, tamanho);

    IO_pause( "Apertar ENTER para continuar" );
}






/**
  Calcular a soma dos primeiros valores ímpares positivos começando em 5.
*/

int somaMultImpar (int x)
{
    int soma = 0;
    if (x > 0)
    {
        soma = (x * 2 + 3) + somaMultImpar(x - 1);
    }
    return (soma);
}

void Metodo06( )
{
    IO_id( "Exercicio0616 - v0.0" );
    
    int valor = 0;

    valor = IO_readint( " Entrar com uma quantidade: " );    

    int soma = somaMultImpar( valor );
    
    IO_printf( "%s%d\n", " Soma dos primeiros impares apartir de 5 = ", soma );
    
    IO_pause( "Apertar ENTER para continuar" );
}






/*
 Calcular a soma dos inversos (1/x) dos primeiros valores ímpares positivos 
 começando em 5
*/

double somaInversos(int x)
{
    double soma = 0.0;
    if (x > 0)
    {
        soma = pow((x * 2 + 3), -1) + somaInversos(x - 1);
    }
    return (soma);
}

void Metodo07( )
{
    IO_id( "Exercicio0617 - v0.0" );
    
    int valor = 0;

    valor = IO_readint( " Entrar com uma quantidade: " );     

    double soma = somaInversos( valor );
    
    IO_printf( "%s%lf\n", " Soma dos inversos dos primeiros impares apartir de 5 = ", soma );
    
    IO_pause( "Apertar ENTER para continuar" );
}









/**
 Calcular certo termo par da série de Fibonacci começando em 1.
*/

int fibonacci(int n)
{
    int x = 0;
    if (n == 1 || n == 2)
    {
        x = 1;
    }
    else
    {
        if (n > 1)
        {
            x = fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    return (x);
}

void Metodo08 ( )
{

    IO_id( "Exercicio0618 - v0.0" );

    int valor = 0;
    int valor2 = 0;
    int termo = 0;

    valor = IO_readint(" Entrar com uma quantidade: ");

    valor2 = valor * 3;

    termo = fibonacci(valor2);
    IO_printf("\n %d.o termo par da serie de Fibonnaci = %d\n", valor, termo);
    
    IO_pause( "Apertar ENTER para continuar" );
}










/**
 Contar os dígitos com valores ímpares em uma cadeia de caracteres
*/

int  valoresImpares(chars string, int n)
{
    int count = 0;
    char character = '\0';
    int intChar = 0;

    if (0 <= n && n < strlen(string))
    {
        character = string[n];
        intChar = (int) character - 48;
        if (('0' <= character && character <= '9') && (intChar % 2 != 0))
        {
            count = 1;
        }
        count = count + valoresImpares(string, n + 1);
    }
    return (count);
}

void Metodo09( )
{
    IO_id( "Exercicio0619 - v0.0" );

    chars cadeia = IO_new_chars(STR_SIZE);
    int n = 0;
    int total = 0;

    cadeia = IO_readstring("\n Entrar com uma quantidade:  ");

    total = valoresImpares(cadeia, n);
    IO_printf("\n Total de digitos impares = %d\n", total);

    IO_pause( "Apertar ENTER para continuar" );
}







int quantMaiusc(char palavra2 [STR_SIZE])
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   int tamanho = 0;
   
// repetir para cada letra
   tamanho = strlen ( palavra2 );

// inicio teste de repetição
   for ( y = 0; y < tamanho; y = y + 1 )
   {  
      // se maiuscula
      if ( isupper(palavra2 [y]) )
      {
         // mostrar letra atual
         contar = contar + 1;
      }
   } // fim repetir
   
// resultado
   contar = contar - 1;
   return(contar);
} 

/**
 Calcular a quantidade de maiúsculas em uma cadeia de caracteres.
*/

void Metodo10 ( )
{
// definir dado
   char palavra [STR_SIZE];
   int resultado;
   
// identificar
   IO_id( "Exercicio0620 - v0.0" );
   
// ler do teclado
   IO_printf (" Entrar com uma palavra: " );
   scanf ( "%s", palavra );

//chama a função e recebe o retorno
  resultado = quantMaiusc(palavra);
  
//resultado
   printf(" \n Apenas %d letras maiusculas \n", resultado);
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method20 ( )











int main ( )
{
    int x = 0;

    do
    {
      IO_id ( "EXEMPLO06 - Programa - v0.0" );
    
      IO_println ( "    Opcoes:" );
      IO_println ( " 0  - parar" );
      IO_println ( " 1  - Exemplo0411" );
      IO_println ( " 2  - Exemplo0412" );
      IO_println ( " 3  - Exemplo0413" );
      IO_println ( " 4  - Exemplo0414" );
      IO_println ( " 5  - Exemplo0415" );
      IO_println ( " 6  - Exemplo0416" );
      IO_println ( " 7  - Exemplo0417" );
      IO_println ( " 8  - Exemplo0418" );
      IO_println ( " 9  - Exemplo0419" );
      IO_println ( " 10 - Exemplo0420" );
      IO_println ( "" );
      x = IO_readint ( "Esolha uma opcao: " );

        switch ( x )
        {
            case 0:
            Parar ( );
            break;

            case 1:
            Metodo01 ( );
            break;

            case 2:
            Metodo02 ( );
            break;

            case 3:
            Metodo03 ( );
            break;

            case 4:
            Metodo04 ( );
            break;

            case 5:
            Metodo05 ( );
            break;

            case 6:
            Metodo06 ( );
            break;

            case 7:
            Metodo07 ( );
            break;

            case 8:
            Metodo08 ( );
            break;

            case 9:
            Metodo09 ( );
            break;

            case 10:
            Metodo10 ( );
            break;    

            default:
            break;
        }
    } while ( x != 0 );
    
    IO_pause ( "Apretar ENTER para continuar" );
    return( 0 );
}