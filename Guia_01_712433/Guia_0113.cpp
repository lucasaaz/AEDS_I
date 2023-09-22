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
// colocar um marcador no mundo (3,3/3,6/6,6)   
   world->set ( 3, 3, BEEPER );
   world->set ( 6, 3, BEEPER );
   world->set ( 6, 6, BEEPER );
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
doTask - Relacao de acoes para o robo executar.
*/
   void doTask( )
   {
   // chegar ate a posicao (6,6)
      turnLeft( );
      moveN(6);
      turnRight( );
      moveN(6);
      pickBeeper( );
   // chegar ate a posicao (6,3)
      turnRight( );
      moveN(4);
      pickBeeper( ); 
   // chegar ate a posicao (3,3)
      turnRight( );
      moveN(4);
      pickBeeper( );
   // chegar ate a posicao (1,5)
      moveN(3);
      turnRight( );
      moveN(3);
      putBeeper( );   
   // chegar ate a posicao (1,4)
      turnLeft( );
      turnLeft( );
      move( );
      putBeeper( );    
   // chegar ate a posicao (1,3)
      move( );
      putBeeper( ); 
   // voltar ao inicio      
      moveN(3);
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