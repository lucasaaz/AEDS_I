/*
Exemplo0117 - v0.0. - 03 / 04 / 2020
Author: Lucas Augusto
*/

// dependencias
#include <stdio.h>   // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h>  // para cadeias de caracteres
#include <math.h>    // para funcoes matemáticas: pow( ), sqrt( ), sin( ), cos( ) ...

/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dados 
   float lado   = 0.0;
   float volume = 0.0; 
   float volume2 = 0.0;
// identificar
   printf ( "%s\n", "EXEMPLO0117 - Programa - v0.0" );
   printf ( "%s\n", "Autor: Lucas Augusto" );
   printf ( "\n" ); // mudar de linha
// ler do teclado
   printf ( "\n Digite um valor para o lado do cubo: " );
   scanf ( "%f", &lado );
// operar valores
   volume  = pow(lado,3);
   volume2 = pow((lado*4),3);
// mostrar valor resultante
   printf ( "\n Volume do cubo: %f\n", volume );
   printf ( "\n Volume do solido com quatro vezes a medida do lado: %f\n", volume2 );
// encerrar
   printf ( "\n\nApertar ENTER para terminar." );
   fflush ( stdin ); // limpar a entrada de dados
   getchar( ); // aguardar por ENTER
   return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
