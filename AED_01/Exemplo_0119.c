/*
Exemplo0119 - v0.0. - 03 / 04 / 2020
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
   float raio  = 0.0;
   float area  = 0.0;
   float area2 = 0.0; 
// identificar
   printf ( "%s\n", "EXEMPLO0119 - Programa - v0.0" );
   printf ( "%s\n", "Autor: Lucas Augusto" );
   printf ( "\n" ); // mudar de linha
// ler do teclado
   printf ( "\n Digite um valor para o raio do circulo: " );
   scanf ( "%f", &raio );
// operar valores
   area  = (M_PI) * pow((raio),2);
   area2 = (M_PI) * pow((raio/2),2);
// mostrar valor resultante
   printf ( "\n Area do círculo: %f\n", area );
   printf ( "\n Area do círculo com a metade do raio: %f\n", area2 );
// encerrar
   printf ( "\n\nApertar ENTER para terminar." );
   fflush ( stdin ); // limpar a entrada de dados
   getchar( ); // aguardar por ENTER
   return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
