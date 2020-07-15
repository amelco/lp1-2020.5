GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -g
PROGRAMA = conta
REQUIREMENTS = main.o Conta.o Cliente.o ClientePJ.o

$(PROGRAMA): $(REQUIREMENTS)
	@echo "Gerando binário..."
	$(GCC) -o $(PROGRAMA) $(REQUIREMENTS)

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp include/Conta.h
	$(GCC) $(GCC_FLAGS) -c src/Conta.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

ClientePJ.o: src/ClientePJ.cpp include/ClientePJ.h
	$(GCC) $(GCC_FLAGS) -c src/ClientePJ.cpp

clean:
	rm *.o

all: $(PROGRAMA)

.PHONY: clean all