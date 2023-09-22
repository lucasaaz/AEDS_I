/*
Guia0311 - v0.0. - 26 / 03 / 2021
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
   world->set ( 4, 3, VWALL );
   world->set ( 4, 4, VWALL );
   world->set ( 4, 5, VWALL );
   world->set ( 4, 6, VWALL );
   world->set ( 4, 7, VWALL );
   
   world->set ( 2, 2, HWALL );
   world->set ( 3, 2, HWALL );
   world->set ( 4, 2, HWALL );
   world->set ( 2, 7, HWALL );
   world->set ( 3, 7, HWALL );
   world->set ( 4, 7, HWALL );
   
   //bloco 2
   world->set ( 5, 3, VWALL );
   world->set ( 5, 4, VWALL );
   world->set ( 5, 5, VWALL );
   world->set ( 5, 6, VWALL );
   world->set ( 5, 7, VWALL );
   world->set ( 8, 3, VWALL );
   world->set ( 8, 4, VWALL );
   world->set ( 8, 5, VWALL );
   world->set ( 8, 6, VWALL );
   world->set ( 8, 7, VWALL );
   
   world->set ( 6, 2, HWALL );
   world->set ( 7, 2, HWALL );
   world->set ( 8, 2, HWALL );
   world->set ( 6, 7, HWALL );
   world->set ( 7, 7, HWALL );
   world->set ( 8, 7, HWALL );
   
// colocar um marcador no mundo
   world->set ( 3, 2, BEEPER );
   world->set ( 3, 8, BEEPER );
   world->set ( 1, 5, BEEPER );
   world->set ( 9, 5, BEEPER );
   world->set ( 7, 2, BEEPER );
   world->set ( 7, 8, BEEPER );
   
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
* @return quantidade de marcadores coletados
*/
   int pickBeepers ( )
   {
   // definir dado local
      int numb = 0;
      int n = 0;
   // repetir (com teste no inicio)
   // enquanto houver marcador proximo
      while ( nextToABeeper ( ) )
      { 
      // coletar um marcador
         pickBeeper ( );
         n = n + 1;
      // contar mais um marcador coletado
         numb = numb + 1;
      // Fazer
         if( (numb > 2) && (numb < 4) )
         {
            moveN(3);
            turnRight();
            moveN(2);
            numb = numb + 1;
         } 
      // Fazer
         if( numb < 2)
         {
            moveN(2);
            turnRight();
            moveN(3);
            numb = numb + 1;
         }

      } // end while
   // retornar a quantidade de marcadores coletados
      return ( n );
   } // end pickBeepers( )
/**
* pickBeepers2 - Funcao para coletar marcadores.
* @return quantidade de marcadores coletados
*/
   int pickBeepers2 ( )
   {
   // definir dado local
      int numb = 0;
   // repetir (com teste no inicio)
   // enquanto houver marcador proximo
      while ( nextToABeeper ( ) )
      { 
      // coletar um marcador
         putBeeper ( );
      // contar mais um marcador coletado
         numb = numb + 1; 
      // Fazer
         if((numb > 2) && (numb < 4))
         {
            moveN(3);
            turnLeft();
            moveN(2);
            numb = numb + 1;
         }
      // Fazer
         if( ((numb > 0) && (numb < 2)) OR ((numb > 4) && (numb < 6)) )
         {
            moveN(2);
            turnLeft( );
            moveN(3);
            numb = numb + 1;
         }

      } // end while
   // retornar a quantidade de marcadores coletados
      return ( 0 );
   } // end pickBeepers( )

/**
goPosition - Metodo para ir ate position
*/
   void goPosition( )
   {
   // especificar acoes dessa parte da tarefa
      moveN( 2 );
      turnRight( );
      moveN( 6 );
      turnLeft( );
      moveN( 2 );
   } // end goPosition( )
/**
goPositionF - Metodo para ir ate position Final
*/
   void goPositionF( )
   {
   // especificar acoes dessa parte da tarefa
      moveN( 4 );
      turnRight( );
      moveN( 4 );
      turnLeft( );
      turnLeft( );
   } // end goPosition( )
/**
doTask - Relacao de acoes para o robo executar.
*/
   void doTask( )
   {
   // ir ate position
      moveN(2);
      turnLeft();
      move();
      turnLeft ();   
   // especificar acoes da tarefa
      pickBeepers( );
      goPosition( );
      pickBeepers2( );
      goPositionF( );
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