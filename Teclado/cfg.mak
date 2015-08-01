SRC=src
INC=inc
OBJ=obj
DIST=dist
EXE=teclado
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
