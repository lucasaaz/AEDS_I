/*
Exemplo0205 - v0.0. - 09 / 04 / 2021
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
   int x; // definir variavel com valor inicial


// identificar
   IO_id ( "EXEMPLO0205 - Programa - v0.0" );


// ler do teclado
   x = IO_readint ( "Entrar com um valor inteiro: " );

// testar valor
   if ( (20 <= x && x <= 75) && ( 33 <= x && x <= 55 ) )
   {
      IO_printf ("\n O numero (%d) pertence aos intervalos fechados [20:75] e [33:55]\n", x );
   }
   else
   {
      if ( 20 <= x && x <= 75 )
      {
         IO_printf ("\n O numero (%d) pertence a apenas um deles [20:75]\n", x );
      }
      else
      {
         if ( 33 <= x && x <= 55 )
         {
            IO_printf ("\n O numero (%d) pertence a apenas um deles [33:55]\n", x );
         }
         else
         {
            IO_printf ("\n O numero (%d) pertence a nenhum deles\n", x );
         } // fim se
      } // fim se
   } // fim se
// encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )