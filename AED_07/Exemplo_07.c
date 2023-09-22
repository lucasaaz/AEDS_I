/*
Exemplo04 - v0.0. - 18 / 05 / 2021
Author: Lucas Augusto
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void Parar( ){ }

/**
 Ler um valor inteiro do teclado e gravar essa quantidade em múltiplos de 3,
 pares,em ordem crescente, começando em 3.
*/

void multTresPar(chars fileName, int n)
{
    FILE *file = fopen(fileName, "wt");
    int x = 0;

    for (int i = 1; i <= n; i++)
    {
        x = 3 * 2 * i;
        fprintf(file, "%d\n", x);
    }

    fclose(file);
}

void Metodo01( )
{

// definir dado
    int quantidade = 0;

// identificar
   IO_id ( "\nEXEMPLO0711 - Method01 - v0.0" );
    
// ler do teclado    
   IO_println("Multiplos pares de 3, em ordem crescente\n");
    
// ler quantidade do teclado
   quantidade = IO_readint("\nEntre com quantidade inteira = ");

// executar metodo e gravar em arquivo
   multTresPar("DADOS01.TXT", quantidade);
   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );   
}







/**
 Ler um valor inteiro do teclado e gravar essa quantidade em múltiplos de 3, 
 ímpares, em ordem decrescente encerrando em 10.
*/

void multTresImpar(chars fileName, int n)
{
    FILE *file = fopen(fileName, "wt");
    int x = 0;
    n = n + 2;

    while (n > 0)
    {
        x = 3 * (2 * n - 1);
        fprintf(file, "%d\n", x);
        if ( x <= 15 )
        {
           n = 0;
        }
        n--;
    }

    fclose(file);
}

void Metodo02( )
{

// definir dado
    int quantidade = 0;

// identificar
   IO_id ( "\nEXEMPLO0712 - Method02 - v0.0" );
    
// ler do teclado 
    IO_println("Multiplos impares de 3, em ordem decrescente\n");
    
// ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira = ");

// executar metodo e gravar em arquivo
    multTresImpar("DADOS02.TXT", quantidade);
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );    
}







/**
 Ler um valor inteiro do teclado e gravar essa quantidade em valores da sequência: 1 5 25 125 625 ...
*/

void expCinco(chars fileName, int b, int n)
{
    FILE *file = fopen(fileName, "wt");
    double y = 0.0;

    for (int x = 0; x < n; x++)
    {
        y = pow(5.0, (double) x);
        fprintf(file, "%.0lf\n", y);
    }

    fclose(file);
}

void Metodo03( )
{

// definir dado
    int base       = 5;
    int quantidade = 0;

// identificar
   IO_id ( "\nEXEMPLO0713 - Method03 - v0.0" );
    
// ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira = ");

// executar metodo e gravar em arquivo
    expCinco("DADOS03.TXT", base, quantidade);
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );     
}









/**
 Ler um valor inteiro do teclado e gravar essa quantidade em valores decrescentes da sequência: ... 1/64 1/16 1/4 1
*/

void decExpQuatro(chars fileName, int b, int n)
{
    FILE *file = fopen(fileName, "wt");
    double y = 0.0;
    n = n * (-1);

    while (n < 0)
    {
        n++;
        y = pow((double) b, (double) n);
        fprintf(file, "%.12lf\n", y);
    }

    fclose(file);
}

void Metodo04( )
{

// definir dado
    int base       = 4;
    int quantidade = 0;

// identificar
   IO_id ( "\nEXEMPLO0714 - Method04 - v0.0" );
    
// ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade inteira = ");

// executar metodo e gravar em arquivo
    decExpQuatro("DADOS04.TXT", base, quantidade);
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );     
}






/**
 Ler um valor inteiro do teclado (n) e outro valor real (x),
 gravar essa quantidade (n) em valores reais da sequência: 1 1/x 1/x2 1/x4 ...
*/

void decimalExponencial(chars fileName, double b, int n)
{
    FILE *file = fopen(fileName, "wt");
    double y = 0.0;
    n = n * (-1);

    for (int i = 0; i > -2; i--)
    {
        y = pow((double) b, (double) i);
        fprintf(file, "%.12lf\n", y);
    }

    for (int i = -2; i > n; i--)
    {
        y = pow((double) b, (double) i);
        fprintf(file, "%.12lf\n", y);        
    }

    fclose(file);
}

