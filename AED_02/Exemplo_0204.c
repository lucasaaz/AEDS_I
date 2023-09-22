/*
Exemplo0204 - v0.0. - 09 / 04 / 2021
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
   IO_id ( "EXEMPLO0204 - Programa - v0.0" );
   
// ler do teclado
   x = IO_readint ( "Entrar com um valor inteiro: " );
   
// testar valor
   if ( 25 <= x && x <= 60 )
   {
      IO_printf ("\n O valor (%d) pertence ao intervalo aberto entre (25:60)\n", x );
   }
   else 
   {
      IO_printf ("\n O valor (%d) nao pertence ao intervalo aberto entre (25:60)\n", x );
   } // fim se
// encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )