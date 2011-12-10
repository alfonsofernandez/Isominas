#include "Tablero.h"
                             
 
//Constructor del tablero
Tablero::Tablero(){
	 
	this->numCasillasX =   (KANCHOTOTAL/KANCHOCELDA) ;
	this->numCasillasY =   (KALTOTOTAL/KALTOCELDA);	
	this->inicioX = 0;
	                                                        
 
}

void Tablero::pintar(Coor casillas , StdPijo & pijo , bool pintar, bool isSleep =false){
	
	int cX=this->inicioX+KANCHOTOTAL;
	int cY=KALTOTOTAL;
	int suma=0;	
  
	                                 	
	//Pintar lo basico del tabler               
	if(this->inicioX >0) pijo.setColor(ANORMAL, CWHITE, CGREEN);         	
	else                 pijo.setColor(ANORMAL, CGREEN, CWHITE);         
	
                                       
	
	for(int y=0; y<cY; y ++) 
	{  				                               
 			for(int x=this->inicioX; x<=cX; x ++) 
			{			  			    							
					if(x % KANCHOCELDA==0)
					{
						pijo.setCursor(x+suma, y); 
				    pijo.writeChar('\\');                 				    
				  }
				  else
				  {
						if((y+1) % KALTOCELDA==0){
							pijo.setCursor(x+suma, y); 
					    pijo.writeChar('_');
						}            
						else
						{            

							pijo.setCursor(x+suma, y); 
							pijo.writeChar(' ');	
						}                            

				  }
			}  
		  suma++;
	 }    
 			for(int x=0; x<this->numCasillasX; x ++)   
			{  				                               
				for(int y=0; y<this->numCasillasY; y ++) 
				{
					switch(casillas[x][y]) {
						case 1: //Jugador               
							this->pintaJugador(x,y,pijo);
						break;
						case 2://Pisada
							this->marcarRastro(x,y,pijo);
						break;
						case 3: // Mina
				if(pintar)			this->pintaMina(x,y,pijo);
						break;      
						}
				 }
			}	
			if(isSleep) sleep(1);
}
/*
  Name : Marcar
	Desc : Marca la casilla dada por cordenadas simples x,y ( "convierte" a "isometrico") 
	retur : void, solo pinta por pantalla
*/
void Tablero::marcaCasilla(int px, int py, StdPijo &pijo){
	
	int dX = (px*KANCHOCELDA)+(py*KALTOCELDA)+this->inicioX;      
	int dY = (py*KALTOCELDA);
	pijo.setColor(ABOLD, CRED, CWHITE);
        
	
	if(dY>0){
		pijo.setCursor(dX, dY-1);
		for(int j=0; j<KANCHOCELDA-1;j++)
		{
			pijo.setCursor(dX+j, dY-1);
			pijo.writeChar('_');	 
		}
	}               
	//linea superior                  
		for(int j=0; j<KANCHOCELDA;j++)
		{
			pijo.setCursor(dX+j, dY);
			pijo.writeChar(' ');	 
		}

		pijo.setCursor(dX, dY);
		pijo.writeChar('\\');
			
	pijo.setCursor(dX+KANCHOCELDA, dY);
	pijo.writeChar('\\');	 
	
	pijo.setCursor(dX+1, dY+1);
	pijo.writeChar('\\');	         
	                              
	for(int j=0; j<KANCHOCELDA;j++)
	{
		pijo.setCursor(dX+2+j, dY+1);
		pijo.writeChar('_');	 
	}
	pijo.setCursor(dX+KANCHOCELDA+1, dY+1);
	pijo.writeChar('\\');	               		
}                                      


