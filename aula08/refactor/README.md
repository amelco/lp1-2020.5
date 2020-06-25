### Compilando
```bash
$ make
```

### Executando
```bash
$ bin/diary
```

### Compilando teste
```bash
$ g++ -Wall -std=c++11 -I include -o bin/test_diary test_main.cpp src/Diary.cpp src/Date.cpp src/Time.cpp
```

### Executando teste
```bash
$ bin/test_diary
```
