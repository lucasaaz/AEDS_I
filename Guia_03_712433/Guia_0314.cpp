/*
Guia0314 - v0.0. - 27 / 03 / 2021
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
// colocar paredes no mundo
   //bloco 1
   world->set ( 1, 3, VWALL );
   world->set ( 1, 4, VWALL );
   world->set ( 1, 5, VWALL );
   world->set ( 1, 6, VWALL );
   world->set ( 1, 7, VWALL );
   world->set ( 1, 8, VWALL );
   world->set ( 2, 4, VWALL );
   world->set ( 2, 5, VWALL );
   world->set ( 2, 6, VWALL );
   world->set ( 2, 7, VWALL );
   world->set ( 3, 5, VWALL );
   world->set ( 3, 6, VWALL );
   world->set ( 4, 5, VWALL );
   world->set ( 4, 7, VWALL );
   world->set ( 5, 5, VWALL );
   world->set ( 5, 7, VWALL );
   world->set ( 6, 6, VWALL );
   world->set ( 6, 5, VWALL );
   world->set ( 7, 3, VWALL );
   world->set ( 7, 4, VWALL );
   world->set ( 7, 5, VWALL );
   world->set ( 7, 6, VWALL );
   world->set ( 7, 7, VWALL );
   
   world->set ( 2, 2, HWALL );
   world->set ( 3, 2, HWALL );
   world->set ( 4, 2, HWALL );
   world->set ( 5, 2, HWALL );
   world->set ( 6, 2, HWALL );
   world->set ( 7, 2, HWALL );
   world->set ( 3, 3, HWALL );
   world->set ( 5, 4, HWALL );
   world->set ( 5, 5, HWALL );
   world->set ( 4, 6, HWALL );
   world->set ( 6, 6, HWALL );
   world->set ( 3, 7, HWALL );
   world->set ( 4, 7, HWALL );
   world->set ( 5, 7, HWALL );
   world->set ( 6, 7, HWALL );
   world->set ( 7, 7, HWALL );
   world->set ( 2, 8, HWALL );
   world->set ( 3, 8, HWALL );
   world->set ( 4, 8, HWALL );
   world->set ( 5, 8, HWALL );
   world->set ( 6, 8, HWALL );
   world->set ( 7, 8, HWALL );
   
// colocar um marcador no mundo
   world->set ( 4, 7, BEEPER );
   world->set ( 4, 7, BEEPER );
   world->set ( 4, 7, BEEPER );
   world->set ( 5, 6, BEEPER );
   world->set ( 5, 6, BEEPER );
   world->set ( 6, 7, BEEPER );


   
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
      int x, y;
      std::ofstream arquivo ( "Coordenadas_Trajeto_0313.txt", std::ios::app );
   // testar se a quantidade de passos e' maior que zero
      for ( step = steps; step > 0; step = step - 1 )
      {
      // dar um passo
         move( );
         x = xAvenue( );
         y = yStreet( );
         arquivo << x << std::ends;
         arquivo << y << std::ends;
      } // end if
      arquivo.close ( );
   } // end moveN( )
 
/**
pickBeepers - Metodo para coletar marcadores.
*/
   void pickBeepers( )
   {
   // definir dado local
      int x, y;
      std::ofstream arquivo ( "Coordenadas_Marcadores_0314.txt", std::ios::app );
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
goFinish - chegar no final
*/
   void goFinish ( )
   {
   // especificar acoes dessa parte da tarefa
      turnLeft ( ); 
      move (  );
      turnLeft ( );
   } // end goFinish
   
/**
goMoreFastL - acelarar trajeto que vira a esquerda
*/
   void goMoreFastL ( )
   {
   // especificar acoes dessa parte da tarefa
      leftIsClears ( );
      turnLefts( );
      leftIsClears ( );
      turnLefts( );
   } // end goMoreFastl
   
/**
goMoreFastR - acelarar trajeto que vira a direita
*/
   void goMoreFastR ( )
   {
   // especificar acoes dessa parte da tarefa
      rightIsClears ( );
      turnLefts ( );
      rightIsClears ( );
      turnLefts ( );
   } // end goMoreFastD  
   
/**
goMoreFastR2 - acelarar trajeto que vira a direita
*/
   void goMoreFastR2 ( )
   {
   // especificar acoes dessa parte da tarefa
      rightIsClears ( );
      turnRights ( );
      rightIsClears ( );
      turnRights ( );
   } // end goMoreFastD2      
   
/**
turnLefts - vira à direita
*/
   void turnLefts ( )
   {
   // especificar acoes dessa parte da tarefa
      turnLeft ( ); 
      move ( );
   } // end turnLefts   

/**
turnRights - vira à direita
*/
   void turnRights ( )
   {
   // especificar acoes dessa parte da tarefa
      turnRight ( ); 
      move ( );
   } // end turnRights 
       
/**
pickBeeper1 - pegar marcador.
*/
   void pickBeeper1 ( )
   {
   // especificar acoes dessa parte da tarefa
      pickBeepers( );
      turnAround( );
      move ( );
      turnRights ( );     
      rightIsClears ( );     
      turnLefts( );
   } // end pickBeeper1 
   
/**
pickBeeper2 - pegar marcador.
*/
   void pickBeeper2 ( )
   {
   // especificar acoes dessa parte da tarefa
      pickBeepers( );
      move ( );
      turnLeft ( );
   } // end pickBeeper2   

/**
pickBeeper3 - pegar marcador.
*/
   void pickBeeper3 ( )
   {
   // especificar acoes dessa parte da tarefa
      pickBeepers( );
      turnAround( );
      move ( );
      turnLefts ( );
      rightIsClears ( );
      turnLefts ( );
      turnRights ( );
      turnRights ( );
      move ( );
      turnRights ( );
      rightIsClears ( );      
      turnRights ( );      
      rightIsClears ( );
   } // end pickBeeper3 

/**
turnAround - Metodo para fazer 180°
*/
   void turnAround( )
   {
   // especificar acoes dessa parte da tarefa
      turnLeft( );
      turnLeft( );
   } // end turnAround   
   
/**
rightIsClears - Funcao para ver se pode vira a direita.
*/
   void rightIsClears ( )
   {
   // definir dado local
      int numb = 0;
   // repetir (com teste no inicio)
      while ( frontIsClear( ) )
      {
         if ( rightIsClear( ) )
         { 
            turnRight ( );         
            move ( );
         } 
         else
         {        
            move ( );
         } 
      } 
   } // rightIsClears 
   
   
/**
* leftIsClears - Funcao para ver se pode vira a esquerda.
*/
   void leftIsClears ( )
   {
   // definir dado local
      int numb = 0;
   // repetir (com teste no inicio)
      while ( frontIsClear( ) )
      {
         if ( leftIsClear( ) )
         { 
            turnLeft ( );         
            move ( );
         } 
         else
         {        
            move ( );
         } 
      }  
   } // leftIsClears  
   
   
/**
doTask - Relacao de acoes para o robo executar.
*/
   void doTask( )
   {
   // ir ate position
      turnLeft ( );
      move ( );
      turnRight ( );
      move ( );
      
      goMoreFastL ( );   // Funcao para ver se pode vira a esquerda (mais rapido)
      
      goMoreFastR ( );   // Funcao para ver se pode vira a direita (mais rapido)
      
      pickBeeper1 ( );   // pegar marcador 1
      
      pickBeeper2 ( );   // pegar marcador 2
      
      goMoreFastR2 ( );  //// Funcao para ver se pode vira a direita 2 (mais rapido)
      
      pickBeeper3 ( );   // pegar marcador 3
      
      goFinish ( );      // chegar no final 
          
   // especificar acoes da tarefa
   
      
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
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
--------------------------------------------- testes
Versao Teste
0.1 01. ( ) identificacao de programa
*/