void Tablero::marcarRastro(int px, int py, StdPijo &pijo){
	
	int dX = (px*KANCHOCELDA)+(py*KALTOCELDA)+this->inicioX;      
	int dY = (py*KALTOCELDA); 
	
	
	if(this->inicioX >0)	pijo.setColor(ANORMAL, CWHITE, CBLUE);
	else                  pijo.setColor(ANORMAL, CBLACK, CYELLOW);
		pijo.setCursor(dX, dY);
		pijo.writeChar('\\');	         
		for(int j=0; j<KANCHOCELDA;j++){
			pijo.setCursor(dX+j, dY);
			pijo.writeChar(' ');	          
		}


   //linea superior                  
		for(int j=0; j<KANCHOCELDA;j++)
		{
			pijo.setCursor(dX+j, dY);
			pijo.writeChar(' ');	 
		}                                
		
		pijo.setCursor(dX, dY);
		pijo.writeChar('\\');
		pijo.setCursor(dX+KANCHOCELDA, dY);
		pijo.writeChar('\\');	               
                                
	//linea inferior
	pijo.setCursor(dX+1, dY+1);
	pijo.writeChar('\\');	         	
	for(int j=0; j<KANCHOCELDA;j++)
	{
		pijo.setCursor(dX+2+j, dY+1);
		pijo.writeChar('_');	 
	}
	pijo.setCursor(dX+KANCHOCELDA+1, dY+1);
	pijo.writeChar('\\');	               
		
}

void Tablero::pintaJugador(int px, int py, StdPijo &pijo) 
{                          
	this->marcaCasilla(px,py,pijo);
	
 	int dX = (px*KANCHOCELDA)+(py*KALTOCELDA)+this->inicioX;      
	int dY = (py*KALTOCELDA);                                   
	                       
	//Corrección para el ancho de celda
	if(KANCHOCELDA==5) dX+=4;
	
	if(this->inicioX >0)	pijo.setColor(AUNDERLINE, CBLUE, CWHITE);
	else                  pijo.setColor(AUNDERLINE, CBLACK, CWHITE);
                                       
	//Cabeza
	pijo.setCursor(dX, dY);	
	if(this->inicioX >0) pijo.writeChar('o');                     
	else pijo.writeChar('0');                        
                                                                 
	if(this->inicioX >0)	pijo.setColor(ANORMAL, CBLUE, CWHITE);
	else                  pijo.setColor(ANORMAL, CBLACK, CWHITE);
	
	//Piernas
	pijo.setCursor(dX, dY+1);
	pijo.writeChar('A');
	
}

void Tablero::pintaMina(int px, int py, StdPijo &pijo) 
{
	int dX = (px*KANCHOCELDA)+(py*KALTOCELDA)+this->inicioX;      
	int dY = (py*KALTOCELDA);
	if(KANCHOCELDA==5) dX+=4;
	pijo.setColor(ANORMAL, CRED, CWHITE);
	pijo.setCursor(dX, dY+1);	                                   
	pijo.writeChar('*');                                        
	
 	
}               


