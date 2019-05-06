all: lib_func input main

FUNC_DIR = function/
INPUT_DIR = input_lib/
MAIN_DIR = part103/

INPUT_LIB_SRC = $(INPUT_DIR)input_lib.c
PARSE_SRC = $(INPUT_DIR)parse.c
TOKEN_SRC = $(INPUT_DIR)token.c
INPUT_SRC =   $(INPUT_LIB_SRC) $(TOKEN_SRC) $(PARSE_SRC)

MAIN_SRC = part103/calcCube.c part103/calcCircle.c part103/dice.c part103/main.c part103/plotter.c part103/part103.c part103/printMenu.c

INPUT_O = lib/input.o
PARSE_O = lib/parse.o
TOKEN_O = lib/token.o

INPUT_OUTS = $(INPUT_O) $(PARSE_O) $(TOKEN_O)

ARCHIVES = 

lib_func: $(FUNC_DIR)func.c
	mkdir -p lib
	mkdir -p bin
	gcc -c -fpic -o lib/func.o $(FUNC_DIR)func.c -I $(FUNC_DIR)
	ar rcs lib/libfunc.a lib/func.o 

input: 	$(INPUT_SRC)
	gcc -c -fpic -o $(INPUT_O) $(INPUT_DIR)input_lib.c -I $(INPUT_DIR) -I $(FUNC_DIR)
	gcc -c -fpic -o $(PARSE_O) $(PARSE_SRC) -I $(INPUT_DIR) -I $(FUNC_DIR)
	gcc -c -fpic -o $(TOKEN_O) $(TOKEN_SRC) -I $(INPUT_DIR) -I $(FUNC_DIR)
	ar rcs lib/libinput.a $(INPUT_OUTS)

main: $(MAIN_SRC)
	gcc -o bin/randomizer $(MAIN_SRC) $(INPUT_OUTS) -L lib/ -I input_lib/ -I function/ -l input -l func -lm

clean:
	rm -rf lib/* bin/*
	
