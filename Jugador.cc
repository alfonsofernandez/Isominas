#include "Jugador.h"
                             
 
//Constructor del tablero
Jugador::Jugador(){
	this->numJugador=1;    
	this->modoJuego=1 ;
	this->vidas=0; //indica que el juego no ha empezado y estamos en el menu, posteriormente en juego.iniciar se le daran vidas
}

void Jugador::moverSegunTecla(int tecla){
	if(this->numJugador==1)
	{
		if(this->vidas==0) //Si no ha empezado el juego , estamos en la pantalla de menu y las teclas elijen modo juego
		{
				switch (tecla){	 
					
							case 115: if(this->modoJuego<2)	 this->modoJuego++; break;
							case 119: if(this->modoJuego>1)	 this->modoJuego--; break;
				 }				
		} 
		else
		{
				switch (tecla){	 
							case  97: if(this->posx>0)	 this->posx--; break;   
							case 100: if(this->posx<4)   this->posx++; break;   					             
							case 115: if(this->posy<9)	 this->posy++; break;
							case 119: if(this->posy>0)	 this->posy--; break;
				 }
		}
	}
	else if(this->numJugador==2)
	{                  
		switch (tecla){	 
					case 106: if(this->posx>0)	 this->posx--; break;   
					case 108: if(this->posx<4)   this->posx++; break;   					             
					case 107: if(this->posy<9)	 this->posy++; break;
					case 105: if(this->posy>0)	 this->posy--; break;		
		 }
	}
	
}


