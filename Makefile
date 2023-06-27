CC = g++
CFLAGS := -Os -pipe -Wall -Wextra -fPIC -I. -Wno-unused-function $(CFLAGS)
LDFLAGS := $(LDFLAGS) -lstdc++ -lm -L.
EXEC = exec

SRCS = main.cpp Dominio/Menu.h Dominio/Arvore.h Dominio/Mapa.h
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC)
