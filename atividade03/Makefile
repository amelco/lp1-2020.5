GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -g
PROGRAMA = diary
TEST = test
BIN = bin/
MATRICULA = 20190003903
REQUIREMENTS = main.o App.o Date.o Diary.o Time.o
TEST_REQUIREMENTS = test_main.o App.o Date.o Diary.o Time.o

$(PROGRAMA): $(REQUIREMENTS)
	@echo "Gerando binário..."
	$(GCC) -o $(BIN)$(PROGRAMA) $(REQUIREMENTS)

main.o: src/main.cpp bin/
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Time.o: src/Time.cpp include/Time.h
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp

test_main.o: src/test_main.cpp bin/
	$(GCC) $(GCC_FLAGS) -c src/test_main.cpp

bin/:
	mkdir bin

clean:
	rm *.o
	rm bin/*
	rm *.zip

test: $(TEST_REQUIREMENTS)
	$(GCC) -o $(BIN)$(TEST) $(TEST_REQUIREMENTS)

pdf: diary.md bin/
	pandoc diary.md --pdf-engine=pdflatex -o $(BIN)diary.pdf

zip:
	zip -r $(MATRICULA).zip src include

all: $(PROGRAMA) test pdf zip

.PHONY: clean test pdf zip all