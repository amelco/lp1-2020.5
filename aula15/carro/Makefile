GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -g
PROGRAMA = carro
REQUIREMENTS = main.o Carro.o

$(PROGRAMA): $(REQUIREMENTS)
	@echo "Gerando binário..."
	$(GCC) -o $(PROGRAMA) $(REQUIREMENTS)

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Carro.o: src/Carro.cpp include/Carro.h
	$(GCC) $(GCC_FLAGS) -c src/Carro.cpp


clean:
	rm *.o

all: $(PROGRAMA)

.PHONY: clean all