void Tablero::pintarTitulo(int modoJuego,StdPijo & pijo)
{
		pijo.setColor(ABOLD, CYELLOW, CBLACK);                  
		int x,y;
		x=0;
		y=0;
		
		pijo.setCursor(x, y);
		pijo.writeStr("                      _/_/_/         _/_/_/       _/_/_/"             );					pijo.setCursor(x, y+1);
		pijo.writeStr("                       _/         _/            _/    _/"             );					pijo.setCursor(x, y+2);
		pijo.writeStr("                      _/           _/_/        _/    _/"              ); 				pijo.setCursor(x, y+3);
		pijo.writeStr("                     _/               _/      _/    _/"               ); 		 		pijo.setCursor(x, y+4);
		pijo.writeStr("                  _/_/_/       _/_/_/         _/_/_/"                 );					pijo.setCursor(x, y+5);
		pijo.writeStr("																																						 ");	pijo.setCursor(x, y+6);
		pijo.writeStr("     _/      _/        _/_/_/       _/      _/         _/_/          _/_/_/ ");	pijo.setCursor(x, y+7);  
		pijo.writeStr("    _/_/  _/_/          _/         _/_/    _/       _/    _/      _/         ");	pijo.setCursor(x, y+8);         
		pijo.writeStr("   _/  _/  _/          _/         _/  _/  _/       _/_/_/_/        _/_/");				pijo.setCursor(x, y+9);      
		pijo.writeStr("  _/      _/          _/         _/    _/_/       _/    _/            _/");			pijo.setCursor(x, y+10);     
		pijo.writeStr(" _/      _/        _/_/_/       _/      _/       _/    _/      _/_/_/");					pijo.setCursor(x, y+11);
		pijo.setColor(ABOLD, CYELLOW, CBLACK);                                                    		                                                                                                                                            

		pijo.setCursor(x, y+12);                                  		
		pijo.writeStr("                  1 JUGADOR                         ");
  	pijo.setCursor(x, y+13);                                  		
		pijo.writeStr("                  2 JUGADORES (W,A,S,D) & (J,I,L,K)            ");
		
		pijo.setCursor(12, y+11+modoJuego);                                  		
		pijo.writeStr(">");	                    		  
		pijo.setCursor(12, 18);
		pijo.writeStr("CONTROLES JUGADOR 1 : W A S D  SPACE ");                                  		
		pijo.setCursor(12, 19);                            
		pijo.writeStr("CONTROLES JUGADOR 1 : J I L K  ENTER");

}                      
// TODO: Pasar de 6 parametros a hacer un struct sería mas legible
void Tablero::pintarMarcador(int pPuntos1, int pVidas1 , int pMinas1,int pNivel1,int pPuntos2, int pVidas2 , int pMinas2, int pNivel2,StdPijo &pijo){ 

  stringstream s1,s2,s3,s4,s5,s6,s7,s8;        //para las conversione de entero a cadena
	s1 << pPuntos1;	string puntos1 = s1.str();	s2 << pPuntos2;	string puntos2 = s2.str();
	s3 << pMinas1;	string minas1 = s3.str();	s4 << pMinas2;	string minas2 = s4.str();
	s5 << pVidas1;	string vidas1 = s5.str();	s6 << pVidas2;	string vidas2 = s6.str();
  s7 << pNivel1;	string nivel1 = s7.str();	s8 << pNivel2;	string nivel2 = s8.str();	
	
	pijo.setColor(ABOLD, CYELLOW, CBLACK);                                                    		                                                                                                                                            
	pijo.setCursor(0, 20); pijo.writeChar(' ');
	for(int j=1; j < 79;j++){
		pijo.setCursor(j, 20);pijo.writeChar('_');		
 }	                 
	pijo.setCursor(79, 20);	pijo.writeChar(' '); 
	pijo.setCursor(0, 21);	pijo.writeChar('/'); 
	pijo.setCursor(79, 21);	pijo.writeChar('\\'); 	
	pijo.setColor(AUNDERLINE, CYELLOW, CBLACK);
	pijo.setCursor(2,  22);	pijo.writeChar('o'); 
	pijo.setColor(ABOLD, CYELLOW, CBLACK);
	pijo.setCursor(2,  23);	pijo.writeChar('A'); 
	pijo.setCursor(0,  22);	pijo.writeChar('|'); 
	pijo.setCursor(0,  23);	pijo.writeChar('|'); 
	pijo.setCursor(4,  23);	pijo.writeChar('x'); 
	pijo.setCursor(5,  23);	pijo.writeStr(vidas1.c_str()); 

	pijo.setCursor(8,  23);	pijo.writeStr("NIVEL: ");             
  pijo.setCursor(16,  23);	pijo.writeStr(nivel1.c_str()); 	
	
	pijo.setCursor(8,  22);	pijo.writeStr("PUNTOS: "); 	
  pijo.setCursor(16,  22);	pijo.writeStr(puntos1.c_str()); 	
	
	pijo.setCursor(22,  22);	pijo.writeStr("MINAS: ");  
  pijo.setCursor(29,  22);	pijo.writeStr(minas1.c_str());  
	
	// JUGADOR 2 
	pijo.setColor(AUNDERLINE, CYELLOW, CBLACK);
	pijo.setCursor(40,  22);	pijo.writeChar('0'); 
	pijo.setColor(ABOLD, CYELLOW, CBLACK);
	pijo.setCursor(40,  23);	pijo.writeChar('A'); 
	pijo.setCursor(42,  23);	pijo.writeChar('x'); 
  pijo.setCursor(43,  23);	pijo.writeStr(vidas2.c_str()); 

  pijo.setCursor(48,  23);	pijo.writeStr("NIVEL: " );     
  pijo.setCursor(43,  24);	pijo.writeStr(nivel2.c_str()); 
                                            
	
	pijo.setColor(ABLINK, CYELLOW, CBLACK);	
	pijo.setCursor(48,  22);	pijo.writeStr("PUNTOS:"); 		 
  pijo.setCursor(56,  22);	pijo.writeStr(puntos2.c_str()); 		
	
	//usleep(500);
	pijo.setColor(ABOLD, CYELLOW, CBLACK);	
	pijo.setCursor(62,  22);	pijo.writeStr("MINAS: ");    
	pijo.setCursor(69,  22);	pijo.writeStr(minas2.c_str());    
	
	pijo.setCursor(0,   24);	pijo.writeChar('\\');
	pijo.setCursor(79,  24);	pijo.writeChar('/');
	pijo.setCursor(79,  22);	pijo.writeChar('|'); 
	pijo.setCursor(79,  23);	pijo.writeChar('|');

	for(int j=1; j < 79;j++){	pijo.setCursor(j, 24); pijo.writeChar('_');		} 	
		                                                      	
}                                      

