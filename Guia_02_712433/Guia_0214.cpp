/*
Guia0110 - v0.0. - 20 / 03 / 2021
Author:    Lucas Augusto 
Matricula: 712433
*/

// lista de dependencias
#include "karel.hpp"
#include "io.hpp"
// --------------------------- definicoes de metodos

/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar marcadores no mundo
   world->set ( 3, 3, BEEPER );
   world->set ( 3, 3, BEEPER );
   world->set ( 3, 3, BEEPER );
   world->set ( 4, 3, BEEPER );
   world->set ( 4, 3, BEEPER );
   world->set ( 4, 3, BEEPER );
   world->set ( 4, 4, BEEPER );
   world->set ( 4, 4, BEEPER );
   world->set ( 5, 3, BEEPER );
   world->set ( 5, 3, BEEPER );
   world->set ( 5, 3, BEEPER );
   world->set ( 5, 4, BEEPER );
   world->set ( 5, 4, BEEPER );
   world->set ( 5, 5, BEEPER );
   
// colocar paredes no mundo (verical)   
   world->set (  2,  3, VWALL);
   world->set (  2,  4, VWALL);
   world->set (  2,  5, VWALL);
   world->set (  2,  6, VWALL);
   world->set (  2,  7, VWALL);
   world->set (  2,  8, VWALL); 
   

   world->set (  3,  3, VWALL);
   world->set (  3,  4, VWALL);
   world->set (  3,  5, VWALL);
   world->set (  3,  6, VWALL);
   world->set (  3,  7, VWALL);
   
   world->set (  4,  3, VWALL);
   world->set (  4,  4, VWALL);
   world->set (  4,  5, VWALL);
   world->set (  4,  6, VWALL); 
   world->set (  4,  7, VWALL);  
   
   world->set (  5,  3, VWALL);
   world->set (  5,  4, VWALL);
   world->set (  5,  5, VWALL);
   world->set (  5,  6, VWALL);
   world->set (  5,  7, VWALL);
   world->set (  5,  8, VWALL);
  
// colocar escadas no mundo (descendo)   
   world->set (  3,  2, HWALL);
   world->set (  4,  2, HWALL);
   world->set (  5,  2, HWALL);
   
   world->set (  3,  8, HWALL);
   world->set (  5,  8, HWALL);   
   
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
pickBeepers - Metodo para coletar marcadores.
*/
   void pickBeepers( )
   {
   // definir dado local
      int x, y;
      std::ofstream arquivo ( "Coordenadas_0202.txt", std::ios::app );
   // enquanto houver marcador proximo
      while ( nextToABeeper( ) )
      {
      // coletar um marcador
         pickBeeper ( );
         x = xAvenue( );
         y = yStreet( );
         arquivo << x << std::ends;
         arquivo << y << std::ends;
      } // end while
      arquivo.close ( );
   } // end pickBeepers( )  
   
/**
turnAround( ) - virar-se
*/
   void turnAround( )
   {
   // especificar acoes dessa parte da tarefa
      turnLeft( );
      turnLeft( );
   }     
   
/**
goBeeper3( ) - ir pegar beeper e sair
*/
   void goBeeper3( )
   {
   // especificar acoes dessa parte da tarefa
      moveN( 3 );
      pickBeepers( );
      turnLeft( );
      turnLeft( );
      moveN( 3 );
   }  
   
/**
goBeeper4( ) - ir pegar beeper e sair
*/
   void goBeeper4( )
   {
   // especificar acoes dessa parte da tarefa
      moveN( 4 );
      pickBeepers( );
      turnLeft( );
      turnLeft( );
      moveN( 4 );
   }   
   
/**
goBeeper5( ) - ir pegar beeper e sair
*/
   void goBeeper5( )
   {
   // especificar acoes dessa parte da tarefa
      moveN( 5 );
      pickBeepers( );
      turnLeft( );
      turnLeft( );
      moveN( 5 );
   }    
   
/**
goPosition( ) - ir ate a posicao
*/
   void goPosition( )
   {
   // especificar acoes dessa parte da tarefa
      turnRight( );
      move( );
      turnLeft( );
      move( );
      turnRight( );
   }
   
/**
goPosition2( ) - ir ate a posicao
*/
   void goPosition2( )
   {
   // especificar acoes dessa parte da tarefa
      turnLeft( );
      move( );
      turnLeft( );
   }    
   
/**
goPositionX( ) - ir ate a posicao X
*/
   void goPositionX( )
   {
   // especificar acoes dessa parte da tarefa
      turnRight( );
      move( );
      turnLeft( );
      move( );
      turnRight( );
      moveN( 3 );
      turnRight( );
      moveN( 8 );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
      putBeeper( );
  
   }       
   
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
   // ir ate posicao inicial
      move( );
      turnLeft( );
      moveN( 8 );
      turnRight( );
      moveN( 2 );
      
      goPosition( );  // se posicionar indo para direita
      
      goBeeper3( );   // ir pegar beeper e sair (distacia=3)
       
      turnAround( );  // virar-se
      
      goBeeper4( );   // ir pegar beeper e sair (distacia=4)
      
      goPosition2( ); // se posicionar indo para esquerda
      
      goBeeper4( );   // ir pegar beeper e sair (distacia=4)
      
      turnRight( );   // voltar para posicao da direita
      move();
      turnRight( );
      
      goBeeper5( );   // ir pegar beeper e sair (distacia=5)
      
      goPosition2( ); // se posicionar indo para esquerda
      
      goBeeper5( );   // ir pegar beeper e sair (distacia=5)
      
      goPosition2( ); // se posicionar indo para esquerda
      
      goBeeper5( );   // ir pegar beeper e sair (distacia=5)
      
      goPositionX( ); // ir ate a posicao X
 
      
      turnRight( );   // ir ate a posicao inicial
      moveN( 6 );
      
      turnAround( );  // virar-se
   
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
   set_Speed ( 1 ); // definir velocidade padrao
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
      DUVIDA:
      tive duvida na hora de passar as coordenadas para o arquivo,
      deixar as coordenadas separadas, para ficar mais organizado.
*/
