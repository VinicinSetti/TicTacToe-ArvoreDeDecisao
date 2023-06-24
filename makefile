CC = g++
CFLAGS := -Wall  -Wextra $(CFLAGS)


SRCS = main.cpp Dominio/Arvore.h Dominio/Mapa.h Dominio/Menu.h
OBJS = $(SRCS:.cpp=.o)

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) main
