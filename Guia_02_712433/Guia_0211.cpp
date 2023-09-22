/*
Guia0110 - v0.0. - 20 / 03 / 2021
Author:    Lucas Augusto 
Matricula: 712433
*/

// lista de dependencias
#include "karel.hpp"
// --------------------------- definicoes de metodos

/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar marcadores no mundo
   world->set ( 9, 1, BEEPER );
   world->set ( 9, 1, BEEPER );
   world->set ( 9, 1, BEEPER );

   world->set ( 8, 2, BEEPER );
   world->set ( 8, 2, BEEPER );
   
   world->set ( 7, 3, BEEPER );
   
// colocar escadas no mundo (subindo)   
   world->set (  2,  1, VWALL);
   world->set (  3,  2, VWALL);
   world->set (  4,  3, VWALL);

   world->set (  3,  1, HWALL  );
   world->set (  4,  2, HWALL  );
   world->set (  5,  3, HWALL  );
   world->set (  6,  3, HWALL  );   

   
// colocar escadas no mundo (descendo)   
   world->set (  6,  3, VWALL);
   world->set (  7,  2, VWALL);
   world->set (  8,  1, VWALL);
   
   world->set (  7,  2, HWALL  );
   world->set (  8,  1, HWALL  );


// salvar a configuracao atual do mundo
   world->save( fileName );
} // decorateWorld ( )

/**
Classe para definir robo particular (MyRobot),
a partir do modelo generico (Robot)
Nota: Todas as definicoes irao valer para qualquer outro robo
criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
public:
/**
turnRight - Procedimento para virar 'a direita.
*/
   void turnRight ( )
   {
   // definir dado local
      int step = 0;
   // testar se o robo esta' ativo
      if ( checkStatus ( ) )
      {
      // o agente que executar esse metodo
      // devera' virar tres vezes 'a esquerda
         for ( step = 1; step <= 3; step = step + 1 )
         {
            turnLeft( );
         } // end for
      } // end if
   } // end turnRight ( )
   
/**
moveN - Metodo para mover certa quantidade de passos.
@param steps - passos a serem dados.
*/
   void moveN( int steps )
   {
   // definir dado local
      int step = 0;
   // testar se a quantidade de passos e' maior que zero
      for ( step = steps; step > 0; step = step - 1 )
      {
      // dar um passo
         move( );
      } // end if
   } // end moveN( )

/**
* pickBeepers - Metodo para coletar marcadores.
*/
   void pickBeepers( )
   {
   // repetir (com teste no inicio)
   // enquanto houver marcador proximo
      while ( nextToABeeper( ) )
      {
      // coletar um marcador
         pickBeeper ( );
      } // end while
   } // end pickBeepers( )  
   
/**
stepUpRight( ) - um degrau para cima e � direita
*/
   void stepUpRight( )
   {
   // especificar acoes dessa parte da tarefa
      turnLeft( );
      move( );
      turnRight( );
      move( );
   } // end stepUpRight( ) 
   
/**
stepDownRight( ) - um degrau para baixo e � direita
*/
   void stepDownRight( )
   {
   // especificar acoes dessa parte da tarefa
      move( );
      turnRight( );
      move( );
      turnLeft( );
   } // end stepDownRight( )  
   
/**
stepUpLeft( ) - um degrau para cima e � esquerda
*/
   void stepUpLeft( )
   {
   // especificar acoes dessa parte da tarefa
      turnRight( );
      move( );
      turnLeft( );
      move( );
   } // end stepUpRight( ) 
   
/**
stepDownLeft( ) - um degrau para baixo e � esquerda.
*/
   void stepDownLeft( )
   {
   // especificar acoes dessa parte da tarefa
      move( );
      turnLeft( );
      move( );
      turnRight( );
   } // end stepUpRight( )       
   
/**
doPartialTask - Metodo para especificar parte de uma tarefa.
*/
   void doPartialTask( )
   {
   // especificar acoes dessa parte da tarefa
      moveN( 3 );
      turnLeft( );
   } // end doPartialTask( )
   
/**
doTask - Relacao de acoes para o robo executar.
*/
   void doTask( )
   {
   // subir escadas (ida)
      move( );
      stepUpRight( );
      stepUpRight( );
      stepUpRight( );
      move( );
      
   // descer escadas (ida)
      stepDownRight( );
      stepDownRight( );
      stepDownRight( );
      pickBeepers( );    //pegar marcadores
      
   // subir escadas (volta)
      turnLeft( );
      turnLeft( );
      stepUpLeft( );
      pickBeepers( );    //pegar marcadores
      stepUpLeft( );
      pickBeepers( );    //pegar marcador
      stepUpLeft( );
      move( );
      
   // descer escadas (volta)
      stepDownLeft( );
      putBeeper( );
      stepDownLeft( );
      putBeeper( );
      putBeeper( );
      stepDownLeft( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      move( );
        
      turnLeft( );
      turnLeft( );      
           
   // encerrar
      turnOff ( );
   } // end doTask( )
}; // end class MyRobot// --------------------------- acao principal
/**
Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
// definir o contexto
// criar o ambiente e decorar com objetos
// OBS.: executar pelo menos uma vez,
// antes de qualquer outra coisa
// (depois de criado, podera' ser comentado)
   world->create ( "" ); // criar o mundo
   decorateWorld ( "Guia0201.txt" );
   world->show ( );
// preparar o ambiente para uso
   world->reset ( ); // limpar configuracoes
   world->read ( "Guia0201.txt" );// ler configuracao atual para o ambiente
   world->show ( ); // mostrar a configuracao atual
   set_Speed ( 3 ); // definir velocidade padrao
// criar robo
   MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
   robot->create ( 1, 1, EAST, 0, "Karel" );
// executar tarefa
   robot->doTask ( );
// encerrar operacoes no ambiente
   world->close ( );
// encerrar programa
   getchar ( );
   return ( 0 );
} // end main ( )
// -------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
--------------------------------------------- testes
Versao Teste
0.1 01. ( ) identificacao de programa
*/
