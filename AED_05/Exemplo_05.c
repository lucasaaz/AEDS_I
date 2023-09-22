/*
Exemplo05 - v0.0. - 01 / 05 / 2021
Author: Lucas Augusto
*/

// dependencias
#include "io.h" // para definicoes proprias
#include <math.h>

/**
Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )



/**
Funcao01 - Mostrar essa quantidade em valores múltiplos de 5 em ordem crescente.
*/
int funcao01( int quantidade)
{
// definir dado
   int controle   = 0;
   int contar     = 0;
   
// repetir para a quantidade de vezes informada
   controle = 1;
   while ( quantidade >= controle )
   {
      contar   = 5 * controle;
      controle = controle + 1;
      printf (" %d", contar);
   } // fim repetir
   
   return(contar);
} // fim Funcao01


/**
Method01 - Mostrar essa quantidade em valores múltiplos de 5 em ordem crescente.
*/
void method01 ( )
{
// definir dado
   int quantidade = 0;
   int resultado  = 0;
   
// identificar
   IO_id ( "EXEMPLO0501 - Method01 - v0.0" );
   
// ler do teclado
   printf(" Entrar com uma quantidade: " );
   scanf ("%d", &quantidade);
   printf ("\n");

// chama a função e recebe o retorno
   resultado = funcao01(quantidade);
     
// encerrar
   printf   ( "\n");
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )





/**
Funcao2 - Mostrar essa quantidade em valores pares múltiplos de 5 em ordem crescente.
*/
int funcao02( int quantidade)
{
// definir dado
   int controle   = 0;
   int contar     = 0;
   
// repetir para a quantidade de vezes informada
   controle = 1;
   while ( quantidade >= controle )
   {
      contar = 5 * controle;
      if ( contar %2 == 0)
      {
         printf (" %d",contar);
      }
      controle = controle + 1;
   } // fim repetir
   
   return(contar);
} // fim Funcao02


/**
Method02 - Mostrar essa quantidade em valores pares múltiplos de 5 em ordem crescente.
*/
void method02 ( )
{
// definir dado
   int quantidade = 0;
   int resultado  = 0;
   
// identificar
   IO_id ( "EXEMPLO0502 - Method02 - v0.0" );
   
// ler do teclado
   printf(" Entrar com uma quantidade: " );
   scanf ("%d", &quantidade);
   printf ("\n");

// chama a função e recebe o retorno
   resultado = funcao02(quantidade);   
   
// encerrar
   printf   ( "\n");
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )








/**
Funcao3 - Mostrar essa quantidade em valores ímpares múltiplos de 5 em ordem decrescente.
*/
int funcao03( int quantidade)
{
// definir dado
   int controle   = 0;
   int contar     = 0;
   
// repetir para a quantidade de vezes informada
   controle = 1;
   while ( quantidade >= controle )
   {
      contar = 5 * quantidade;
      if ( contar %2 != 0)
      {
         printf (" %d",contar);
      }
      quantidade = quantidade - 1;
   } // fim repetir
   
   return(contar);
} // fim Funcao03


/**
Method03 - Mostrar essa quantidade em valores ímpares múltiplos de 5 em ordem decrescente.
*/
void method03 ( )
{
// definir dado
   int quantidade = 0;
   int resultado  = 0;
   
// identificar
   IO_id ( "EXEMPLO0503 - Method03 - v0.0" );
   
// ler do teclado
   printf(" Entrar com uma quantidade: " );
   scanf ("%d", &quantidade);
   printf ("\n");

// chama a função e recebe o retorno
   resultado = funcao03(quantidade);   
   
// encerrar
   printf   ( "\n");
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )







/**
Funcao04 - Mostrar essa quantidade em valores crescentes nos denominadores.
*/
int funcao04( int quantidade)
{
// definir dado
   int controle   = 0;
   int contar     = 0;
   
// repetir para a quantidade de vezes informada
   controle = 1;
   while ( quantidade >= controle )
   {
      contar   = 5 * controle;
      controle = controle + 1;
      printf (" 1/%d", contar);
   } // fim repetir
   
   return(contar);
} // fim Funcao04


/**
Method04 - Mostrar essa quantidade em valores crescentes nos denominadores.
*/
void method04 ( )
{
// definir dado
   int quantidade = 0;
   int resultado  = 0;
   
// identificar
   IO_id ( "EXEMPLO0504 - Method04 - v0.0" );
   
// ler do teclado
   printf(" Entrar com uma quantidade: " );
   scanf ("%d", &quantidade);
   printf ("\n");

// chama a função e recebe o retorno
   resultado = funcao04(quantidade);
     
// encerrar
   printf   ( "\n");
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )









