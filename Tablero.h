#include <iostream>
#include <string>             
#include <sstream>
#include <stdlib.h>   
#include "StdPijo.h"      
#include "Jugador.h"                    
  

using namespace STDP;          

#ifndef TABLERO_H
#define TABLERO_H

class Tablero
{
	public:                                   
  //Constructor 
	Tablero();                    
	int inicioX;
	int numCasillasX;
	int numCasillasY;                  
	bool ppal;  
	
  //Recibe las cordenadas del jugador , y las de las minas Para pintar lo que toque                                                                          
  void pintar(Coor casillas,StdPijo &pijo,bool,bool);           
	void marcaCasilla(int px, int py,StdPijo &pijo); 
	void marcarRastro(int px, int py, StdPijo &pijo);
	
	void pintaJugador(int px, int py, StdPijo &pijo);               
	void pintaMina(int px, int py, StdPijo &pijo);               
	void pintarTitulo(int, StdPijo & pijo);	
	void  pintarMarcador(int pPuntos1, int pVidas1 , int pMinas1,int pNivel1,int pPuntos2, int pVidas2 , int pMinas2, int pNivel2,StdPijo &pijo);
	
	void pintarSiguienteNivel(int segundos,StdPijo & pijo);
                                                           
	void pintarExplosion(StdPijo & pijo);
	void pintarGameOver(StdPijo & pijo);            
  
                                        
} ;      

#endif /* TABLERO_H */