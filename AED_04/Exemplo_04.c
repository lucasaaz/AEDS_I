/*
Exemplo04 - v0.0. - 25 / 04 / 2021
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
Method01 - Contar quantos desses valores estão dentro do intervalo, e quantos estão fora dele.
*/
void method01 ( )
{
// definir dado
   float inferior = 0;
   float superior = 0;
   int     dentro = 0;
   int       fora = 0;
   float   numero = 0;
   int quantidade = 0;
   int      valor = 0;
   int   controle = 0;
   
// identificar
   IO_id ( "EXEMPLO0401 - Method01 - v0.0" );
   
// ler do teclado
   inferior   = IO_readfloat ( " Digite um valor inferior: "  );
   superior   = IO_readfloat ( " Digite um valor superior: "  );
   quantidade = IO_readfloat ( " Entrar com uma quantidade: " );
   printf ("\n");
   
// repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
   // ler valor do teclado
      valor = IO_readint ( IO_concat (
         IO_concat ( "", IO_toString_d ( controle ) ),
          ": " ) );
   // se dentro
   if ( inferior <= valor && valor <= superior )
   {
      printf (" Dentro do intervalo\n\n");
      dentro = dentro + 1;
   }
   else 
   {
      printf (" Fora do intervalo\n\n");
      fora = fora + 1;
   }
   // passar ao proximo valor
      controle = controle + 1;
   } // fim repetir
   
// resultado
   printf ( " Apenas %d esta(m) dentro do intervalo e %d esta(m) fora do intervalo\n", dentro, fora );
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )


/**
Method02 - Contar e mostrar a quantidade de letras maiúsculas menores que 'K'.
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
   IO_id ( "\nEXEMPLO0412 - Method02 - v0.0" );
   
// ler do teclado
   IO_printf (" Entrar com uma palavra: " );
   scanf ( "%s", palavra );
   
// repetir para cada letra
   tamanho = strlen ( palavra );
   
// inicio teste de repetição
   for ( y = 0; y < tamanho; y = y + 1 )
   {  
      // se maiuscula
      if ( isupper(palavra [y]) && 'A' <= palavra [y] && palavra [y] <= 'K' )
      {
         // mostrar letra atual
         IO_printf ( "\n %d - [%c] ", contar, palavra [y] );
         IO_printf ( "Letra maiuscula e menor que K\n");
         contar = contar + 1;
      }
   } // fim repetir
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )









/**
Funcao03 - Mostrar a quantidade de letras maiúsculas menores que 'K' .
*/
int funcao03(char palavra2 [STR_SIZE])
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   int tamanho = 0;
   
// repetir para cada letra
   tamanho = strlen ( palavra2 );

// inicio teste de repetição
   for ( y = 0; y < tamanho; y = y + 1 )
   {  
      // se maiuscula
      if ( isupper(palavra2 [y]) && 'A' <= palavra2 [y] && palavra2 [y] <= 'K' )
      {
         // mostrar letra atual
         contar = contar + 1;
      }
   } // fim repetir
   
// resultado
   contar = contar - 1; // corrigir numero total de letras mauiscula menor que K
   return(contar);
} // fim Funcao03

/**
Method03 - Mostrar a quantidade de letras maiúsculas menores que 'K' .
*/
void method03 ( )
{
// definir dado
   char palavra [STR_SIZE];
   int resultado;
   
// identificar
   IO_id ( "\nEXEMPLO0413 - Method03 - v0.0" );
   
// ler do teclado
   IO_printf (" Entrar com uma palavra: " );
   scanf ( "%s", palavra );

//chama a função e recebe o retorno
  resultado = funcao03(palavra);
  
//resultado
   printf(" \n Apenas %d letras maiusculas menores que 'K'\n", resultado);
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )







/**
Funcao04 - Mostrar as letras maiúsculas menores que 'K'.
*/
int funcao04(char palavra2 [STR_SIZE])
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   int tamanho = 0;
   
