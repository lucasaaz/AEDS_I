/*
Exemplo09 - v0.0. - 29 / 05 / 2021
Author: Lucas Augusto
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void Parar( ){ }

/**
 Ler o tamanho de um arranjo para inteiros do teclado,
 bem como todos os seus elementos, garantindo que só tenha valores positivos e pares.
*/

bool sePositivo(int x)
{
    return (x > 0);
}

bool sePar(int x)
{
    return (x % 2 == 0);
}


void lerArray (int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    chars text = IO_new_chars (STR_SIZE);

    // ler e guardar valores em arranjo
    for (x = 0; x < n; x++)
    {
        // ler valor
        strcpy (text, STR_EMPTY);
        y = IO_readint(IO_concat (
        IO_concat(text, IO_toString_d(x)),": "));
        
        // guardar valor
        array[x] = y;
    }
}

bool arrayParPositivo(int n, int array[])
{
    bool resultado = true;
    int x = 0;
    int valor = 0;

    while (x < n && resultado)
    {
        valor = array[x];
        resultado = resultado && (sePositivo(valor) && sePar(valor));
        x++;
    }

    return (resultado);
}

void Metodo01( )
{
  
    // definir dados
    int n = 0;
    
    // identificar
    IO_id ( "\nEXEMPLO0811 - Method01 - v0.0" );

    // ler dados
    while (n <= 0) // arranjo positivo
    {
        n = IO_readint(" Entre com o tamanho do arranjo = ");
    }

    // definir armazenador
    int array[n];

    // ler do arranjo
    lerArray(n, array);

    // se positivos e pares
    if (arrayParPositivo(n, array))
    {
        IO_printf("\n Todos os valores do arranjo sao positivos e pares\n");
    }
    else
    {
        IO_printf("\n Pelo menos um valor do arranjo nao e' positivo ou par\n");
    }   
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );   
}







/**
 Ler um arranjo com inteiros positivos de arquivo.
 Valores negativos e também os ímpares deverão ser descartados.
 O arranjo e o nome do arquivo serão dados como parâmetros.
 Guardar primeiro o tamanho, depois os elementos, um dado por linha.
*/

void posiFileArray (chars fileName, int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    FILE *file = fopen(fileName, "rt");

    if (n <= 0)
    {
        IO_printf("\n ERRO: arranjo de tamanho invalido");
    }
    else
    {
        while (! feof(file) && x < n)
        {
            IO_fscanf(file, "%d", &y);
            array[x] = y;
            x++;
        }
    }
}

int tamanhoArray(chars fileName)
{
    int x = 0;
    int n = 0;
    FILE *file = fopen(fileName, "rt");

    IO_fscanf(file, "%d", &x);

    if (x <= 0)
    {
        n = 0;
    }
    else
    {
        while (! feof(file))
        {
            fscanf(file, "%d", &x);
            n++;
        }
    }

    return(n);
}

void posiArray(chars fileName, int n, int array[])
{
    // definir dados locais
    FILE *file = fopen(fileName, "wt");
    int x = 0;
    int valor = 0;

    // gravar quantidade de dados
    IO_fprintf(file, "%d\n", n);

    // gravar valores no arranjo
    for (x = 0; x < n; x++)
    {
        valor = array[x];

        // gravar valor se obedecida as condicoes
        if (sePar(valor) && sePositivo(valor))
        {
            IO_fprintf(file, "%d\n", valor);
        }
    }

    fclose(file);
}

void Metodo02( )
{
   
    // definir dados
    int n = 0;
    chars fileIn = "ARRAY02.TXT";
    chars fileOut = "DADOS02.TXT";
    
    // identificar
    IO_id ( "\nEXEMPLO0812 - Method02 - v0.0" );

    // tamanho do arranjo
    n = tamanhoArray(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // definir armazenador
        int array[n];

        // ler do arquivo
        posiFileArray(fileIn, n, array);

        // guardar em arquivo o tamanho e os elementos validos
        posiArray(fileOut, n, array);
    }
    
    // gravacao
    IO_printf("\n Gravacao feita com sucesso!!\n");
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );    
}







/**
 Função para gerar um valor inteiro aleatoriamente dentro de um intervalo,
 cujos limites de início e de fim serão recebidos como parâmetros .....
*/

int gerarInt(int inicio, int fim)
{
    return (inicio + rand() % (fim - inicio + 1));
}

void xArray(chars fileName, int n, int array[])
{
    // definir dados locais
    FILE *file = fopen(fileName, "wt");
    int x = 0;
    
    // ajuste
    n = n -1;

    // gravar quantidade de dados
    IO_fprintf(file, "%d\n", n);

    // gravar valores no arranjo
    for (x = 0; x < n; x++)
    {
        // gravar valor
        IO_fprintf(file, "%d\n", array[x]);
    }

    fclose(file);
}

