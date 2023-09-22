/*
Guia0110 - v0.0. - 12 / 03 / 2021
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
// colocar um marcador no mundo (5,3)   
   world->set ( 5, 3, BEEPER );
   world->set ( 5, 3, BEEPER );
   world->set ( 5, 3, BEEPER );
   world->set ( 5, 3, BEEPER );
   world->set ( 5, 3, BEEPER );
   world->set ( 5, 3, BEEPER );
// colocar paredes no mundo    
   world->set (  2,  3, VWALL  );
   world->set (  2,  4, VWALL  );
   world->set (  2,  5, VWALL  );
   world->set (  2,  6, VWALL  );
   
   world->set (  5,  3, VWALL  );
   world->set (  5,  4, VWALL  );
   world->set (  5,  5, VWALL  );
   
   world->set (  3,  6, HWALL  );
   world->set (  4,  6, HWALL  );
   world->set (  5,  6, HWALL  );
   
   world->set (  3,  2, HWALL  );
   world->set (  4,  2, HWALL  );
   world->set (  5,  2, HWALL  );
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
   // testar se o robo esta' ativo
      if ( checkStatus ( ) )
      {
      // o agente que executar esse metodo
      // devera' virar tres vezes 'a esquerda
         turnLeft ( );
         turnLeft ( );
         turnLeft ( );
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
      for ( step = 1; step < steps; step = step + 1 ) // outra alternativa
      {
      // dar um passo
         move( );
      } // end if
   } // end moveN( )
   
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
ContornoRight - Metodo para da um contorno a direita
*/
   void ContornoRight( )
   {
   // especificar acoes dessa parte da tarefa
   move( );
   turnRight( );
   move( );
   turnRight( );
   move( );
   } // end ContornoRight( )  
   
/**
doTask - Relacao de acoes para o robo executar.
*/
   void doTask( )
   {
   // chegar ate a posicao X (5,3)
      turnLeft( );
      moveN(7);
      turnRight( );
      moveN(5);
      ContornoRight( );
      turnLeft( );
      moveN(4);
      pickBeeper( );
      pickBeeper( );
      pickBeeper( );
      pickBeeper( );
      pickBeeper( );
      pickBeeper( );
   // chegar ate a posicao (5,2)
      turnLeft( );
      turnLeft( );     
      moveN(3);
      ContornoRight( ); 
      moveN(4);
      turnRight( );
      move( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
   // chegar ate a posicao (2,6)
      moveN(4);
      turnRight( );
      moveN(5);
      putBeeper( );
      putBeeper( );
   // levar ate a posicao (5,7)
      move( );
      turnRight( );
      moveN(4);
      putBeeper( );  
   // voltar ao inicio 
      turnLeft( );
      turnLeft( );     
      moveN(5);
      turnLeft( );
      moveN(7);
      turnLeft( );
   // encerrar
      turnOff ( );            
   } // end doTask( )
}; // end class MyRobot

// --------------------------- acao principal
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
   decorateWorld ( "Guia0110.txt" );
   world->show ( );
// preparar o ambiente para uso
   world->reset ( ); // limpar configuracoes
   world->read ( "Guia0110.txt" );// ler configuracao atual para o ambiente
   world->show ( ); // mostrar a configuracao atual
   set_Speed ( 3 ); // definir velocidade padrao
// criar robo
   MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
   robot->create ( 1, 1, EAST, 0, "Karel" );// executar tarefa
   robot->doTask ( );
// encerrar operacoes no ambiente
   world->close ( );
// encerrar programa
   getchar ( );
   return ( 0 );
} // end main ( )