/**
 *   Copyright 2011 (c) Francisco José Gallego Durán <fgallego@byterealms.com>
 *   Copyright 2011 (c) ByteRealms <info@byterealms.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; version 3 of the License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 */

//////////////////////////////////////////////////
// Ejemplo de uso de la versión básica de StdPijo
//////////////////////////////////////////////////

// Incluimos la cabecera principal de StdPijo
#include "StdPijo.h"

// Incluimos cabeceras para números aleatorios y retardos
#include <ctime>
#include <cstdlib>
#include <unistd.h>        
#include <sstream>


// Usamos globalmente el espacio de nombres de stdpijo (STDP)
using namespace STDP;          
string intToString(int number);       
                
stringstream debug;

void pintarTablero(int,int,StdPijo &);
void marcarCasilla(int cX,int cY,StdPijo &); 

string intToString(int number){
	stringstream ss;
	ss << number;
	return (ss.str());
}                                           


void marcarCasilla(int cX,int cY,StdPijo & stdp){   
	
	int suma=0;
	int desdeX=0;
	
	for(int y=cY+1; y <=cY+2; y ++) 
	{  				                               
 			for(int x=(cX*10)+(cY*2)+1; x<=(cX*10)+10+(cY*2)+1; x ++) 
			{			  			    							
					if(x % 10==0)
					{
						stdp.setCursor(x+suma, y); 
				    stdp.writeChar('\\');                 				    
				  }
				  else
				  {
						if((y+1) % 2==0){
							stdp.setCursor(x+suma, y); 
					    stdp.writeChar('_');
						}            
						else
						{            

							stdp.setCursor(x+suma, y); 
							stdp.writeChar(' ');	
						}                            

				  }
			}  
		  suma++;
	 }
}    
void pintarTablero(int ancho, int alto,StdPijo &stdp)
{
	int suma=0;
	for(int y=0; y < 20; y ++) 
	{  				
			for(int x=0; x <60; x ++) 
			{			  			    							
					if(x % ancho==0)
					{
						stdp.setCursor(x+suma, y); 
				    stdp.writeChar('\\');                 				    
				  }
				  else
				  {
						if((y+1) % alto==0){
							stdp.setCursor(x+suma, y); 
					    stdp.writeChar('_');
						}            
						else
						{            
					    stdp.setColor(ANORMAL, CBLACK, CWHITE);
					    
							stdp.setCursor(x+suma, y); 
							stdp.writeChar(' ');	
						}                            
						
				  }
			}  
		  suma++;                          			
	}
	
	
}
int main (void)
{
    // Obtenemos referencia de acceso a StdPijo
    StdPijo& stdp = StdPijo::p();

    // Inicializamos la pantalla
    stdp.init();

    // Borramos la pantalla

    // 0 Segundos de retardo de espera desde que se recibe un
    // caracter de escape por la entrada estándar. Esto sirve para
    // que no tengamos que esperar cuando pulsamos la tecla escape
    // a que verifique que no es un código de escape.
    stdp.setGlobalEscapeDelay(0);

    // Cambiamos a color azul negrita, sobre fondo amarillo cantoso :)
    stdp.setColor(ABOLD, CBLUE, CBLACK);

                       
		int contX=3;
 	  int contY=1;
		int tecla;    
		string var;
                         
		int altura = 2;          
		
		int segundos;  
		int pos[6][10];  
		int anteriorX,anteriorY;

    // Esperamos hasta que el usuario pulse Escape, escribiendo
    // caracteres en pantalla mientras.
    stdp.clearScreen();

		anteriorX=0;
		anteriorY=0;
		while (true)
		{                             
	  
			   
  
				// Posicionamos el cursor en fila 16, columna 10
		    stdp.setColor(ANORMAL, CBLACK, CWHITE);
                                  
	//		  pintarTablero(10,altura,stdp);                 
		
				usleep(20000);
				tecla = stdp.getKey();
		
		 	anteriorX=contX;
				anteriorY=contY;
					switch (tecla){
				
						case 97:  
							 contX-=10;   
						break;
						case  100:      				 	 
						 contX+=10;   
						break;              
						case 115: 
							contY+=altura; contX+=2;  
						break;
						case 119:   
							contY-=altura; contX-=2;
						break;
					}
          stdp.setCursor(24,0);				    
 				stdp.setCursor(24,0);
				var = intToString(tecla);
			 stdp.writeChar(var[0]); 
			stdp.setCursor(25,0);                
			 stdp.writeChar(var[1]);   
			stdp.setCursor(26,0);                
			
			stdp.writeChar(var[2]); 
			                                                    
            
			//	  debug << "ContX"<<tecla<<endl;
			//	 stdp.writeStr(debug.str().c_str());
				//	marcarCasilla(1,1,stdp);                

				                

//       					stdp.setColor(ABOLD, CYELLOW, CWHITE);


		    //  if(anteriorX!=contX || anteriorY>contY){  //pintamos rastro en la cordenada anterior, la primera vez no entrará aquí
						stdp.setColor(ANORMAL,  CGREEN, CBLUE);
       
		 		    stdp.setCursor(anteriorX, anteriorY-1);
						stdp.writeChar(' ');
		 			  stdp.setCursor(anteriorX, anteriorY);
						stdp.writeChar('.');
				//	}               
			
			    stdp.setCursor(contX, contY-1);
			    stdp.setColor(AUNDERLINE,  CGREEN, CWHITE);
		   		stdp.writeChar('o');                                                                                     
				  stdp.setCursor(contX, contY);
					stdp.writeChar('A');   
                    
     
                 
    
			



		    /*
		 		  stdp.setColor(ANORMAL, CRED, CWHITE);			                     	
					stdp.setCursor(18,4);
		   	  stdp.writeChar('2'); 
		 		 stdp.setCursor(30,6);
				 stdp.writeChar('*');
				 stdp.setCursor(0,25);               
		                     
				*/
		
				// segundos++;
			 //  var =          intToString((segundos/1000)-134500); 
			//	var = intToString(tecla);
			// stdp.writeStr(var.c_str());	                                                                   
    
		    // Borramos el asterisco el 90% de las veces
		       // if (rand() % 100 < 90) {
		         //   stdp.setCursor(x, y);
		          //  stdp.writeChar(' ');
		       // }

		        // Refrescamos la pantalla para asegurarnos de que
		        // se ven los últimos cambios    
			  
				//stdp.setCursor(0,24);
				
					
				stdp.refreshScr();    
			  
			
			

    }
              
    // Restauramos el estado original del terminal

    stdp.end();

    // Salimos sin errores
    return 0;
}

