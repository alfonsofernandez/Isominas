#include "Juego.h"
 
/* Name: Juego
 * Des : Constructor del juego
	Rellena la pantalla de minas
  Las casillas son el array bidimensional que define que hay en cada casilla
			0 = No hay nada
			1 = Posición del jugador
			2 = Zona por donde ha pasado el jugador
			3 = Mina!!       
			Primero tiene que rellenar las minas , llamando a la clase Minas 
			Después se posiciona el jugador 	
 */
Juego::Juego(){ 
                                                    
	this->jugador.posx=2;
	this->jugador.posy=9;
	this->modoJuego		=1;
	this->nivel=1;
	this->numMinasCerca=0;
	this->puntos=0;       
	this->iniciado=false;    
	


	for(int x=0; x< this->tablero.numCasillasX; x ++)
			for(int y=0; y< this->tablero.numCasillasY; y ++) 
			 	this->casillas[x][y]=0;	                 


	this->ponerMinas();			
			gettimeofday(& this->tim, NULL);  //Carga la hora actual
			this->t1=tim.tv_sec+(tim.tv_usec/1000000.0);      //guarda los segundos actuales



}                   
                   
           
void Juego::gameOver(){
	this->jugador.posx=2;
	this->jugador.posy=9;
	this->modoJuego		=1;
	this->nivel=1;
	this->numMinasCerca=0;
	this->puntos=0;       
	this->iniciado=false;    
	


	for(int x=0; x< this->tablero.numCasillasX; x ++)
			for(int y=0; y< this->tablero.numCasillasY; y ++) 
			 	this->casillas[x][y]=0;	                 


	this->ponerMinas();			
			gettimeofday(& this->tim, NULL);  //Carga la hora actual
			this->t1=tim.tv_sec+(tim.tv_usec/1000000.0);      //guarda los segundos actuales

	
}
/* Name: noHaAcabado
 * Des : Devuelve true si el juego no ha acabado
 *
 */
bool Juego::noHaAcabado() {
                          
	return true;

}
                      

void Juego::procesarEntrada(int entrada,StdPijo & pijo) {
	bool sinminas = true;
 	this->jugador.moverSegunTecla(entrada);                          
	if(casillas[this->jugador.posx][this->jugador.posy]==3 ){ // si has pisado una mina ...
		this->tablero.pintarExplosion(pijo);
		this->tablero.pintar(this->casillas,pijo,true,false); 
		this->jugador.vidas--;   
 		this->jugador.posx=2;
		this->jugador.posy=9;                                                
		casillas[this->jugador.posx][this->jugador.posy]=1;                    

	}else{                                                                                         
			//Establece nueva posicion en la casilla
			casillas[this->jugador.posx][this->jugador.posy]=1;                                        
		  //Comprobar Minas alrededor         
		  this->numMinasCerca=0;  //se resetea para no acumular deñ mov anterior
			if(this->jugador.posx<4) { if((casillas[this->jugador.posx+1][this->jugador.posy]==3 ) ) this->numMinasCerca++;  } //Mirar derecha			
			if(this->jugador.posx>0) { if((casillas[this->jugador.posx-1][this->jugador.posy]==3 ) ) this->numMinasCerca++;  } //Mirar izquierda
			if(this->jugador.posy>0) { if((casillas[this->jugador.posx][this->jugador.posy-1]==3 ) ) this->numMinasCerca++;  } //Mirar arriba


				//Dejar el rastro , se cambian todos los 1 que no coincidan con la pos actual por doses
				for(int x=0; x<tablero.numCasillasX; x ++)
						for(int y=0; y<tablero.numCasillasY; y ++)
							if(casillas[x][y]==1&&  !(x==this->jugador.posx && y==this->jugador.posy ))
							   casillas[x][y]=2;	 														 
	}   		
}           
void Juego::siguienteNivel(){
 	 	this->nivel++;
		this->jugador.posx=2;
		this->jugador.posy=9;   
		//vaciar casillas 
		for(int x=0; x<tablero.numCasillasX; x ++)
				for(int y=0; y<tablero.numCasillasY; y ++)
					this->casillas[x][y]=0;				
		this->casillas[2][9]=1;		
		ponerMinas();		       
		
		this->tiempoInvertido=cuantoTiempo();    
		this->puntos = ((60-tiempoInvertido)*10);
		//se resetea el tiempo
		gettimeofday(& this->tim, NULL);  //Carga la hora actual
		this->t1=tim.tv_sec+(tim.tv_usec/1000000.0);      //guarda los segundos actuales
		        
}                                

void Juego::iniciar(int modoJuego){
  	this->modoJuego=1;       
		this->iniciado=true;	 
		this->jugador.vidas=3;                  		
		this->ponerMinas(); //Rellenar el array de casillas con minas		
}                              


int Juego::cuantoTiempo(){
	gettimeofday(& this->tim, NULL);
	double t2=this->tim.tv_sec+(this->tim.tv_usec/1000000.0);
	int   resultado = (int)(t2-this->t1 );
	return resultado;
}
        
void Juego::ponerMinas(){
	int x;
	int y;             
	int numMinas;
	numMinas = this->nivel *2;
	srand ( time(NULL) );
                     

	for(int j =0; j<= numMinas;j++){
		x = rand() % this->tablero.numCasillasX;
		y = rand() % this->tablero.numCasillasY;    
		this->casillas[x][y]=3;		
	}

}

      
























