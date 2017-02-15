DIR_INC=./include
DIR_SRC=./src
DIR_OBJ=./obj

CC= g++
CFLAGS=-g -Wall -I $(DIR_INC)


SRC=$(wildcard ${DIR_SRC}/*.cpp)
OBJ=$(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC}))

TARGET=app

${TARGET}:${OBJ}
	$(CC) $(OBJ) -o $@ 

${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm ${DIR_OBJ}/*.o $(TARGET)
