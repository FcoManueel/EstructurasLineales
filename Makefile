CC        =g++
CFLAGS    =-c -Wall
LDFLAGS   =
INCLUDE   =-I./Cabeceras
OBJDIR    =Objetos/
OBJLIST   = \
	ListaOrdenadaSinRepeticion.o \
	NodoSencillo.o \
	PruebaUnitaria.o \
	Cola.o \
	Pila.o
OBJECTS   = $(addprefix $(OBJDIR), $(OBJLIST) )

all:prueba

prueba: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTS): Objetos/%.o: Fuentes/%.cpp
	$(CC) $(CFLAGS) $? -o $@ $(INCLUDE)

clean:
	rm -rf Objetos/*.o