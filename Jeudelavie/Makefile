
#VARIABLES
CC = g++
CFLAGS = -W -Wall
LDFLAGS = 
EXEC = option
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
HEAD = $(wildcard *.h)

#VARIABLES INTERNES
#	$@ -> nom de la cible
#	$< -> nom de la 1ere dépendance
#	$^ -> liste des dependances

#REGLES
all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%o : %c
	$(CC) -o $@ -c $< $(CFLAGS) 