/**
Funcao05 - Mostrar essa quantidade em valores crescentes nos denominadores.
*/
int funcao05( int quantidade, float valor)
{
// definir dado
   int controle = 0;
   float contar = 0;
   
// repetir para a quantidade de vezes informada
   controle = 1;
   while ( quantidade >= controle )
   {
      contar   = pow ( valor, controle );
      controle = controle + 1;
      printf (" 1/%f", contar);
   } // fim repetir
   
   return(contar);
} // fim Funcao05


/**
Method05 - Mostrar essa quantidade em valores crescentes nos denominadores.
*/
void method05 ( )
{
// definir dado
   float  valor   = 0;
   int quantidade = 0;
   int resultado  = 0;
   
// identificar
   IO_id ( "EXEMPLO0505 - Method05 - v0.0" );
   
// ler do teclado
   printf(" Entrar com um valor: " );
   scanf ("%f", &valor);
   printf ("\n");

   printf(" Entrar com uma quantidade: " );
   scanf ("%d", &quantidade);
   printf ("\n");
   
// chama a função e recebe o retorno
   resultado = funcao05(quantidade,valor);
     
// encerrar
   printf   ( "\n");
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )











/**
Funcao06 - Calcular a soma dos primeiros valores ímpares positivos começando em 5
e não múltiplos de 3.
*/
int funcao06( int quantidade)
{
// definir dado
   int resultado = 0;
   int controle  = 0;
   int contar    = 0;
   int x         = 5;
   
// repetir para a quantidade de vezes informada
   while ( quantidade >= controle )
   {
      if ( (x %2 != 0) && (x %3 != 0) )
      {
         printf (" %d", x);
         resultado = resultado + x;
         x = x + 2;
      }
      else
      {
         x = x + 2;
      }
      controle = controle + 1;
   } // fim repetir
   
   return(resultado);
} // fim Funcao06


/**
Method06 - Calcular a soma dos primeiros valores ímpares positivos começando em 5
e não múltiplos de 3.
*/
void method06 ( )
{
// definir dado         
   int valor = 0;
   int resultado  = 0;
   
// identificar
   IO_id ( "EXEMPLO0506 - Method06 - v0.0" );
   
// ler do teclado
   printf(" Entrar com uma quantidade: " );
   scanf ("%d", &valor);
   printf ("\n");

// chama a função e recebe o retorno
   resultado = funcao06(valor);
   
// resultado final
   printf ("\n\n Soma dos primeiros numeros: %d", resultado);
     
// encerrar
   printf   ( "\n");
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )











/**
Funcao07 - Calcular a soma dos inversos (1/x) dos primeiros valores ímpares positivos.
*/
int funcao07( int quantidade)
{
// definir dado
   float resultado = 0.0;
   int controle    = 0;
   int contar      = 0;
   int x           = 5;
   float y         = 0.0;
   float z         = 0.0;
   
// repetir para a quantidade de vezes informada
   while ( quantidade >= controle )
   {
      if ( (x %2 != 0) && (x %3 != 0) )
      {
         y = x;
         z = y / (x*x);
         printf (" 1/%d", x);
         resultado = resultado + z;
         x = x + 2;
      }
      else
      {
         x = x + 2;
      }
      controle = controle + 1;
   } // fim repetir
  
   printf ("\n\n Soma dos inversos (1/x) dos primeiros numeros impares: %f", resultado);
   
   return(resultado);
} // fim Funcao06


/**
Method07 - Calcular a soma dos inversos (1/x) dos primeiros valores ímpares positivos.
*/
void method07 ( )
{
// definir dado         
   int valor = 0;
   float resultado  = 0.0;
   
// identificar
   IO_id ( "EXEMPLO507 - Method07 - v0.0" );
   
// ler do teclado
   printf(" Entrar com uma quantidade: " );
   scanf ("%d", &valor);
   printf ("\n");

// chama a função e recebe o retorno
   resultado = funcao07(valor);
     
// encerrar
   printf   ( "\n");
   IO_pause ( "Apertar ENTER para continuar" );
} // fim methodo07 ( )











/**
Funcao08 - Calcular a soma dos primeiros números naturais começando em 1.
*/
int funcao08( int quantidade)
{
// definir dado
   int resultado = 0.0;
   int controle    = 0;
   int contar      = 0;
   int x           = 1;
   
// repetir para a quantidade de vezes informada
   while ( quantidade >= x )
   {
      printf (" %d", x);
      resultado = resultado + x;
      x = x + 1;
   } // fim repetir
   
   return(resultado);
} // fim Funcao08


