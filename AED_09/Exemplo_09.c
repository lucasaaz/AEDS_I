/*
Exemplo09 - v0.0. - 06 / 06 / 2021
Author: Lucas Augusto
*/

// dependencias
#include "io.h"     // para definicoes proprias
#include <locale.h> // para usar os caracteres do portugues
#include <math.h> // para usar operadores matematicos

void Parar( ){ }

/**
 Ler as dimensões (quantidade de linhas e de colunas) de uma matriz real do teclado,
 bem como todos os seus elementos (apenas valores positivos).
*/

void mostrarMatrizReal(int linhas, int colunas, double matriz[linhas][colunas])
{
   int i = 0, j = 0;
   IO_printf ( "\n" );
   for (i = 0; i < linhas; i++)
   {
      for (j = 0; j < colunas; j++)
      {
         printf(" %.2lf\t", matriz[i][j]);
      }
      IO_printf ( "\n" );
   }
}

void Metodo01( )
{
    // definir dados
   int linhas  = 0; 
   int colunas = 0; 
   int i       = 0; 
   int j       = 0;
   double x = 0.0;

    // ler valores
   linhas = IO_readint("\nEntrar com a quantidade de linhas: ");
   colunas = IO_readint ("\nEntrar com a quantidade de colunas: ");
   double matriz[linhas][colunas];

   for (i = 0; i < linhas; i++)
   {
      for (j = 0; j < colunas; j++)
      {
         do
         {
            printf("\nEntre com o valor positivo para a posicao %d, %d = ", i, j);
            scanf("%lf", &x);
         } while (x < 0.0);
         matriz[i][j] = x;
      }
   }
   mostrarMatrizReal(linhas, colunas, matriz);
    
   IO_pause( "\nApertar ENTER para continuar" );
}





/**
 Gravar uma matriz real em arquivo, a matriz e o nome do arquivo serão dados como parâmetros.
*/

void lerDoArquivo(char *nomeDoArquivo, int linhas, int colunas, double matriz[][colunas])
{
   int x = 0;
   int y = 0;
   double z = 0;
   FILE *arquivo = fopen(nomeDoArquivo, "rt");

   fscanf(arquivo, "%d", &x);
   fscanf(arquivo, "%d", &y);
   if (linhas <= 0 || linhas > x || colunas <= 0 || colunas > y)
   {
   
   }
   else
   {
      x = 0;
      while (!feof(arquivo) && x < linhas)
      {
         y = 0;
         while (!feof(arquivo) && y < colunas)
         {
            fscanf(arquivo, "%lf", &z);
            matriz[x][y] = z;
            y = y + 1;
         }
         x = x + 1;
      }
      fclose(arquivo);
      mostrarMatrizReal(linhas, colunas, matriz);
   }
}

void gravarNoArquivo(char *nomeDoArquivo, int linhas, int colunas, double matriz[linhas][colunas])
{
   FILE *arquivo = fopen(nomeDoArquivo, "wt");

   fprintf(arquivo, " Linhas: %d\n", linhas);
   fprintf(arquivo, " Colunas: %d\n", colunas);
    
   if (linhas > 0 && colunas > 0)
   {
      fprintf(arquivo, "\n", colunas);
      for (int i = 0; i < linhas; i++)
      {
         for (int j = 0; j < colunas; j++)
         {
            fprintf(arquivo, " %.2lf\t", matriz[i][j]);
         }
         fprintf(arquivo, "\n", colunas);
      }
   }
   else
   {
      printf("\nQuantidade de linhas ou colunas invalida.");
   }
   fclose(arquivo);
}

void Metodo02( )
{
    // definir dados
   char nomeDoArquivo[80];
   int linhas  = 0; 
   int colunas = 0; 
   int i       = 0; 
   int j       = 0;
   double x = 0.0;

    // ler da tela
    // nome do arquivo
   printf("\nEntrar com nome do arquivo .txt: ");
   scanf("%s", nomeDoArquivo);
    // valores da matriz
   printf("\nEntrar com a quantidade de linhas: ");
   scanf("%d", &linhas);
   printf("\nEntrar com a quantidade de colunas: ");
   scanf("%d", &colunas);
    
   double matriz[linhas][colunas];

   for (i = 0; i < linhas; i++)
   {
      for (j = 0; j < colunas; j++)
      {
         do
         {
            printf("\nEntre com o valor positivo para a posicao %d, %d = ", i, j);
            scanf("%lf", &x);
         } while (x < 0.0);
         matriz[i][j] = x;
      }
   }
   gravarNoArquivo(nomeDoArquivo, linhas, colunas, matriz);
   lerDoArquivo(nomeDoArquivo, linhas, colunas, matriz);
    
   IO_pause( "\nApertar ENTER para continuar" );    
}







