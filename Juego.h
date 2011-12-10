#include <iostream>
#include <string>
#include <stdlib.h>           
#include <sys/time.h>    
#include "StdPijo.h"         
#include "Jugador.h"                             
#include "Minas.h"
#include "Tablero.h"                             


using namespace STDP;          

#ifndef JUEGO_H
#define JUEGO_H                                    
				                         

class Juego
{
	public:                                   
  	//Constructor 
		Juego();      
		Jugador jugador; // Para gestionar su posición 	                  
		Tablero tablero;  //Gestiona el tablero visual de la pantalla
		Coor		casillas; // Para saber que hay en cada casilla
		Minas		minas; // Para generar las minas
		
		int modoJuego;        //1 jugador o  2 jugadores
		int nivel;     
		int numMinasCerca; //Numero minas cerca
		int puntos;      
		int tiempoInvertido;
		bool iniciado;  
		
		double t1;        
		timeval tim;               
		
		
		bool noHaAcabado();		              
		int  cuantoTiempo();      
		void siguienteNivel();
		void gameOver();
		   
		void ponerMinas();
		Coor posJugador, posMinas;		
		void procesarEntrada(int entrada,StdPijo & pijo); 
		void iniciar(int); //Incia el juego           
 		                                        
} ;      

#endif /* JUEGO_H */               

