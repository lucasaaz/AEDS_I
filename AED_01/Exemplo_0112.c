/*
Exemplo0112 - v0.0. - 03 / 04 / 2020
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
   int lado = 0; 
   int area = 0; 
   int area2 = 0; 
   int perimetro = 0; 
// identificar
   printf ( "%s\n", "EXEMPLO0112 - Programa - v0.0" );
   printf ( "%s\n", "Autor: Lucas Augusto" );
   printf ( "\n" ); // mudar de linha
// ler do teclado
   printf ( "\n Digite o valor do lado do quadraro: " );
   scanf ( "%d", &lado );
// operar valores
   area = lado * lado;
   area2 = (lado/2) * (lado/2);
   perimetro = (lado/2) * 4;
// mostrar valor resultante
   printf ( "\n Area do quadrado: %d\n", area );
   printf ( "\n Area do quadrado com metade do tamanho do lado: %d\n", area2 );
   printf ( "\n Perimetro do quadrado com metade do tamanho do lado: %d\n", perimetro );
// encerrar
   printf ( "\n\nApertar ENTER para terminar." );
   fflush ( stdin ); // limpar a entrada de dados
   getchar( ); // aguardar por ENTER
   return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