/**
 Mostrar somente os valores na diagonal principal de uma matriz real, se for quadrada.
*/

void diagonalPrincipal(int linhas, int colunas, double matriz[linhas][colunas])
{
   if (linhas == colunas)
   {
      int i = 0; 
      int j = 0;
        
      for (i = 0; i < linhas; i++)
      {
         for (j = 0; j < colunas; j++)
         {
            if (i == j)
            {
               printf("\n Valor da diagonal principal --> ");
               printf("posicao %d,%d = %.2lf", i, j, matriz[i][j]);
            }
         }
      }
   }
   else
   {
      printf("ERRO: Nao e' matriz quadrada");
   }
}

void Metodo03( )
{ 
    // definir dados
   int linhas  = 0; 
   int colunas = 0; 
   int i       = 0; 
   int j       = 0;
   double  x = 0.0;

    // ler da tela
   printf("\nEntrar com a quantidade de linhas: ");
   scanf("%d", &linhas);
   printf("\nEntrar com a quantidade de colunas: ");
   scanf("%d", &colunas);
    
   double matriz[linhas][colunas];

   for (i = 0; i < linhas; i++)
   {
      for (j = 0; j < colunas; j++)
      {
         printf("\nEntre com o valor da posicao %d, %d = ", i, j);
         scanf("%lf", &x);
         matriz[i][j] = x;
      }
   }
   diagonalPrincipal(linhas, colunas, matriz);
    
   IO_pause( "\nApertar ENTER para continuar" );     
}









/**
 Mostrar somente os valores na diagonal secundária de uma matriz real, se for quadrada.
*/

void diagonalSecundaria(int linhas, int colunas, double matriz[linhas][colunas])
{
   if (linhas == colunas)
   {
      int i = 0; 
      int x = colunas - 1;
      for (i = 0; i < linhas; i++)
      {
         printf("\n Valor da diagonal secundaria --> ");
         printf("posicao %d,%d = %.2lf", i, x, matriz[i][x]);
         x = x -1;
      }
   }
   else
   {
      printf("ERRO: Nao e' matriz quadrada");
   }
}

void Metodo04( )
{ 
    // definir dados
   int linhas  = 0; 
   int colunas = 0; 
   int i       = 0; 
   int j       = 0;
   double  x = 0.0;

    // ler da tela
   printf("\nEntrar com a quantidade de linhas: ");
   scanf("%d", &linhas);
   printf("\nEntrar com a quantidade de colunas: ");
   scanf("%d", &colunas);
    
   double matriz[linhas][colunas];

   for (i = 0; i < linhas; i++)
   {
      for (j = 0; j < colunas; j++)
      {
         printf("\nEntre com o valor da posicao %d, %d = ", i, j);
         scanf("%lf", &x);
         matriz[i][j] = x;
      }
   }
   diagonalSecundaria(linhas, colunas, matriz);
    
   IO_pause( "\nApertar ENTER para continuar" );     
}






/**
 Mostrar somente os valores abaixo da diagonal principal de uma matriz real, se for quadrada.
*/

void abaixoDiagonalPrincipal(int linhas, int colunas, double matriz[linhas][colunas])
{
   if (linhas == colunas)
   {
      int i = 0; 
      int j = 0;
        
      for (i = 0; i < linhas; i++)
      {
         for (j = 0; j < colunas; j++)
         {
            if (i > j)
            {
               printf("\n Valor abaixo da diagonal principal --> ");
               printf("posicao %d,%d = %.2lf", i, j, matriz[i][j]);
            }
         }
      }
   }
   else
   {
      printf("ERRO: Nao e' matriz quadrada");
   }
}

void Metodo05( )
{
   int linhas = 0, colunas = 0, i = 0, j = 0;
   double x = 0.0;

   printf("\nEntrar com a quantidade de linhas: ");
   scanf("%d", &linhas);
   printf("\nEntrar com a quantidade de colunas: ");
   scanf("%d", &colunas);
   double matriz[linhas][colunas];

   for (i = 0; i < linhas; i++)
   {
      for (j = 0; j < colunas; j++)
      {
         printf("\nEntre com o valor da posicao %d, %d = ", i, j);
         scanf("%lf", &x);
         matriz[i][j] = x;
      }
   }
   abaixoDiagonalPrincipal(linhas, colunas, matriz);

   IO_pause( "\nApertar ENTER para continuar" );
}






/**
 Mostrar somente os valores acima da diagonal principal de uma matriz real, se for quadrada.
*/

void acimaDiagonalPrincipal(int linhas, int colunas, double matriz[linhas][colunas])
{
   if (linhas == colunas)
   {
      int i = 0; 
      int j = 0;
        
      for (i = 0; i < linhas; i++)
      {
         for (j = 0; j < colunas; j++)
         {
            if (i < j)
            {
               printf("\n Valor acima da diagonal principal --> ");
               printf("posicao %d,%d = %.2lf", i, j, matriz[i][j]);
            }
         }
      }
   }
   else
   {
      printf("ERRO: Nao e' matriz quadrada");
   }
}

void Metodo06( )
{
   int linhas = 0, colunas = 0, i = 0, j = 0;
   double x = 0.0;

   printf("\nEntrar com a quantidade de linhas: ");
   scanf("%d", &linhas);
   printf("\nEntrar com a quantidade de colunas: ");
   scanf("%d", &colunas);
   double matriz[linhas][colunas];

   for (i = 0; i < linhas; i++)
   {
      for (j = 0; j < colunas; j++)
      {
         printf("\nEntre com o valor da posicao %d, %d = ", i, j);
         scanf("%lf", &x);
         matriz[i][j] = x;
      }
   }
   acimaDiagonalPrincipal(linhas, colunas, matriz);

   IO_pause( "\nApertar ENTER para continuar" );
}






/*
 Mostrar somente os valores abaixo da diagonal secundária de uma matriz real, se for quadrada.
*/

void abaixoDiagonalSecundaria(int linhas, int colunas, double matriz[linhas][colunas])
{
   if (linhas == colunas)
   {
      int i = 0; 
      int j = 0;
      int l = linhas;
      int Z = 1;
              
        
      for (i = linhas; i > 1; i--)
      {
         for (j = colunas; j > Z; j--)
         {
            printf("\n Valor abaixo da diagonal secundaria --> ");
            printf("posicao %d,%d = %.2lf", i, j, matriz[l][j]);    
         }
         Z = Z + 1;
         l = l - 1;
      }
   }
   else
   {
      printf("ERRO: Nao e' matriz quadrada");
   }
}

void Metodo07( )
{ 
    // definir dados
   int linhas  = 0; 
   int colunas = 0; 
   int i       = 1; 
   int j       = 1;
   double  x = 0.0;

    // ler da tela
   printf("\nEntrar com a quantidade de linhas: ");
   scanf("%d", &linhas);
   printf("\nEntrar com a quantidade de colunas: ");
   scanf("%d", &colunas);
    
   double matriz[linhas][colunas];

   for (i = 1; i <= linhas; i++)
   {
      for (j = 1; j <= colunas; j++)
      {
         printf("\nEntre com o valor da posicao %d, %d = ", i, j);
         scanf("%lf", &x);
         matriz[i][j] = x;
      }
   }
   abaixoDiagonalSecundaria(linhas, colunas, matriz);
    
   IO_pause( "\nApertar ENTER para continuar" );     
}









/*
 Mostrar somente os valores acima da diagonal secundária de uma matriz real, se for quadrada.
*/

void acimaDiagonalSecundaria(int linhas, int colunas, double matriz[linhas][colunas])
{
   if (linhas == colunas)
   {
      int i = 0; 
      int j = 0;
      int x = colunas - 1;
        
        
      for (i = 0; i < linhas; i++)
      {
         for (j = 0; j < x; j++)
         {
            printf("\n Valor acima da diagonal principal --> ");
            printf("posicao %d,%d = %.2lf", i, j, matriz[i][j]);
         }
         x = x - 1;           
      }
   }
   else
   {
      printf("ERRO: Nao e' matriz quadrada");
   }
}

void Metodo08( )
{ 
    // definir dados
   int linhas  = 0; 
   int colunas = 0; 
   int i       = 0; 
   int j       = 0;
   double  x = 0.0;

    // ler da tela
   printf("\nEntrar com a quantidade de linhas: ");
   scanf("%d", &linhas);
   printf("\nEntrar com a quantidade de colunas: ");
   scanf("%d", &colunas);
    
   double matriz[linhas][colunas];

   for (i = 0; i < linhas; i++)
   {
      for (j = 0; j < colunas; j++)
      {
         printf("\nEntre com o valor da posicao %d, %d = ", i, j);
         scanf("%lf", &x);
         matriz[i][j] = x;
      }
   }
   acimaDiagonalSecundaria(linhas, colunas, matriz);
    
   IO_pause( "\nApertar ENTER para continuar" );     
}










/**
 testar se não são todos zeros os valores abaixo da diagonal principal de uma matriz real quadrada.
*/

