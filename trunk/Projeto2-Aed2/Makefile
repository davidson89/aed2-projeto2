FLAGS = -ansi -pedantic -Wall -g -efence 
CLASSES = main.cpp UnionFind.cpp Les.cpp Elemento_Floresta.cpp

# regra principal
all: lab2

# gera o executável
lab2:
	g++ -o lab2 ${CLASSES} 
	@echo "\n\n*****Para gerar todos os arquivos do doxygen digite make lab2d*****\n\n"

# make clean
clean:
	rm -f *.o lab2

lab2d:
	g++ ${FLAGS} -o lab2d: ${CLASSES}
	doxygen -g
	doxygen