void Metodo03( )
{

    // definir dados
    int n = 0;
    int x = 0;
    int inferior = 0;
    int superior = 0;
    
    // identificar
    IO_id ( "\nEXEMPLO0813 - Method03 - v0.0" );

    // ler dados
    while (n <= 0)
    {
        n = IO_readint("\n Entre com a quantidade a ser gerada = ");
    }

    inferior = IO_readint("\n Entre com o limite inferior = ");

    while (superior <= inferior)
    {
        superior = IO_readint("\n Entre com o limite superior = ");
    }

    // definir armazenador
    int array[n];

    // gerar valores e armazenar em arranjo
    for (int i = 0; i < n; i++)
    {
        x = gerarInt(inferior, superior);
        array[i] = x;
    }

    xArray("DADOS.TXT", n, array);

    // gavacao
    IO_printf("\n Gravacao feita com sucesso!!\n");
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );     
}









/**
 Procurar o menor valor em um arranjo.
*/

int menorValorArray(int n, int array[])
{
    int minimo = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] < minimo)
        {
            minimo = array[i];
        }
    }

    return (minimo);
}

void Metodo04( )
{

    // definir dados
    int n = 0;
    int menor = 0;
    chars fileIn = "DADOS.TXT";
    
    // identificar
    IO_id ( "\nEXEMPLO0814 - Method04 - v0.0" );
    
    // mostrar na tela
    IO_println(" Procurar menor valor em arranjo");

    // tamanho do arranjo
    n = tamanhoArray(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // definir armazenador
        int array[n];

        // ler do arquivo
        posiFileArray(fileIn, n, array);

        // encontrar menor valor
        menor = menorValorArray(n, array);

        // mostrar menor valor
        IO_printf("\n Menor valor no arranjo: %d\n", menor);
    }

    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );     
}






/**
 Procurar o maior valor em um arranjo.
*/

int maiorValorArray(int n, int array[])
{
    int maximo = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] > maximo)
        {
            maximo = array[i];
        }
    }

    return (maximo);
}

void Metodo05( )
{
       
    // definir dados
    int n = 0;
    int maior = 0;
    chars fileIn = "DADOS.TXT";
    
    // identificar
    IO_id ( "\nEXEMPLO0815 - Method05 - v0.0" );
    
    // mostrar na tela
    IO_println(" Procurar maior valor em arranjo");

    // verificar tamanho do arranjo
    n = tamanhoArray(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // definir armazenador
        int array[n];

        // ler do arquivo
        posiFileArray(fileIn, n, array);

        // encontrar maior valor
        maior = maiorValorArray(n, array);

        // mostrar maior valor
        IO_printf("\n Maior valor no arranjo: %d\n", maior);
    }

    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );     
}









/**
  Determinar a média valores em um arranjo.
*/

int somarValoresArray(int n, int array[])
{
    int soma = 0;
    
    for (int i = 0; i < n; i++)
    {
        soma = soma + array[i];
    }

    return(soma);
}

double mediaValorArray(int n, int array[])
{
    // evitar divisao por 0
    if (n > 0)
    {
        int sum = somarValoresArray(n, array);
        return ((double) sum / (double) n);
    }
    else
    {
        // retornar 0 se tamanho do arranjo for invalido
        return (0.0);
    }
}

void Metodo06( )
{

    // definir dados
    int n = 0;
    double media = 0.0;
    chars fileIn = "DADOS.TXT";
    
    // identificar
    IO_id ( "\nEXEMPLO0816 - Method06 - v0.0" );
    
    // mostrar na tela
    IO_println(" Calcular media de valores em arranjo");

    // tamanho do arranjo
    n = tamanhoArray(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // definir armazenador
        int array[n];

        // ler do arquivo
        posiFileArray(fileIn, n, array);

        // encontrar valor medio
        media = mediaValorArray(n, array);

        // mostrar valor medio
        IO_printf("\n Valor medio do arranjo: %lf\n", media);
    }
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );     
}






/*
 Receber como parâmetro um arranjo  e dizer se está ordenado, ou não, em ordem crescente.
*/

bool ordenarArray(int n, int array[])
{
    bool resultado = true;
    int x = 1;

    while (x < n && resultado)
    {
        resultado = resultado && (array[x] > array[x - 1]);
        x++;
    }

    return (resultado);
}