void abaixoDiagonalPrincipalsemZero(int linhas, int colunas, double matriz[linhas][colunas])
{
   if (linhas == colunas)
   {
      int i    = 0; 
      int j    = 0;
      int zero = 0;
        
      for (i = 0; i < linhas; i++)
      {
         for (j = 0; j < colunas; j++)
         {
            if (matriz[i][j] == 0 )
            {
               zero = zero + 1;
               printf("\n Erro: possui %d valor(es) 0 abaixo da diagonal principal", zero);
            }
            else
            {
               if ( i > j )
               {
                  printf("\n Valor abaixo da diagonal principal --> ");
                  printf("posicao %d,%d = %.2lf", i, j, matriz[i][j]); 
               }               
            }
         }
      }
   }
   else
   {
      printf("ERRO: Nao e' matriz quadrada");
   }
}

void Metodo09( )
{
   int linhas = 0, colunas = 0, i = 0, j = 0;
   double x = 0.0;

   printf("\nEntrar com a quantidade de linhas: ");
   scanf("%d", &linhas);
   printf("\nEntrar com a quantidade de colunas: ");
   scanf("%d", &colunas);
   double matriz[linhas][colunas];

   for (i = 0; i < linhas; i++)
   {
      for (j = 0; j < colunas; j++)
      {
         printf("\nEntre com o valor da posicao %d, %d = ", i, j);
         scanf("%lf", &x);
         matriz[i][j] = x;
      }
   }
   abaixoDiagonalPrincipalsemZero(linhas, colunas, matriz);

   IO_pause( "\nApertar ENTER para continuar" );
}












/**
 testar se são zeros os valores acima da diagonal principal de uma matriz real quadrada.
*/

void acimaDiagonalPrincipalsemZero(int linhas, int colunas, double matriz[linhas][colunas])
{
   if (linhas == colunas)
   {
      int i    = 0; 
      int j    = 0;
      int zero = 0;
        
      for (i = 0; i < linhas; i++)
      {
         for (j = 0; j < colunas; j++)
         {
            if (matriz[i][j] == 0)
            {
               zero = zero + 1;
               printf("\n Valor acima da diagonal principal --> ");
               printf("posicao %d,%d = %.2lf", i, j, matriz[i][j]);
            }
            else
            {
               if (i < j)
               {
                  printf("\n Valor acima da diagonal principal --> ");
                  printf("posicao %d,%d = %.2lf", i, j, matriz[i][j]);
               }
            }
         }
      }
   // Resulado final
   printf("\n\n Erro: possui %d valor(es) 0 acima da diagonal principal", zero);
   }
   else
   {
      printf("ERRO: Nao e' matriz quadrada");
   }

}

void Metodo10( )
{
   int linhas = 0, colunas = 0, i = 0, j = 0;
   double x = 0.0;

   printf("\nEntrar com a quantidade de linhas: ");
   scanf("%d", &linhas);
   printf("\nEntrar com a quantidade de colunas: ");
   scanf("%d", &colunas);
   double matriz[linhas][colunas];

   for (i = 0; i < linhas; i++)
   {
      for (j = 0; j < colunas; j++)
      {
         printf("\nEntre com o valor da posicao %d, %d = ", i, j);
         scanf("%lf", &x);
         matriz[i][j] = x;
      }
   }
   acimaDiagonalPrincipalsemZero(linhas, colunas, matriz);

   IO_pause( "\nApertar ENTER para continuar" );
}








int main ( )
{
   int x = 0;

   do
   {
      IO_id ( "EXEMPLO06 - Programa - v0.0" );
    
      IO_println ( "    Opcoes:" );
      IO_println ( " 0  - parar" );
      IO_println ( " 1  - Exemplo0911" );
      IO_println ( " 2  - Exemplo0912" );
      IO_println ( " 3  - Exemplo0913" );
      IO_println ( " 4  - Exemplo0914" );
      IO_println ( " 5  - Exemplo0915" );
      IO_println ( " 6  - Exemplo0916" );
      IO_println ( " 7  - Exemplo0917" );
      IO_println ( " 8  - Exemplo0918" );
      IO_println ( " 9  - Exemplo0919" );
      IO_println ( " 10 - Exemplo0920" );
      IO_println ( "" );
      x = IO_readint ( "Escolha uma opcao: " );
   
      switch ( x )
      {
         case 0:
            Parar ( );
            break;
      
         case 1:
            Metodo01 ( );
            break;
      
         case 2:
            Metodo02 ( );
            break;
      
         case 3:
            Metodo03 ( );
            break;
      
         case 4:
            Metodo04 ( );
            break;
      
         case 5:
            Metodo05 ( );
            break;
      
         case 6:
            Metodo06 ( );
            break;
      
         case 7:
            Metodo07 ( );
            break;
      
         case 8:
            Metodo08 ( );
            break;
      
         case 9:
            Metodo09 ( );
            break;
      
         case 10:
            Metodo10 ( );
            break;    
      
         default:
            break;
      }
   } while ( x != 0 );
    
   IO_pause ( "Apretar ENTER para continuar" );
   return( 0 );
}