void Metodo05( )
{

// definir dado
    double base    = 0.0;
    int quantidade = 0;

// identificar
   IO_id ( "\nEXEMPLO0715 - Method05 - v0.0" );
    
// ler quantidade do teclado
    quantidade = IO_readint("\nEntre com quantidade = ");
    base = IO_readdouble("\nEntre com valor real = ");

// executar metodo e gravar em arquivo
    decimalExponencial("DADOS05.TXT", base, quantidade);
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );     
}









/**
  Ler um valor inteiro do teclado para representar certa quantidade de valores
  a serem somados dentre os primeiros gravados no exercício anterior.
*/

double somaFile(chars fileName, int n)
{
    FILE *file = fopen(fileName, "rt");
    int contar = 0;
    double x = 0.0;
    double soma2 = 0.0;

    while (! feof(file) && contar < n)
    {
        fscanf(file, "%lf", &x);
        soma2 += x;
        contar++;
    }

    return (soma2);
}

void Metodo06( )
{
    FILE *saida = fopen("RESULTADO06.TXT", "wt");
    
// definir dado
    double soma    = 0.0;
    int quantidade = 0;    

// identificar
    IO_id ( "\nEXEMPLO0716 - Method06 - v0.0" );
    
// mostrar na tela   
    IO_println("Soma dos valores gravados no Metodo_05\n");

// mostrar cabecalho 
    fprintf(saida, "\nQuantidade\t---> \tSoma\n");

    do // repeticao
    {
        // ler quantidade do teclado
        quantidade = IO_readint("\nEntre com quantidade = ");
        IO_println("Apertar 0 para finalizar");        

        // executar metodo e gravar em arquivo
        if (quantidade > 0)
        {
            soma = somaFile("DADOS05.TXT", quantidade);
            fprintf(saida, "\t%d\t\t%.12lf\n", quantidade, soma);
        }
    }
    while (quantidade != 0);

    // fechar arquivo para gravacao
    fclose(saida);
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );     
}






/*
 Ler um valor inteiro do teclado e calcular a soma dessa quantidade 
 dentre os inversos das potências do exercício 04 acima.
*/


void Metodo07( )
{
    FILE *saida = fopen("RESULTADO07.TXT", "wt");
    
// definir dado
    double soma    = 0.0;
    int quantidade = 0;    

// identificar
    IO_id ( "\nEXEMPLO0717 - Method075 - v0.0" );
    
// mostrar na tela   
    IO_println("Soma dos valores gravados no Metodo_04\n");    

// mostrar cabecalho 
    fprintf(saida, "\nQuantidade\t---> \tSoma\n");

    do // repeticao
    {
        // ler quantidade do teclado
        quantidade = IO_readint("\nEntre com quantidade inteira >> ");
        IO_println("Apertar 0 para finalizar");

        // executar metodo e gravar em arquivo
        if (quantidade > 0)
        {
            soma = somaFile("DADOS04.TXT", quantidade);
            fprintf(saida, "\t%d\t\t%.12lf\n", quantidade, soma);
        }
    }
    while (quantidade != 0);

    // fechar arquivo para gravacao
    fclose(saida);
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}









/**
 Ler um valor inteiro do teclado e gravar o valor correspondente 
 aos primeiros termos ímpares da série de Fibonacci
*/

