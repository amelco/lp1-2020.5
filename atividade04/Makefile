GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -g
PROGRAMA = supermercado
REQUIREMENTS = main.o Cliente.o Estabelecimento.o

$(PROGRAMA): $(REQUIREMENTS)
	@echo "Gerando binário..."
	$(GCC) -o $(PROGRAMA) $(REQUIREMENTS)

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

Estabelecimento.o: src/Estabelecimento.cpp include/Estabelecimento.h
	$(GCC) $(GCC_FLAGS) -c src/Estabelecimento.cpp

test: src/test.cpp src/Estabelecimento.cpp
	$(GCC) $(GCC_FLAGS) -o test src/Estabelecimento.cpp src/test.cpp

clean:
	rm *.o
	rm test

all: $(PROGRAMA)

.PHONY: clean all