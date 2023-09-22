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
   int x = 0; // definir variavel com valor inicial

// identificar
   IO_id ( "EXEMPLO0201 - Programa - v0.0" );

// ler do teclado
   x = IO_readint ( "Entrar com um valor inteiro: ");

// testar valor
   if ( x%2 == 0 )
   {
      IO_printf ("\n O valor (%d) e PAR\n", x );
   }
   else
   {
      IO_printf ("\n O valor (%d) e IMPAR\n", x );
   } // fim se
// encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )