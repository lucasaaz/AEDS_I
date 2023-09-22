/*
Exemplo03 - v0.0. - 15 / 04 / 2021
Author: Lucas Augusto
*/

// dependencias
#include "io.h" // para definicoes proprias

/**
Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )

/**
Method01 - mostrar as letras minúsculas.
*/
void method01 ( )
{
// definir dado
   int x = 0;
   int y = 0;
   char palavra [STR_SIZE];
   int tamanho = 0;
   
// identificar
   IO_id ( "\nEXEMPLO0311 - Method01 - v0.0" );
   
// ler do teclado
   IO_printf ("Entrar com uma palavra: " );
   scanf ( "%s", palavra );
   
// repetir para cada letra
   tamanho = strlen ( palavra );
   
// inicio teste variacao para definir se M ou m
   for ( y = 0; y < tamanho; y = y + 1 )
   {  
      // se minuscula
      if ( 'a' <= palavra [y] && palavra [y] <= 'z' )
      {
         // mostrar letra atual
         IO_printf ( "\n [%c] - ", palavra [y] );
         IO_printf ( "Letra minuscula\n");
      }
   } // fim repetir
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )


/**
Method02 - mostrar as letras minúsculas.
*/
void method02 ( )
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   char palavra [STR_SIZE];
   int tamanho = 0;
   
// identificar
   IO_id ( "\nEXEMPLO0312 - Method02 - v0.0" );
   
// ler do teclado
   IO_printf ("Entrar com uma palavra: " );
   scanf ( "%s", palavra );
   
// repetir para cada letra
   tamanho = strlen ( palavra );
   
// inicio teste variacao para definir se M ou m
   for ( y = 0; y < tamanho; y = y + 1 )
   {  
      // se minuscula
      if ( 'a' <= palavra [y] && palavra [y] <= 'z' )
      {
         // mostrar letra atual
         IO_printf ( "\n %d - [%c] ", contar, palavra [y] );
         IO_printf ( "Letra minuscula\n");
         contar = contar + 1;
      }
   } // fim repetir
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )


/**
Method03 - mostrar as letras minúsculas.
*/
void method03 ( )
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   char palavra [STR_SIZE];
   int tamanho = 0;
   
// identificar
   IO_id ( "\nEXEMPLO0313 - Method03 - v0.0" );
   
// ler do teclado
   IO_printf ("Entrar com uma palavra: " );
   scanf ( "%s", palavra );
   
// repetir para cada letra
   tamanho = strlen ( palavra );
   
// inicio teste variacao para definir se M ou m
   while ( tamanho >= 0 )
   {  
      // se minuscula
      if ( 'a' <= palavra [tamanho] && palavra [tamanho] <= 'z' )
      {
         // mostrar letra atual
         IO_printf ( "\n %d - [%c] ", contar, palavra [tamanho] );
         IO_printf ( "Letra minuscula\n");
         contar = contar + 1;
      }
      tamanho = tamanho - 1;
   } // fim repetir
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )


/**
Method04 - mostrar as letras minúsculas.
*/
void method04 ( )
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   char palavra [STR_SIZE];
   int tamanho = 0;
   
// identificar
   IO_id ( "\nEXEMPLO0314 - Method04 - v0.0" );
   
// ler do teclado
   IO_printf ("Entrar com uma cadeia de caracteres do teclado: " );
   scanf ( "%s", palavra );
   
// repetir para cada letra
   tamanho = strlen ( palavra );
   
// inicio teste variacao para definir se M ou m
   while ( y <= tamanho )
   {  
      // se letra
      if ( isalpha (palavra [y]) )
      {
         // mostrar letra atual
         IO_printf ( "\n %d - [%c] ", contar, palavra [y] );
         IO_printf ( "Letra minuscula ou maiuscula\n");
         contar = contar + 1;
      }
      y = y + 1;
   } // fim repetir
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )


/**
Method05 - mostrar as letras minúsculas.
*/
void method05 ( )
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   char palavra [STR_SIZE];
   int tamanho = 0;
   
// identificar
   IO_id ( "\nEXEMPLO0315 - Method05 - v0.0" );
   
// ler do teclado
   IO_printf ("Entrar com uma cadeia de caracteres do teclado: " );
   scanf ( "%s", palavra );
   
// repetir para cada letra
   tamanho = strlen ( palavra );
   
// inicio teste variacao para definir se M ou m
   while ( tamanho >= 0 )
   {  
      // se minuscula
      if ( isdigit (palavra [tamanho]) )
      {
         // mostrar letra atual
         IO_printf ( "\n %d - [%c] ", contar, palavra [tamanho] );
         IO_printf ( "E' digito\n");
         contar = contar + 1;
      }
      tamanho = tamanho - 1;
   } // fim repetir
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )


/**
Method06 - mostrar as letras minúsculas.
*/
void method06 ( )
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   char palavra [STR_SIZE];
   int tamanho = 0;
   
// identificar
   IO_id ( "\nEXEMPLO0316 - Method06 - v0.0" );
   
// ler do teclado
   IO_printf ("Entrar com uma cadeia de caracteres do teclado: " );
   scanf ( "%s", palavra );
   IO_printf ("\n" );
   
// repetir para cada letra
   tamanho = strlen ( palavra );
   
// inicio teste variacao para definir se M ou m
   while ( y < tamanho )
   {  
      // se n letra
      if ( isalpha (palavra [y]) OR isdigit (palavra [y]) )
      {
      }
      else 
      {
         // mostrar letra atual
         IO_printf ( " %d - [%c] ", contar, palavra [y] );
         IO_printf ( "Nao e' letra e ");
         IO_printf ( "nao e' digito\n");
         contar = contar + 1;
      }    
      y = y + 1;
   } // fim repetir
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )


/**
Method07 - mostrar as letras minúsculas.
*/
void method07 ( )
{
// definir dado
   int limite_inferior = 0;
   int limite_superior = 0;
   int      quantidade = 0;
   int          contar = 0;
   int         numeros = 0;
   
// identificar
   IO_id ( "\nEXEMPLO0317 - Method07 - v0.0" );
   
// ler do teclado
   limite_inferior = IO_readint (" Limite inferior: ");
   limite_superior = IO_readint (" Limite superior: ");
   quantidade      = IO_readint (" Quantidade a ser testado: ");
   
// inicio teste variacao 
   while ( contar < quantidade )
   {
      printf (" \n Digite um numero: ");
      scanf  ("%d", &numeros);
      printf ("\n");
      
      if ( numeros % 7 == 0 )
      {
         IO_printf (" O numero %d e' dividido por 7 e", numeros);
      }
      else
      {
         IO_printf (" O numero %d nao e' dividido por 7 e", numeros);   
         
      }
      if ( limite_inferior <= numeros && numeros <= limite_superior )
      {
         IO_printf (" pertence ao intervalo [%d,%d]\n", limite_inferior, limite_superior);   
      }
      else
      {
         IO_printf (" nao pertence ao intervalo [%d,%d]\n", limite_inferior, limite_superior);
      }      
      contar = contar + 1;
   }
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )


/**
Method08 - mostrar as letras minúsculas.
*/
void method08 ( )
{
// definir dado
   int limite_inferior = 0;
   int limite_superior = 0;
   int      quantidade = 0;
   int          contar = 0;
   int         contar2 = 0;
   int         numeros = 0;
   
// identificar
   IO_id ( "\nEXEMPLO0318 - Method08 - v0.0" );
   
// ler do teclado
   limite_inferior = IO_readint (" Limite inferior: ");
   limite_superior = IO_readint (" Limite superior: ");
   quantidade      = IO_readint (" Quantidade a ser testado: ");
   
// inicio teste variacao     
   for (contar = 0; contar < quantidade; contar = contar + 1)
   {
      
      printf ("\n Digite um numero: ");
      scanf  ("%d", &numeros);
      printf ("\n");      
      
      if ( (numeros %7 == 0 && numeros %3 != 0) && (limite_inferior <= numeros && numeros <= limite_superior) )
      {
         contar2 = contar2 + 1;
         IO_printf ("[%d] - O numero %d e' dividido por 7 e nao por 3 e pertence ao intervalo [%d,%d]\n", 
                                                          contar2, numeros, limite_inferior, limite_superior);  
      }
      else
      {
         IO_printf (" O numero %d nao esta sobre o padrao\n");
      }
   }
   
   // contar valores dentro do padrao
   IO_printf("\n\n Resultado final: Dos %d testados, apenas %d numero/s estava(m) no padrao\n", quantidade, contar2);
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )


/**
Method09 - mostrar as letras minúsculas.
*/
void method09 ( )
{
// definir dado
   float limite_inferior = 0;
   float limite_superior = 0;
   float         numeros = 0;
   int        quantidade = 0;
   int            contar = 0;
   int           contar2 = 0;
   int          numeros2 = 0;
   
// identificar
   IO_id ( "\nEXEMPLO0319 - Method09 - v0.0" );
   
// ler do teclado
   printf (" Digite um valor real: ");  
   scanf  ("%f", &limite_inferior);
   do
   {  
      printf (" Digite um valor superior ao anterior: ");
      scanf  ("%f", &limite_superior);      
   } while ( limite_superior <= limite_inferior );   
   quantidade = IO_readint (" Quantidade a ser testado: ");
   
// inicio teste variacao     
   for (contar = 0; contar < quantidade; contar = contar + 1)
   {
      
      printf ("\n Digite um valor real: ");
      scanf  ("%f", &numeros);
      printf ("\n"); 
      numeros2 = numeros;     
      
      // se dentro do intervalo
      if ( limite_inferior <= numeros && numeros <= limite_superior )
      {
         printf (" %.2f - Esta dentro do intervalo [%.2f;%.2f] e", numeros, limite_inferior, limite_superior);
      }
      else
      {
         printf (" %.2f - Nao esta dentro do intervalo [%.2f;%.2f] e", numeros, limite_inferior, limite_superior);
      }
      // se impar
      if ( numeros2 %2 != 0 )
      {
         printf (" %d e' impar\n", numeros2, limite_inferior, limite_superior);
      }
      else
      {
         printf (" %d nao e' impar\n", numeros2, limite_inferior, limite_superior);
      }
      // se os dois
      if ((limite_inferior <= numeros && numeros <= limite_superior) && (numeros2 %2 != 0))
      {
         contar2 = contar2 + 1;
      }
   }

   // contar valores dentro do padrao
   IO_printf("\n\n Resultado final: %d numero(s) estava(m) no padrao\n", contar2);
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )


/**
Method10 - mostrar as letras minúsculas.
*/
void method10 ( )
{
// definir dado
   float limite_inferior = 0;
   float limite_superior = 0;
   float         numeros = 0;
   float       resultado = 0;
   int        quantidade = 0;
   int            contar = 0;
   int           contar2 = 0;
   int          numeros2 = 0;
   
// identificar
   IO_id ( "\nEXEMPLO0320 - Method10 - v0.0" );
   
// ler do teclado
   // numero entre 0 e 1
   do
   {
      printf (" Digite um valor real entre 0 e 1: ");  
      scanf  ("%f", &limite_inferior);
   } while ( limite_inferior <= 0 OR limite_inferior >= 1);
   
   // numero maior que o anterior e menor que 1
   do
   {  
      printf (" Digite um valor superior ao anterior e menor que 1: ");
      scanf  ("%f", &limite_superior);      
   } while ( limite_inferior >= limite_superior OR limite_superior >= 1 ); 
     
   quantidade = IO_readint (" Quantidade a ser testado: ");
   
// inicio teste variacao     
   for (contar = 0; contar < quantidade; contar = contar + 1)
   {
      
      printf ("\n Digite um valor real: ");
      scanf  ("%f", &numeros);
      printf ("\n");
      
      // valor inteiro 
      numeros2 = numeros; 
      
      // valor fracionado
      resultado = numeros - numeros2;   
      
      // se dentro do intervalo
      if ( limite_inferior < resultado && resultado < limite_superior )
      {
         printf (" %.2f - Esta dentro do intervalo [%.2f;%.2f]\n", resultado, limite_inferior, limite_superior);
         
         // contar quantas vezes ficou dentro do intervalo
         contar2 = contar2 + 1;
      }
      else
      {
         printf (" %.2f - Nao esta dentro do intervalo [%.2f;%.2f]\n", resultado, limite_inferior, limite_superior);
      }
   }

   // contar valores esta dentro do intervalo
   IO_printf("\n\n Resultado final: Dos %d testados, %d numero(s) estava(m) no intervalo [%.2f;%.2f]\n",
                                                        quantidade, contar2, limite_inferior, limite_superior);
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )



/*
Funcao principal.
*/
int main ( )
{
// definir dado
   int x = 0;
// repetir até desejar parar
   do
   {
   // identificar
      IO_id ( "EXEMPLO0301 - Programa - v0.0" );
   // ler do teclado
      IO_println ( "    Opcoes:" );
      IO_println ( " 0  - parar" );
      IO_println ( " 1  - Exemplo0311" );
      IO_println ( " 2  - Exemplo0312" );
      IO_println ( " 3  - Exemplo0313" );
      IO_println ( " 4  - Exemplo0314" );
      IO_println ( " 5  - Exemplo0315" );
      IO_println ( " 6  - Exemplo0316" );
      IO_println ( " 7  - Exemplo0317" );
      IO_println ( " 8  - Exemplo0318" );
      IO_println ( " 9  - Exemplo0319" );
      IO_println ( " 10 - Exemplo0320" );
      IO_println ( "" );
      x = IO_readint ( "Entrar com uma opcao: " );
   // testar valor
      switch ( x )
      {
         case 0:
            method00 ( );
            break;
         case 1:
            method01 ( );
            break;
         case 2:
            method02 ( );
            break;
         case 3:
            method03 ( );
            break;
         case 4:
            method04 ( );
            break;
         case 5:
            method05 ( );
            break;
         case 6:
            method06 ( );
            break; 
         case 7:
            method07 ( );
            break;
         case 8:
            method08 ( );
            break; 
         case 9:
            method09 ( );
            break;
         case 10:
            method10 ( );
            break;          
         default:
            IO_pause ( "ERRO: Valor invalido." );
      } // fim escolher
   }
   while ( x != 0 );// encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) "a"
b.) "abc"
c.) "abc def"
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/