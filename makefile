CC = g++
CFLAGS := -Wall  -Wextra $(CFLAGS)


SRCS = main.cpp Dominio/Arvore.cpp Dominio/Mapa.cpp Dominio/Menu.cpp
OBJS = $(SRCS:.cpp=.o)

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) main
