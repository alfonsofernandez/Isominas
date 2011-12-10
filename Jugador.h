#include <iostream>
#include <string>
#include <stdlib.h>   
#include "StdPijo.h"     
 
using namespace STDP;          

#ifndef JUGADOR_H
#define JUGADOR_H
        


const int KANCHOTOTAL = 25;
const int KALTOTOTAL  = 20;         

const int KANCHOCELDA = 5;
const int KALTOCELDA  = 2;  
                                 
typedef   int    Coor[KANCHOTOTAL][KALTOTOTAL]; //cordenadas                          



class Jugador
{
	public:                                   
  	//Constructor 
		Jugador();		    
		int numJugador; //Indica que número de jugador es 
		int modoJuego;
		int vidas;
		int posx, posy; //posicion en el tablero en terminos de casilla
		bool judador1;
		//recibe las cordenadas del jugador , y las de las minas Para pintar lo que toque                                                                          
		void moverSegunTecla(int tecla);
		
		
		
		                                        
} ;      

#endif /* JUGADOR_H */