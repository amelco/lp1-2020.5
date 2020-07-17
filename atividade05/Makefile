GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -g
PROGRAMA = supermercado
REQUIREMENTS = main.o Cliente.o Estabelecimento.o App.o Fornecedor.o

$(PROGRAMA): $(REQUIREMENTS)
	@echo "Gerando binário..."
	$(GCC) -o $(PROGRAMA) $(REQUIREMENTS)

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

Estabelecimento.o: src/Estabelecimento.cpp include/Estabelecimento.h
	$(GCC) $(GCC_FLAGS) -c src/Estabelecimento.cpp

Fornecedor.o: src/Fornecedor.cpp include/Fornecedor.h
	$(GCC) $(GCC_FLAGS) -c src/Fornecedor.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

test: src/test.cpp include/vetor_supermercado.h
	$(GCC) $(GCC_FLAGS) -o test src/test.cpp

clean:
	rm *.o
	rm supermercado
	rm *.txt
	rm caixa.csv
	rm test

all: $(PROGRAMA)

.PHONY: clean all