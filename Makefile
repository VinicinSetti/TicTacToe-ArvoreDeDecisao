CC = g++
CFLAGS :=-Wall -Wextra $(CFLAGS)
EXEC = main

SRCS = main.cpp Dominio/Menu.h Dominio/Arvore.h Dominio/Mapa.h
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o Dominio/*.o $(EXEC)
