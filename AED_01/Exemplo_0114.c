/*
Exemplo0114 - v0.0. - 03 / 04 / 2020
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
   int lado      = 0.0; 
   int lado2     = 0.0;
   int area      = 0.0; 
   int area2     = 0.0; 
   int perimetro = 0.0;
// identificar
   printf ( "%s\n", "EXEMPLO0114 - Programa - v0.0" );
   printf ( "%s\n", "Autor: Lucas Augusto" );
   printf ( "\n" ); // mudar de linha
// ler do teclado
   printf ( "\n RETANGULO " );
   printf ( "\n Digite um valor para o lado do retangulo: " );
   scanf ( "%d", &lado );
   printf ( "\n Digite outro valor para o lado do retangulo: " );
   scanf ( "%d", &lado2 );
// operar valores
   area = (lado * lado2);
   area2 = (lado/3) * (lado2/3);
   perimetro = ((lado/3)*2)+((lado2/3)*2);
// mostrar valor resultante
   printf ( "\n Area do retangulo: %d\n", area );
   printf ( "\n Area do retangulo com um terco do tamanho dos lados: %d\n", area2 );
   printf ( "\n Perimetro do retangulo com um terco do tamanho dos lados: %d\n", perimetro );
// encerrar
   printf ( "\n\nApertar ENTER para terminar." );
   fflush ( stdin ); // limpar a entrada de dados
   getchar( ); // aguardar por ENTER
   return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