void Tablero::pintarSiguienteNivel(int segundos,StdPijo & pijo){
	stringstream s1,s2;                    
	string strSegundos,strPuntos;                
	
	int cX=this->inicioX+KANCHOTOTAL;
	int cY=KALTOTOTAL;
	int suma=0;	
	int totalPuntos ;                   
	totalPuntos = ((60-segundos)*10);
	s1 <<  segundos <<" SEGUNDOS ";
	s2 << "+ "<<totalPuntos<<endl;
	strPuntos = s2.str();
	strSegundos = s1.str();
	//Pintar lo basico del tabler               
	pijo.setColor(ANORMAL, CWHITE, CBLACK);         	
	for(int y=0; y<cY; y ++){ for(int x=this->inicioX; x<=cX; x ++) { pijo.setCursor(x+suma, y); pijo.writeChar(' '); }  suma++;}	 
  	pijo.setCursor(this->inicioX+14,  10);    
		pijo.writeStr(strSegundos.c_str());            
		pijo.setCursor(this->inicioX+14,  11);    
		pijo.writeStr(strPuntos.c_str());
  	pijo.refreshScr();            									 
	  sleep(2);
    pijo.clearScreen();                     				 
    pijo.refreshScr();
}
void Tablero::pintarExplosion(StdPijo & pijo){
	         
	int cX=this->inicioX+KANCHOTOTAL;
	int cY=KALTOTOTAL;
	int suma=0;	

	//Pintar lo basico del tabler               
	pijo.setColor(ANORMAL, CBLACK, CRED);         	
	for(int y=0; y<cY; y ++){ for(int x=this->inicioX; x<=cX; x ++) { pijo.setCursor(x+suma, y); pijo.writeChar(' '); }  suma++;}	 
		pijo.setCursor(this->inicioX+14,  10);    
		pijo.writeStr("¡¡¡¡¡ BOOOOM !!!!    ");
  	pijo.refreshScr();            									 
		sleep(1);
		pijo.clearScreen();                     				 
  	pijo.refreshScr();
}

	void Tablero::pintarGameOver(StdPijo & pijo){
		
		int cX=this->inicioX+KANCHOTOTAL;
		int cY=KALTOTOTAL;
		int suma=0;	

		//Pintar lo basico del tabler               
		pijo.setColor(ANORMAL, CYELLOW, CBLACK);         	
		for(int y=0; y<cY; y ++){ for(int x=this->inicioX; x<=cX; x ++) { pijo.setCursor(x+suma, y); pijo.writeChar(' '); }  suma++;}	 
			pijo.setCursor(this->inicioX+14,  10);    
			pijo.writeStr("GAME OVER");
	  	pijo.refreshScr();            									 
			sleep(1);
			pijo.clearScreen();                     				 
	  	pijo.refreshScr();
		
		
	}      


