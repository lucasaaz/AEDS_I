/*
Exemplo0111 - v0.0. - 03 / 04 / 2020
Author: Lucas Augusto
*/

// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h> // para cadeias de caracteres
#include <math.h> // para funcoes matemáticas: pow( ), sqrt( ), sin( ), cos( ) ...

/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dados
   int lado = 0; // definir variavel com valor inicial
   int area = 0; // definir variavel com valor inicial
   int resultado = 0; // definir variavel com valor inicial
// identificar
   printf ( "%s\n", "EXEMPLO0111 - Programa - v0.0" );
   printf ( "%s\n", "Autor: Lucas Augusto" );
   printf ( "\n" ); // mudar de linha
// ler do teclado
   printf ( "\n Digite o valor do lado do quadraro: " );
   scanf ( "%d", &lado );
// operar valores
   area = lado*lado;
   resultado = area / 4;
// mostrar valor resultante
   printf ( "\n Valor da area do quadrado: %d\n", area );
   printf ( "\n Um quarto da area do quadrado: %d\n", resultado );
// encerrar
   printf ( "\n\nApertar ENTER para terminar." );
   fflush ( stdin ); // limpar a entrada de dados
   getchar( ); // aguardar por ENTER
   return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
