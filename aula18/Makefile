GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -g
PROGRAMA = conta
REQUIREMENTS = main.o Conta.o ClientePF.o ClientePJ.o

$(PROGRAMA): $(REQUIREMENTS)
	@echo "Gerando binário..."
	$(GCC) -o $(PROGRAMA) $(REQUIREMENTS)

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp include/Conta.h
	$(GCC) $(GCC_FLAGS) -c src/Conta.cpp

ClientePF.o: src/ClientePF.cpp include/ClientePF.h
	$(GCC) $(GCC_FLAGS) -c src/ClientePF.cpp

ClientePJ.o: src/ClientePJ.cpp include/ClientePJ.h
	$(GCC) $(GCC_FLAGS) -c src/ClientePJ.cpp

clean:
	rm *.o

all: $(PROGRAMA)

.PHONY: clean all