// repetir para cada letra
   tamanho = strlen ( palavra2 );

// inicio teste de repetição
   for ( y = 0; y < tamanho; y = y + 1 )
   {  
      // se maiuscula
      if ( isupper(palavra2 [y]) && 'A' <= palavra2 [y] && palavra2 [y] <= 'K' )
      {
         // mostrar letra atual
         IO_printf ( "\n %d - [%c] ", contar, palavra2 [y] );
         IO_printf ( "Letra maiuscula e menor que K\n");
         contar = contar + 1;
      }
   } // fim repetir
   
// resultado
   contar = contar - 1; // corrigir numero total de letras mauiscula menor que K
   return(contar);
} // fim Funcao04

/**
Method04 - Mostrar as letras maiúsculas menores que 'K'.
*/
void method04 ( )
{
// definir dado
   char palavra [STR_SIZE];
   int resultado;
   
// identificar
   IO_id ( "\nEXEMPLO0414 - Method04 - v0.0" );
   
// ler do teclado
   IO_printf (" Entrar com uma palavra: " );
   scanf ( "%s", palavra );

//chama a função e recebe o retorno
  resultado = funcao04(palavra);
  
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )






/**
Funcao05 - Mostrar a quantidade de letras (tanto maiúsculas, quanto minúsculas) menores que 'K' e 'k'.
*/
int funcao05(char palavra2 [STR_SIZE])
{
// definir dado
   int       x = 0;
   int       y = 0;
   int  contar = 1;
   int contar2 = 1;
   int tamanho = 0;
   
// repetir para cada letra
   tamanho = strlen ( palavra2 );

// inicio teste de repetição
   for ( y = 0; y < tamanho; y = y + 1 )
   {  
      // se maiuscula
      if ( isupper(palavra2 [y]) && 'A' <= palavra2 [y] && palavra2 [y] <= 'K' )
      {
         // mostrar letra atual
         contar = contar + 1;
      }
      // se minuscula
      if ( islower(palavra2 [y]) && 'a' <= palavra2 [y] && palavra2 [y] <= 'k' )
      {
         // mostrar letra atual
         contar = contar + 1;
      }
   } // fim repetir
   
// resultado
   contar = contar - 1; // corrigir numero total de letras mauiscula menor que K
   return(contar);
} // fim Funcao05

/**
Method05 - Mostrar a quantidade de letras (tanto maiúsculas, quanto minúsculas) menores que 'K' e 'k'.
*/
void method05 ( )
{
// definir dado
   char palavra [STR_SIZE];
   int resultado;
   
// identificar
   IO_id ( "\nEXEMPLO0415 - Method05 - v0.0" );
   
// ler do teclado
   IO_printf (" Entrar com uma palavra: " );
   scanf ( "%s", palavra );

//chama a função e recebe o retorno
  resultado = funcao05(palavra);
  
//resultado
   printf(" \n Apenas %d letras maiusculas/minusculas menores que 'K'/'k'\n", resultado);
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )






/**
Funcao06 - Mostrar as letras (tanto maiúsculas, quanto minúsculas) menores que 'K' e 'k'.
*/
int funcao06(char palavra2 [STR_SIZE])
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   int tamanho = 0;
   
// repetir para cada letra
   tamanho = strlen ( palavra2 );

// inicio teste de repetição
   for ( y = 0; y < tamanho; y = y + 1 )
   {  
      // se maiuscula
      if ( isupper(palavra2 [y]) && 'A' <= palavra2 [y] && palavra2 [y] <= 'K' )
      {
         // mostrar letra atual
         IO_printf ( "\n %d - [%c] ", contar, palavra2 [y] );
         IO_printf ( "Letra maiuscula e menor que K\n");
         contar = contar + 1;
      }
      // se minuscula
      if ( islower(palavra2 [y]) && 'a' <= palavra2 [y] && palavra2 [y] <= 'k' )
      {
         // mostrar letra atual
         IO_printf ( "\n %d - [%c] ", contar, palavra2 [y] );
         IO_printf ( "Letra minuscula e menor que k\n");
         contar = contar + 1;
      }
   } // fim repetir
   
// resultado
   contar = contar - 1; // corrigir numero total de letras mauiscula menor que K
   return(contar);
} // fim Funcao06

/**
Method06 - Mostrar as letras (tanto maiúsculas, quanto minúsculas) menores que 'K' e 'k'.
*/
void method06 ( )
{
// definir dado
   char palavra [STR_SIZE];
   int resultado;
   
// identificar
   IO_id ( "\nEXEMPLO0416 - Method06 - v0.0" );
   
// ler do teclado
   IO_printf (" Entrar com uma palavra: " );
   scanf ( "%s", palavra );

//chama a função e recebe o retorno
  resultado = funcao06(palavra);
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )








/**
Funcao07 - Mostrar a quantidade de dígitos ímpares em uma cadeia de caracteres.
*/
int funcao07(char palavra2 [STR_SIZE])
{
// definir dado
   int       x = 0;
   int       y = 0;
   int  contar = 1;
   int contar2 = 1;
   int tamanho = 0;
   
// repetir para cada letra
   tamanho = strlen ( palavra2 );

// inicio teste de repetição
   for ( y = 0; y < tamanho; y = y + 1 )
   {  
      // se digito e impar
      if ( isdigit(palavra2 [y]) && palavra2 [y]%2 != 0  )
      {
         // mostrar letra atual
         contar = contar + 1;
      }
   } // fim repetir
   
// resultado
   contar = contar - 1; // corrigir numero total de letras mauiscula menor que K
   return(contar);
} // fim Funcao07

/**
Method07 - Mostrar a quantidade de dígitos ímpares em uma cadeia de caracteres.
*/
void method07 ( )
{
// definir dado
   char palavra [STR_SIZE];
   int resultado;
   
// identificar
   IO_id ( "\nEXEMPLO0417 - Method07 - v0.0" );
   
// ler do teclado
   IO_printf (" Entrar com uma palavra: " );
   scanf ( "%s", palavra );

//chama a função e recebe o retorno
  resultado = funcao07(palavra);
  
//resultado
   printf(" \n Apenas %d digito(s) impar(es)\n", resultado);
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )










/**
Funcao08 - Mostrar todos os símbolos nao alfanuméricos.
*/
int funcao08(char palavra2 [STR_SIZE])
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   int tamanho = 0;   
   
// repetir para cada letra
   tamanho = strlen ( palavra2 );   

// inicio teste variacao
   while ( y < tamanho )
   {  
      // se n letra
      if ( isalpha (palavra2 [y]) OR isdigit (palavra2 [y]) )
      {
      }
      else 
      {
         // mostrar letra atual
         IO_printf ( " %d - [%c] ", contar, palavra2 [y] );
         IO_printf ( "Nao e' letra e ");
         IO_printf ( "nao e' digito\n");
         contar = contar + 1;
      }    
      y = y + 1;
   } // fim repetir
   
// resultado
   contar = contar - 1; // corrigir numero total de letras mauiscula menor que K
   return(contar);

} // fim Funcao08

/**
Method08 - Mostrar todos os símbolos nao alfanuméricos.
*/
void method08 ( )
{
// definir dado
   char palavra [STR_SIZE];
   int resultado;
  
// identificar
   IO_id ( "\nEXEMPLO0418 - Method08 - v0.0" );
   
// ler do teclado
   IO_printf (" Entrar com uma cadeia de caracteres do teclado: " );
   scanf ( "%s", palavra );
   IO_printf ("\n" );
   
//chama a função e recebe o retorno
   resultado = funcao08(palavra);
  
//resultado
   printf(" \n Apenas %d simbolo(s) nao alfanumerico(s)\n", resultado);
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )






/**
Funcao09 - Mostrar todos os símbolos alfanuméricos.
*/
int funcao09(char palavra2 [STR_SIZE])
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   int tamanho = 0;   
   
// repetir para cada letra
   tamanho = strlen ( palavra2 );   

// inicio teste variacao
   while ( y < tamanho )
   {  
      // se n letra
      if ( isalpha (palavra2 [y]) OR isdigit (palavra2 [y]) )
      {
         // mostrar letra atual
         IO_printf ( " %d - [%c] ", contar, palavra2 [y] );
         IO_printf ( " E' letra ou ");
         IO_printf ( "digito\n");
         contar = contar + 1;
      } 
      y = y + 1;
   } // fim repetir
   
// resultado
   contar = contar - 1; // corrigir numero total de letras mauiscula menor que K
   return(contar);

} // fim Funcao09

/**
Method09 - Mostrar todos os símbolos alfanuméricos.
*/
void method09 ( )
{
// definir dado
   char palavra [STR_SIZE];
   int resultado;
  
// identificar
   IO_id ( "\nEXEMPLO0419 - Method09 - v0.0" );
   
// ler do teclado
   IO_printf (" Entrar com uma cadeia de caracteres do teclado: " );
   scanf ( "%s", palavra );
   IO_printf ("\n" );
   
//chama a função e recebe o retorno
   resultado = funcao09(palavra);
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )








/**
Funcao10 - Mostrar e contar a quantidade de símbolos alfanuméricos (letras e dígitos) em cada palavra.
*/
int funcao10(char palavra2 [STR_SIZE])
{
// definir dado
   int      x = 0;
   int      y = 0;
   int contar = 1;
   int tamanho = 0;   
   
// repetir para cada letra
   tamanho = strlen ( palavra2 );   

// inicio teste variacao
   while ( y < tamanho )
   {  
      // se n letra
      if ( isalpha (palavra2 [y]) OR isdigit (palavra2 [y]) )
      {
         // mostrar letra atual
         IO_printf ( " %d - [%c] ", contar, palavra2 [y] );
         IO_printf ( " E' letra ou ");
         IO_printf ( "digito\n");
         contar = contar + 1;
      } 
      y = y + 1;
   } // fim repetir
   
// resultado
   contar = contar - 1; // corrigir numero total de letras mauiscula menor que K
   return(contar);

} // fim Funcao10


/**
Method10 - Mostrar e contar a quantidade de símbolos alfanuméricos (letras e dígitos) em cada palavra.
*/
void method10 ( )
{
// definir dado
   char palavra [STR_SIZE];
   int resultado;
  
// identificar
   IO_id ( "\nEXEMPLO0420 - Method10 - v0.0" );
   
// ler do teclado
   IO_printf (" Entrar com uma cadeia de caracteres do teclado: " );
   scanf ("%s", palavra );
   IO_printf ("\n" );
   
//chama a função e recebe o retorno
   resultado = funcao10(palavra);
  
//resultado
   printf(" \n Apenas %d simbolo(s) alfanumerico(s)\n", resultado);
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

// NAO CONSEGUIR FAZER LER O ESPAÇO







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
      IO_id ( "EXEMPLO0401 - Programa - v0.0" );
   // ler do teclado
      IO_println ( "    Opcoes:" );
      IO_println ( " 0  - parar" );
      IO_println ( " 1  - Exemplo0411" );
      IO_println ( " 2  - Exemplo0412" );
      IO_println ( " 3  - Exemplo0413" );
      IO_println ( " 4  - Exemplo0414" );
      IO_println ( " 5  - Exemplo0415" );
      IO_println ( " 6  - Exemplo0416" );
      IO_println ( " 7  - Exemplo0417" );
      IO_println ( " 8  - Exemplo0418" );
      IO_println ( " 9  - Exemplo0419" );
      IO_println ( " 10 - Exemplo0420" );
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