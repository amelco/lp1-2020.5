GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -g
PROGRAMA = conta
REQUIREMENTS = main.o Conta.o

$(PROGRAMA): $(REQUIREMENTS)
	@echo "Gerando binário..."
	$(GCC) -o $(PROGRAMA) $(REQUIREMENTS)

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp include/Conta.h
	$(GCC) $(GCC_FLAGS) -c src/Conta.cpp


clean:
	rm *.o
	rm -rf bin

all: $(PROGRAMA)

.PHONY: clean all