/*
   ARQUIVO DE TESTES
*/

// dependencias (biblioteca)
#include "io.h" // para definicoes proprias


// Metodo - 1
void Metodo_01 ( )
{
// variaveis 
   int x = 1; // variavel crescente 
   int y; // variavel fixa
   int r; // resultado
// ler dados da tela
   IO_printf  ("\n Tabuada da matematica");
   y = IO_readint ("\n Tabuada de qual numero voce deseja saber? ");
// fazer tabuada
   while( x <= 10 )
   {
   // fazer a multiplicacao
      r = x * y;
   // respostas
      IO_printf ("\n  %d x %d = %d\n", x, y, r);
   // controle
      x = x + 1;
   }
// encerrar
   IO_pause ( "Apertar ENTER para terminar" );

} // fim Metodo - 1


// Metodo - 2
void Metodo_02 ( )
{
// variaveis 
   int controle = 1; // controle
   int    alunos;    // alunos
   int      nota;    // nota 
   int maior = 0;    // maior
   int menor = 0;    // menor
   float   x = 0;    // calcular media
   float   media;    // media
   char     nome;    // nome
   
// ler dados da tela
   IO_printf  ("\n Resultado da prova");
   alunos = IO_readint ("\n Quantos alunos serao analisados? ");
   
// definar dados
   menor = nota;
   
// fazer tabuada
   while( controle <= alunos )
   {
   // ler dados
      nome   = IO_readint ("\n Qual seu nome? ");
      nota   = IO_readint (" Qual foi sua nota? ");
   // maior nota
      if ( nota > maior)
      {
        maior = nota;
      }  
   // menor nota
      if ( nota < menor)
      {
         menor = nota;
      }   
   // soma
      x = x + nota;    
   // controle
      controle = controle + 1;
   }
   
// media
   media = x / alunos;
         
// mostrar dados
   IO_printf ("\n Media das notas: %f", media);
   IO_printf ("\n Maior nota: %d", maior);
   IO_printf ("\n Menor nota: %d\n", menor);
      
// encerrar
   IO_pause ( "Apertar ENTER para terminar" );

} // fim Metodo - 2


// Metodo - 3
void Metodo_03 ( )
{
// variaveis
   float    x = 1; // ajudante 
   float   number; // numero fatorial
   float fatorial; // resultado fatorial
  
// ler dados da tela
   IO_printf  ("\n Fatorial");
   number = IO_readint ("\n Fatorial de qual numero sera analisado? ");
   printf ("\n");
// fazer fatorial
   for ( fatorial = 1; number > 0; number = number - 1)
   {
      printf (" %.1lf!", number);
      fatorial = fatorial * number;
   }
   
// mostra resposta
   printf ("\n\n Fatorial = %.1lf\n", fatorial);
     
// encerrar
   IO_pause ( "\nApertar ENTER para terminar" );

} // fim Metodo - 3









/*

   Funcao principal.
   
*/
int main ()
{
// variavel
   int x;

// repeticao
   do
   {
   // escolher metodo
      printf("\n Opcoes:"        );
      printf("\n (0) - Fechar"   );
      printf("\n (1) - Tabuada");
      printf("\n (2) - Nota da Prova");
      printf("\n (3) - Fatorial");
      printf("\n");
   
   // ler metodo
      printf(" \n Escolha um Metodo? ");
      scanf ("%d", &x);
   
      switch ( x )
      {
         case 0 :
            printf("\n Faz nada\n");
            break;
      
         case 1 :
            Metodo_01 ( );
            break;
      
         case 2 :
            Metodo_02 ( );
            break;
      
          case 3 :
            Metodo_03 ( );
            break;
            
         default :
            printf ("Valor invalido!\n");
      }
   
   }
   while( x != 0); // fazer ate que escolha o 0
   
// encerrar
   return(0);
}