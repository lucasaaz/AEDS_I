/*
Exemplo0202 - v0.0. - 09 / 04 / 2021
Author: Lucas Augusto
*/

// dependencias
#include "io.h" // para definicoes proprias

/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( )
{
// definir dado
   int x = 0; // definir variavel com valor inicial
   
// identificar
   IO_id ( "EXEMPLO0202 - Programa - v0.0" );
   
// ler do teclado
   x = IO_readint ( "Entrar com um valor inteiro: " );
   
// testar valor
   if ( (x%2 == 0) && ( x > -100 ) )
   {
      IO_printf ("\n O valor (%d) e par e maior que -100\n", x );
   }
   else 
   {
      if ( (x%2 != 0) && ( x < 100 ) )
      {
         IO_printf ("\n O valor (%d) e ímpar e menor que 100\n", x );
      }
      else 
      {
         IO_printf ("\n Nao se enquadra nas alternativas\n", x );
      } // fim se
   } // fim se
// encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )