#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> 
#include <sys/time.h>
#include "StdPijo.h"
#include "Juego.h"
 
using namespace STDP;         

 

 


int main(int argc, char const* argv[])
{
	Juego juego1; //Para controlar si ha acabado y mover al jugador
	Juego juego2; //Para controlar si ha acabado y mover al jugador
	Tablero tablero; // Para pintar el tablero según lo que haya en las casillas
	Coor casillas; // Indica lo que hay en cada casilla
  StdPijo& pijo = StdPijo::p();	
	int tecla;      
	int tmpX,tmpY;  
	bool pintarMinas=false;
	  	
	timespec tiempo1= { 2, 0 };        
	timespec tiempo2;
	                    
  //Ajustes para saber que se trata del jugador2   
	juego2.tablero.inicioX		= 25;
	juego2.jugador.numJugador =  2;       
	juego1.jugador.numJugador =  1;     
      
  pijo.init();
  pijo.setGlobalEscapeDelay(0);
  pijo.setColor(ABOLD, CBLUE, CBLACK);    
	pijo.clearScreen();                     
	
	
	//MENU PRINCIPAL
  while(tecla!=27 ){                                   
		tecla = pijo.getKey();
	 	juego1.procesarEntrada(tecla,pijo);		//Actualizar posicion jugador en las casillas
		juego1.tablero.pintarTitulo(juego1.jugador.modoJuego,pijo);
		pijo.refreshScr();   
		if(tecla==32 || tecla==13 ){            
			pijo.clearScreen();        
			juego1.iniciado=true;	juego1.jugador.vidas=3;     
			if(juego1.jugador.modoJuego==2)  juego2.iniciado=true;	juego2.jugador.vidas=3;     
			//Entramos en el juego			
				while (juego1.iniciado)
				{         					
					tecla = pijo.getKey();    
					if(tecla==104) pintarMinas= !pintarMinas;                                            
					//Si se pulsa scape, o las vidas llegan a 0 o se agota el tiempo , se acaba el juego
					if(tecla==27 ){ //salimos del juego
						juego1.gameOver();
						juego2.gameOver();
						pijo.clearScreen();                     
						tecla=0;						
					} 
					else
					{
						juego1.procesarEntrada(tecla,pijo);// Actualizar posicion jugador en las casillas		 
						if(juego1.jugador.posy==0 || juego2.jugador.posy==0){ //si pasamos de nivel en lugar de pintar el tablero pintamos los puntos						                       
 			 				 if(juego1.jugador.posy==0 ) {                                        
 									juego1.siguienteNivel();									          									       									 										  
									juego1.tablero.pintarSiguienteNivel(juego1.tiempoInvertido,pijo);		 							    
							  }
															
								if(juego2.jugador.posy==0 ) {                                       
								  juego2.siguienteNivel(); 
									juego2.tablero.pintarSiguienteNivel(juego2.tiempoInvertido,pijo);		 							    
							  }
 			 				 
						}else if( juego1.jugador.vidas==0 ){
							juego1.tablero.pintarGameOver(pijo);
						}else{
							juego1.tablero.pintar(juego1.casillas,pijo,pintarMinas,false);
							if(juego1.jugador.modoJuego==2)		juego2.procesarEntrada(tecla,pijo); // Actualizar posicion jugador en las casillas
							if(juego1.jugador.modoJuego==2)		juego2.tablero.pintar(juego2.casillas,pijo,pintarMinas,false); //Juego 2 pinta tablero    				              		
           }
							//Imprimir marcador 
							juego1.tablero.pintarMarcador(juego1.puntos, juego1.jugador.vidas, juego1.numMinasCerca,juego1.nivel,
																						juego2.puntos, juego2.jugador.vidas, juego2.numMinasCerca,juego2.nivel,pijo);
							usleep(1000);
		        					
						pijo.refreshScr();            
					} // Si no has pulsado escape , sigues jugando
				} //While juego se mantiene iniciado		 				 
		 }//While del menu de juego		 
	}
              
  pijo.clearScreen(); 
 	pijo.refreshScr();            
                    
  /*
 		pijo.setCursor(25,12 );	pijo.writeStr("Gracias por jugar :)");
 		pijo.setCursor(20,13 );	pijo.writeStr("nos vemos en la siguiente entrega");     	
		pijo.refreshScr();
		nanosleep(&tiempo1,&tiempo2); 
	*/

   pijo.clearScreen();                     
	
  return 0;
}
