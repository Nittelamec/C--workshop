CC=g++
CXXFLAGS= -Wall -Wextra -Werror -std=c++20 -pedantic -Wold-style-cast

OBJS= main.o game.o player.o invalid_argument.o
BIN= main

all: ${BIN}

${BIN}: ${OBJS}

clean:
	${RM} ${OBJS} ${BIN}

.PHONY: clean all