int fibonacci(int n)
{
    int x = 0;
    if (n == 1 || n == 2)
    {
        x = 1;
    }
    else
    {
        if (n > 1)
        {
            x = fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    return (x);
}

void Metodo08 ( )
{
    FILE *saida = fopen("RESULTADO08.TXT", "wt");
    
// definir dado
    int quantidade = 0;    

// identificar
    IO_id ( "\nEXEMPLO0718 - Method08 - v0.0" );

// mostrar cabecalho 
    fprintf(saida, "\nQuantidade\t---> \tSoma\n");

    do // repeticao
    {
        // ler quantidade do teclado
        quantidade = IO_readint("\nEntre com quantidade inteira = ");
        IO_println("Apertar 0 para finalizar");

        // executar metodo para gravar em arquivo
        if (quantidade > 0)
        {
            // definir dado
            int x = 0;
            int z = 1;
            
            fprintf(saida, "%3d\t", quantidade);

            for(int i = 1; i <= quantidade; i++)
            {
                if (z % 3 == 0)
                {
                    z++;
                }

                x = fibonacci(z);
                fprintf(saida, "%4d ", x);
                z++;
            }
            fprintf(saida, "\n");
        }
    }
    while (quantidade != 0);

    // fechar arquivo para gravacao
    fclose(saida);
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );    
}










/**
 Calcular a quantidade de maiúsculas em cadeia de caracteres de um arquivo texto.
*/

bool Maiuscula(char x)
{
    return ('A' <= x && x <= 'Z');
}

int contaMaiuscula(chars string)
{
    // definir dados
    int  conta    = 0;
    int  pertence = strlen(string);
    char caracter = '\0';

    //repeticao
    for (int i = 0; i < pertence; i++)
    {
        caracter = string[i];
        if (Maiuscula(caracter))
        {
            conta++;
        }
    }
    return (conta);
}

void calMaiuscula(chars fileIn, chars fileOut)
{
    FILE *input  = fopen(fileIn, "rt");
    FILE *output = fopen(fileOut, "wt");
    chars string = IO_new_chars(STR_SIZE);
    int   contar = 0;

    strcpy(string, IO_fread(input));
    IO_fprintf(output, "Caracteres ---> Quantidade de caracteres maiusculas\n");

    while (! feof(input))
    {
        contar = contaMaiuscula(string);
        IO_fprintf(output, "\"%s\" ---> %d letra(s) maiuscula(s).\n", string, contar);
        strcpy(string, IO_fread(input));
    }
    fclose(output);
    fclose(input);    
}

void Metodo09( )
{
    FILE *dados = fopen("DADOS09.TXT", "wt");
    
// definir dado
    chars palavra = IO_new_chars(STR_SIZE);    

// identificar
    IO_id ( "\nEXEMPLO0719 - Method09 - v0.0" );

    do // repeticao
    {
        // ler quantidade do teclado
        IO_printf ( "\nEntre com cadeia de caracteres (Apertar '0' para finalizar) =  " );
        fgets  ( palavra, STR_SIZE, stdin );  // ler uma linha
        palavra [ strlen (palavra)-1 ] = EOS; // reposicionar o fim de linha        

        // executar metodo e gravar em arquivo
        if (strcmp(palavra, "0") != 0)
        {
            fprintf(dados, "%s\n", palavra);
        }
    }
    while (strcmp(palavra, "0") != 0);

    // fechar arquivo de dadoss
    fclose(dados);

    calMaiuscula("DADOS09.TXT", "RESULTADO09.TXT");
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );      
}









/**
 Contar dígitos menores ou iguais a 5 em uma cadeia de caracteres.
*/

bool Digito(char x)
{
    return ('0' <= x && x <= '9');
}

int contarDigitos(chars string)
{
    int  contar    = 0;
    int  pertence  = strlen(string);
    int  digito    = 0;
    char caracter  = '\0';

    for (int i = 0; i < pertence; i++)
    {
        caracter = string[i];
        if (Digito(caracter))
        {
            digito  = (int) caracter - 48;
            
            if (digito <= 5)
            {
                contar++;
            }
        }
    }
    return (contar);
}

void lerDigitos(chars fileIn, chars fileOut)
{
    FILE *input  = fopen(fileIn, "rt");
    FILE *output = fopen(fileOut, "wt");
    chars string = IO_new_chars(STR_SIZE);
    int   contar = 0;

    strcpy(string, IO_fread(input));
    IO_fprintf(output, "Caracteres ---> Quantidade de digitos <= 5\n");

    while (! feof(input))
    {
        contar = contarDigitos(string);
        IO_fprintf(output, "\"%s\" ---> %d digitos <= 5.\n", string, contar);        
        strcpy(string, IO_fread(input));
    }
    fclose(output);
    fclose(input);    
}

void Metodo10 ( )
{
    FILE *dados = fopen("DADOS10.TXT", "wt");

// definir dado
    chars palavra = IO_new_chars(STR_SIZE);    

// identificar
    IO_id ( "\nEXEMPLO0719 - Method09 - v0.0" );

    do // executar para varias cadeias de caractere
    {
        // ler quantidade do teclado
        IO_printf ( "\nEntre com cadeia de caracteres (Apertar '0' para finalizar) =  " );
        fgets  ( palavra, STR_SIZE, stdin );  // ler uma linha
        palavra [ strlen (palavra)-1 ] = EOS; // reposicionar o fim de linha         

        // executar metodo e gravar em arquivo
        if (strcmp(palavra, "0") != 0)
        {
            fprintf(dados, "%s\n", palavra);
        }
    }
    while (strcmp(palavra, "0") != 0);

    // fechar arquivo de dadoss
    fclose(dados);

    lerDigitos("DADOS10.TXT", "RESULTADO10.TXT");
 
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );     
} 













int main ( )
{
    int x = 0;

    do
    {
      IO_id ( "EXEMPLO07 - Programa - v0.0" );
    
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