/*
Exemplo0209 - v0.0. - 09 / 04 / 2021
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
   float z; // terceiro  valor
   
// identificar
   IO_id ( "EXEMPLO0209 - Programa - v0.0" );


// ler do teclado
   x = IO_readint ( " Entrar com o primeiro valor real: " );
   y = IO_readint ( " Entrar com o segundo valor real: " );
   z = IO_readint ( " Entrar com o terceiro valor real: " );

// testar PRIMEIRO valor   
   if ( y != z )
   {
      if ( (x > y && x < z) && (y != z) )
      {
         IO_printf ("\n O primeiro numero(%f) esta entre os numeros (%f),(%f)\n", x, y, z);
      }
      else
      { 
         if ( (x > z && x < y) && (y != z) )
         {
            IO_printf ("\n O primeiro numero(%f) esta entre os numeros (%f),(%f)\n", x, z, y);
         }
         else
         {
            IO_printf ("\n O primeiro numero(%f) nao esta entre os numeros (%f),(%f)\n", x, y, z);
         } // fim se   
      
      } // fim se    
   }
   else
   {
      IO_printf ("\n (%f) = (%f), porfavor troque esses valores \n", y, z);
   }
// encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )