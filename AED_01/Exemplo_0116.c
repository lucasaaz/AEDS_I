/*
Exemplo0116 - v0.0. - 03 / 04 / 2020
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
   float altura    = 0.0; 
   float lado      = 0.0;
   float area      = 0.0; 
   float perimetro = 0.0; 
// identificar
   printf ( "%s\n", "EXEMPLO0116 - Programa - v0.0" );
   printf ( "%s\n", "Autor: Lucas Augusto" );
   printf ( "\n" ); // mudar de linha
// ler do teclado
   printf ( "\n Digite um valor para o lado do triangulo equilatero: " );
   scanf ( "%f", &lado );
// operar valores
   altura = ((lado/2) * sqrt(3) / 2);
   area = (((lado/2) * sqrt(3) / 2) * (lado/2)) / 2;
   perimetro = (lado/2) * 3;
// mostrar valor resultante
   printf ( "\n Area do triangulo com metade do lado: %f\n", area );
   printf ( "\n Altura do triangulo com metade do lado: %f\n", altura );
   printf ( "\n Perimetro do triangulo com metade do lado: %f\n", perimetro );
// encerrar
   printf ( "\n\nApertar ENTER para terminar." );
   fflush ( stdin ); // limpar a entrada de dados
   getchar( ); // aguardar por ENTER
   return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
