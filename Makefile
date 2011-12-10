# Nick del usuario
NICK=phantomas
# Nombre del programa
NOMBRE_PROGRAMA=isominas
# Listado de fuentes del programa
FUENTES=main.cpp Juego.cc Jugador.cc Minas.cc Tablero.cc StdPijo.cpp Juego.h Jugador.h Minas.h Tablero.h
# -lrt      
# Otros archivos a incluir en el paquete, si quieres
# ¡Ojo!, el README, Makefile y COPYING son obligatorios
# Aquí se pueden poner los .h que utilices
OTROS=README Makefile COPYING StdPijo.h definitions.h
# Comentar para depurar
CXXFLAGS=-g
# Librerias a usar
LIBS= -lncurses

# Reglas del Makefile
.PHONY=all, clean, dist

all: ${NOMBRE_PROGRAMA}

clean:
	rm -f ${NOMBRE_PROGRAMA}

dist:
	@tar cvzf ${NICK}-${NOMBRE_PROGRAMA}.tar.gz ${FUENTES} ${OTROS}

${NOMBRE_PROGRAMA}: ${FUENTES}
	${CXX} ${CXXFLAGS} $^ -o $@ ${LIBS}
