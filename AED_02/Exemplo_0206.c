/*
Exemplo0206 - v0.0. - 09 / 04 / 2021
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
   int x; // primeiro valor
   int y; // segundo  valor


// identificar
   IO_id ( "EXEMPLO0206 - Programa - v0.0" );


// ler do teclado
   x = IO_readint ( "Entrar com o primeiro valor inteiro: " );
   y = IO_readint ( "Entrar com o segundo valor inteiro: " );

// testar PRIMEIRO valor
   if ( x%2 != 0 )
   {
      IO_printf ("\n O primeiro numero (%d) e IMPAR\n", x );
   }
   else
   {  
      IO_printf ("\n O primeiro numero (%d) nao e IMPAR\n", x );      
   } // fim se
   
// testar PRIMEIRO valor
   if ( y%2 == 0 )
   {
      IO_printf ("\n O segundo numero (%d) e PAR\n", y );
   }
   else
   {
      IO_printf ("\n O segundo numero (%d) nao e PAR\n", y );
   } // fim se
   
// encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )