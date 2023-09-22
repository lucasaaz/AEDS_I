/*
Guia0312 - v0.0. - 27 / 03 / 2021
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
   world->set ( 2, 3, VWALL );
   world->set ( 2, 4, VWALL );
   world->set ( 2, 5, VWALL );
   world->set ( 2, 6, VWALL );
   world->set ( 2, 7, VWALL );
   world->set ( 3, 5, VWALL );
   world->set ( 3, 6, VWALL );
   world->set ( 4, 7, VWALL );
   world->set ( 5, 6, VWALL );
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
   world->set ( 4, 4, HWALL );
   world->set ( 5, 4, HWALL );
   world->set ( 6, 4, HWALL );
   world->set ( 6, 5, HWALL );
   world->set ( 4, 6, HWALL );
   world->set ( 5, 6, HWALL );
   world->set ( 3, 7, HWALL );
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
   world->set ( 5, 6, BEEPER );
   world->set ( 5, 6, BEEPER );
   world->set ( 5, 7, BEEPER );
   world->set ( 2, 3, BEEPER );
   world->set ( 2, 3, BEEPER );
   world->set ( 2, 3, BEEPER );
   
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
* pickBeepers - Funcao para coletar marcadores.
*/
   int pickBeepers ( )
   {
   // definir dado local
      int numb = 0;
   // repetir (com teste no inicio)
   // enquanto houver marcador proximo
      while ( (numb < 1) OR ( (numb > 1) && (numb < 3) ) )
      { 
         turnLeft();
         moveN(2);
      // contar mais um marcador coletado
         numb = numb + 1; 
      // Fazer se numb=1
         if((numb > 0) && (numb < 2))
         {
            turnLeft();
            moveN(4);
            numb = numb + 1;
         }
      } // end while
   // retornar a quantidade de marcadores coletados
      return ( 0 );
   } // end pickBeepers( )
/**
* pickBeepers2 - Funcao para coletar marcadores.
*/
   int pickBeepers2 ( )
   {
   // definir dado local
      int numb = 0;
   // repetir (com teste no inicio)
   // enquanto houver marcador proximo
      while ( numb < 3 )
      { 
      // Fazer
         if( numb < 1 )
         {
            move( );
            turnRight();
            move( );
            numb = numb + 1;
         }
      // coletar um marcador
         pickBeeper ( );
         pickBeeper ( );
      // contar mais um marcador coletado
         numb = numb + 1; 
      // Fazer
         if( numb > 0 )
         {
            turnAround( );
            move( );
            turnLeft( );
            move( );
            numb = numb + 1;
         }

      } // end while
   // retornar a quantidade de marcadores coletados
      return ( 0 );
   } // end pickBeepers2( )
/**
* pickBeepers3 - Funcao para coletar marcadores.
*/
   int pickBeepers3 ( )
   {
   // definir dado local
      int numb = 0;
   // repetir (com teste no inicio)
   // enquanto houver marcador proximo
      while ( numb < 3 )
      { 
      // Fazer
         if( numb < 1 )
         {
            move( );
            turnLeft();
            moveN( 5 );
            numb = numb + 1;
         }
      // coletar um marcador
         pickBeeper ( );
         pickBeeper ( );
         pickBeeper ( );
      // contar mais um marcador coletado
         numb = numb + 1; 
      // Fazer
         if( numb > 0 )
         {
            turnAround( );
            moveN( 5 );
            numb = numb + 1;
         }
      } // end while
   // retornar a quantidade de marcadores coletados
      return ( 0 );
   } // end pickBeepers3( )
/**
* goFinish - Funcao para coletar marcadores.
*/
   int goFinish ( )
   {
   // definir dado local
      int numb = 0;
   // repetir (com teste no inicio)
   // enquanto houver marcador proximo
      while ( numb < 3 )
      { 
      // Fazer
         turnRight();
         moveN( 6 );
      // contar mais um marcador coletado
         numb = numb + 1; 
      } // end while
   // retornar a quantidade de marcadores coletados
      return ( 0 );
   } // end goFinish ( )
/**
* goBeepers - Funcao para coletar marcadores.
*/
   int goBeepers ( )
   {
   // definir dado local
      int numb = 0;
   // repetir (com teste no inicio)
   // enquanto houver marcador proximo
      while ( numb < 2 )
      { 
      // Fazer
         moveN( 3 );
         turnRight();
      // contar mais um marcador coletado
         numb = numb + 1; 
      } // end while
   // retornar a quantidade de marcadores coletados
      return ( 0 );
   } // end goBeepers 

/**
goPosition - Metodo para ir ate position
*/
   void goPosition( )
   {
   // especificar acoes dessa parte da tarefa
      turnLeft( );
      moveN( 8 );
      turnRight( );
      moveN( 6 );
   } // end goPosition( )
/**
turnAround( ) - Metodo para fazer 180°
*/
   void turnAround( )
   {
   // especificar acoes dessa parte da tarefa
      turnLeft( );
      turnLeft( );
   } // end turnAround
/**
turnAroundCornerLeft( )  - Metodo para contorna a esquerda
*/
   void turnAroundCornerLeft( ) 
   {
   // especificar acoes dessa parte da tarefa
      move( );
      turnLeft( );
      move( );
      turnLeft( );
      move( );
   } // end turnAroundCornerLeft
/**
turnAroundCornerRight( )  - Metodo para contorna a direita
*/
   void turnAroundCornerRight( ) 
   {
   // especificar acoes dessa parte da tarefa
      move( );
      turnRight( );
      move( );
      turnRight( );
      move( );
   } // end turnAroundCornerRight
/**
stepDownLeft( ) - um degrau para baixo e à esquerda.
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
stepUpLeft( ) - um degrau para cima e à esquerda
*/
   void stepUpLeft( )
   {
   // especificar acoes dessa parte da tarefa
      turnLeft( );
      move( );
      turnRight( );
      move( );
      turnLeft( );
      move( );
   } // end stepUpRight( ) 
/**
stepDownRight( ) - um degrau para baixo e à direita
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
doTask - Relacao de acoes para o robo executar.
*/
   void doTask( )
   {
   // ir ate position
      goPosition( );
      
   // especificar acoes da tarefa
      turnAroundCornerRight( );  // fazer curva fechada à direita
      moveN(2);
      stepDownLeft( );           // um degrau para baixo e à esquerda.
      stepDownLeft( );           // um degrau para baixo e à esquerda.
      pickBeepers ( );
      stepUpLeft( );             // um degrau para cima e à esquerda
      pickBeeper ( );
      turnAround( );             // 180°
      stepDownRight( );
      turnAroundCornerRight( );  // fazer curva fechada à direita
      pickBeepers2 ( );
      turnAroundCornerRight( );  // fazer curva fechada à direita
      goBeepers ( );
      turnAroundCornerLeft( );   // fazer curva fechada à esquerda
      pickBeepers3 ( );
      goFinish ( );
      stepDownLeft( );           // um degrau para baixo e à esquerda.
      turnAround( );             // 180°
      
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