/**
Method08 - Calcular a soma dos primeiros números naturais começando em 1.
*/
void method08 ( )
{
// definir dado         
   int valor = 0;
   int resultado  = 0.0;
   
// identificar
   IO_id ( "EXEMPLO508 - Method08 - v0.0" );
   
// ler do teclado
   printf(" Entrar com uma quantidade: " );
   scanf ("%d", &valor);
   printf ("\n");

// chama a função e recebe o retorno
   resultado = funcao08(valor);
   
// resultado 
   printf ("\n\n Soma dos primeiros numeros naturais: %d", resultado);
     
// encerrar
   printf   ( "\n");
   IO_pause ( "Apertar ENTER para continuar" );
} // fim methodo08 ( )









/**
Funcao09 - Calcular a soma dos quadrados dos primeiros números naturais começando em 1.
*/
int funcao09( int quantidade)
{
// definir dado
   int resultado = 0;
   int controle  = 0;
   int contar    = 0;
   int x         = 1;
   int y         = 0;
   
// repetir para a quantidade de vezes informada
   while ( quantidade >= x )
   {
      printf (" %d", x);      
      y = pow ( x, 2);   
      resultado = resultado + y;     
      x = x + 1;
   } // fim repetir
   
   return(resultado);
} // fim Funcao09


/**
Method9 - Calcular a soma dos quadrados dos primeiros números naturais começando em 1.
*/
void method09 ( )
{
// definir dado         
   int valor = 0;
   int resultado  = 0.0;
   
// identificar
   IO_id ( "EXEMPLO509 - Method09 - v0.0" );
   
// ler do teclado
   printf(" Entrar com uma quantidade: " );
   scanf ("%d", &valor);
   printf ("\n");

// chama a função e recebe o retorno
   resultado = funcao09(valor);
   
// resultado 
   printf ("\n\n Soma dos quadrados dos primeiros numeros naturais: %d", resultado);
     
// encerrar
   printf   ( "\n");
   IO_pause ( "Apertar ENTER para continuar" );
} // fim methodo09 ( )








/**
Funcao10 - Calcular a soma dos inversos (1/x) dos primeiros números naturais começando em 1.
*/
int funcao10( int quantidade)
{
// definir dado
   float resultado = 0;
   int controle    = 0;
   int contar      = 0;
   int x           = 1;
   float y         = 0;
   float z         = 0;
   
// repetir para a quantidade de vezes informada
   while ( quantidade >= x )
   {
      y = x;
      z = y / (x*x);
      printf (" 1/%d", x);
      resultado = resultado + z;
      x = x + 1;
   } // fim repetir
   
// resultado 
   printf ("\n\n Soma dos primeiros numeros naturais: %f", resultado);
   
   return(resultado);
} // fim Funcao10


/**
Methodo10 - Calcular a soma dos inversos (1/x) dos primeiros números naturais começando em 1.
*/
void method10 ( )
{
// definir dado         
   int valor = 0;
   float resultado  = 0.0;
   
// identificar
   IO_id ( "EXEMPLO520 - Methodo10 - v0.0" );
   
// ler do teclado
   printf(" Entrar com uma quantidade: " );
   scanf ("%d", &valor);
   printf ("\n");

// chama a função e recebe o retorno
   resultado = funcao10(valor);
     
// encerrar
   printf   ( "\n");
   IO_pause ( "Apertar ENTER para continuar" );
} // fim methodo10 ( )









/*
Funcao principal.
*/
int main ( )
{
// definir dado
   int x = 0;
// repetir até desejar parar
   do
   {
   // identificar
      IO_id ( "EXEMPLO0501 - Programa - v0.0" );
   // ler do teclado
      IO_println ( "    Opcoes:" );
      IO_println ( " 0  - parar" );
      IO_println ( " 1  - Exemplo0511" );
      IO_println ( " 2  - Exemplo0512" );
      IO_println ( " 3  - Exemplo0513" );
      IO_println ( " 4  - Exemplo0514" );
      IO_println ( " 5  - Exemplo0515" );
      IO_println ( " 6  - Exemplo0516" );
      IO_println ( " 7  - Exemplo0517" );
      IO_println ( " 8  - Exemplo0518" );
      IO_println ( " 9  - Exemplo0519" );
      IO_println ( " 10 - Exemplo0520" );
      IO_println ( "" );
      x = IO_readint ( "Entrar com uma opcao: " );
   // testar valor
      switch ( x )
      {
         case 0:
            method00 ( );
            break;
         case 1:
            method01 ( );
            break;
         case 2:
            method02 ( );
            break;
         case 3:
            method03 ( );
            break;
         case 4:
            method04 ( );
            break;
         case 5:
            method05 ( );
            break;
         case 6:
            method06 ( );
            break; 
         case 7:
            method07 ( );
            break;
         case 8:
           method08 ( );
            break; 
         case 9:
           method09 ( );
            break;
         case 10:
           method10 ( );
            break;         
         default:
            IO_pause ( "ERRO: Valor invalido." );
      } // fim escolher
   }
   while ( x != 0 );// encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )
