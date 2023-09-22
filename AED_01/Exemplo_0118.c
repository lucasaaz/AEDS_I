/*
Exemplo0118 - v0.0. - 03 / 04 / 2020
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
   float comprimento = 0.0;
   float largura     = 0.0; 
   float altura      = 0.0;
   float volume      = 0.0;
   float volume2     = 0.0;
// identificar
   printf ( "%s\n", "EXEMPLO0118 - Programa - v0.0" );
   printf ( "%s\n", "Autor: Lucas Augusto" );
   printf ( "\n" ); // mudar de linha
// ler do teclado
   printf ( "\n Digite um valor para o comprimento do paralelepipedo: " );
   scanf ( "%f", &comprimento );
   printf ( "\n Digite um valor para a largura do paralelepipedo: " );
   scanf ( "%f", &largura );
   printf ( "\n Digite um valor para a altura do paralelepipedo: " );
   scanf ( "%f", &altura );
// operar valores
   volume  = comprimento*largura*altura;
   volume2 = (comprimento/5)*(largura/5)*(altura/5);
// mostrar valor resultante
   printf ( "\n Volume do paralelepipedo: %f\n", volume );
   printf ( "\n Volume do solido com um quinto do seu lado: %f\n", volume2 );
// encerrar
   printf ( "\n\nApertar ENTER para terminar." );
   fflush ( stdin ); // limpar a entrada de dados
   getchar( ); // aguardar por ENTER
   return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
