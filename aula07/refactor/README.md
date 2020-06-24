## Compilação:

Gerando `.o`:
```bash
$ cd src
$ g++ -Wall -std=c++11 -c -I../include *.cpp
```

Gerando executável:
```bash
$ g++ -Wall -std=c++11 -o diary *.o
```