void Metodo07( )
{

    // definir dados
    int n = 0;
    
    // identificar
    IO_id ( "\nEXEMPLO0817 - Method07 - v0.0" );
    
    // mostrar na tela
    IO_println(" Verificar se arranjo esta' em ordem crescente\n");

    // ler dados
    while (n <= 0) // tamanho do arranjo deve ser positivo
    {
        n = IO_readint(" Entre com o tamanho do arranjo = ");
    }

    // definir armazenador
    int array[n];

    // ler elementos do arranjo
    lerArray(n, array);

    // verificar se o arranjo esta' em ordem crescente
    if (ordenarArray(n, array))
    {
        IO_printf("\n O arranjo esta' em ordem crescente\n");
    }
    else
    {
        IO_printf("\n O arranjo esta' desordenado\n");
    }    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}









/**
 Procurar por determinado valor em arranjo e  dizer se esse valor pode ser nele encontrado,
 indicada a posição inicial para se começar a procura ....
*/

bool procuraPosiArray(int valor, int posi, int n, int array[])
{
    bool resultado = false;
    int x = posi;

    while (x < n && ! resultado)
    {
        resultado = (valor == array[x]);
        x++;
    }

    return (resultado);
}

void Metodo08 ( )
{

    // definir dados
    int n = 0;
    int procurado = 0;
    int posicao = 5;
    chars fileIn = "DADOS.TXT";
    
    // identificar
    IO_id ( "\nEXEMPLO0818 - Method08 - v0.0" );

    // mostrar na tela
    IO_println(" Procurar valor em arranjo a partir de posicao inicial\n");

    // tamanho do arranjo
    n = tamanhoArray(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // ler valor a ser procurado
        procurado = IO_readint(" Entre com o valor inteiro a procurar = ");

        // definir armazenador
        int array[n];

        // ler do arquivo
        posiFileArray(fileIn, n, array);

        // verificar se o valor esta' no arranjo a partir da posicao indicada
        if (procuraPosiArray(procurado, posicao, n, array))
        {
            IO_printf("\n Valor: %d; posicao: %d = encontrado\n", procurado, posicao);
        }
        else
        {
            IO_printf("\n Valor: %d; posicao: %d = nao encontrado\n", procurado, posicao);
        }
    }
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );    
}










/**
 Procurar por determinado valor em arranjo e dizer onde se encontra esse valor,
 indicada a posição inicial para começar a procura .....
*/

int procuraPosiArray2(int valor, int posi, int n, int array[])
{
    bool resultado = false;
    int x = posi;

    while (x < n && ! resultado)
    {
        resultado = (valor == array[x]);
        x++;
    }

    if (resultado)
    {
        return (x - 1);
    }
    else
    {
        return(-1);
    }
}

void Metodo09( )
{

    // definir dados
    int n = 0;
    int procurado = 0;
    int posicao = 5;
    int indice = 0;
    chars fileIn = "DADOS.TXT";
    
    // identificar
    IO_id ( "\nEXEMPLO0819 - Method09 - v0.0" );

    // mostrar na tela
    IO_println(" Procurar indice de valor em arranjo\n");

    // tamanho do arranjo
    n = tamanhoArray(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // ler valor a ser procurado
        procurado = IO_readint(" Entre com o valor inteiro a procurar = ");

        // definir armazenador
        int array[n];

        // ler do arquivo
        posiFileArray(fileIn, n, array);

        // verificar se o valor esta' no arranjo a partir da posicao indicada
        if (procuraPosiArray(procurado, posicao, n, array))
        {
            // procurar o indice
            indice = procuraPosiArray2(procurado, posicao, n, array);
            IO_printf("\n Valor: %d => indice: %d\n", procurado, indice);
        }
        else
        {
            IO_printf("\n Valor %d nao foi encontrado\n", procurado);
        }
    }
    
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );      
}









/**
 Procurar por determinado valor em arranjo e  dizer quantas vezes esse valor pode ser encontrado,
 indicada a posição inicial para começar a procura ...
*/

int procurarQuantidadeArray(int valor, int posi, int n, int array[])
{
    int quant = 0;

    for (int i = posi; i < n; i++)
    {
        if (array[i] == valor)
        {
            quant++;
        }
    }

    return (quant);
}

void Metodo10 ( )
{

    // definir dados
    int n = 0;
    int procurado = 0;
    int posicao = 5;
    int quantidade = 0;
    chars fileIn = "DADOS.TXT";
    
    // identificar
    IO_id ( "\nEXEMPLO0820 - Method10 - v0.0" );

    // mostrar na tela
    IO_println(" Calcular quantidade de valor em arranjo\n");

    // tamanho do arranjo
    n = tamanhoArray(fileIn);

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        // ler valor a ser procurado
        procurado = IO_readint(" Entre com o valor inteiro a procurar = ");

        // definir armazenador
        int array[n];

        // ler do arquivo
        posiFileArray(fileIn, n, array);

        // procurar quantidade do valor no arranjo
        quantidade = procurarQuantidadeArray(procurado, posicao, n, array);
        IO_printf("\n Valor: %d --> Quantidade: %d\n", procurado, quantidade);
    }
 
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