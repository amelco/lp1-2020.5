GCC=g++
INCLUDE=include
NOME_PROG=empresa
GCC_ARGS=-Wall -std=c++11 -I $(INCLUDE)
REQUIREMENTS=main.o Funcionario.o Empresa.o

$(NOME_PROG): $(REQUIREMENTS)
	$(GCC) -o $(NOME_PROG) $(REQUIREMENTS)

main.o: src/main.cpp
	$(GCC) $(GCC_ARGS) -c src/main.cpp

Funcionario.o: src/Funcionario.cpp
	$(GCC) $(GCC_ARGS) -c src/Funcionario.cpp

Empresa.o: src/Empresa.cpp
	$(GCC) $(GCC_ARGS) -c src/Empresa.cpp

clean:
	rm $(NOME_PROG)
	rm *.o

all: $(NOME_PROG)