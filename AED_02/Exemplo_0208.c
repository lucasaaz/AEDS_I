/*
Exemplo0208 - v0.0. - 09 / 04 / 2021
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
   float x; // primeiro valor
   float y; // segundo  valor
   
// identificar
   IO_id ( "EXEMPLO0208 - Programa - v0.0" );


// ler do teclado
   x = IO_readint ( " Entrar com o primeiro valor real: " );
   y = IO_readint ( " Entrar com o segundo valor real: " );

// testar PRIMEIRO valor
   if ( x == y )
   {
      IO_printf ("\n Os valores (%f) e (%f) sao IGUAIS\n", x, y);
   }
   else
   { 
      if ( x < y )
      {
         IO_printf ("\n O valor (%f) e MENOR que (%f)\n", x, y);
      }
      else
      {
         IO_printf ("\n O valor (%f) e MAIOR que (%f)\n", x, y);
      } // fim se   
   } // fim se  
// encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )