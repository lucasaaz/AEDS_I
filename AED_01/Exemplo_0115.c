/*
Exemplo0115 - v0.0. - 03 / 04 / 2020
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
   float altura = 0.0; 
   float base   = 0.0;
   float area   = 0.0; 
   float area2  = 0.0; 
// identificar
   printf ( "%s\n", "EXEMPLO0115 - Programa - v0.0" );
   printf ( "%s\n", "Autor: Lucas Augusto" );
   printf ( "\n" ); // mudar de linha
// ler do teclado
   printf ( "\n Digite um valor para a altura do triangulo: " );
   scanf ( "%f", &altura );
   printf ( "\n Digite um valor para a base do triangulo: " );
   scanf ( "%f", &base );
// operar valores
   area = (base * altura)/2;
   area2 = ((altura*2) * base)/2;
// mostrar valor resultante
   printf ( "\n Area do triangulo: %f\n", area );
   printf ( "\n Area do triangulo com o dobro da altura do mesmo: %f\n", area2 );
// encerrar
   printf ( "\n\nApertar ENTER para terminar." );
   fflush ( stdin ); // limpar a entrada de dados
   getchar( ); // aguardar por ENTER
   return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
