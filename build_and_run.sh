#!/bin/bash
g++ -std=c++11 -I headers/ -c source/Enemy.cpp -o build/Enemy.o
g++ -std=c++11 -I headers/ -c source/Cell.cpp -o build/Cell.o
g++ -std=c++11 -I headers/ -c source/Turret.cpp -o build/Turret.o
g++ -std=c++11 -I headers/ -c source/ObjectsStorage.cpp -o build/ObjectsStorage.o
g++ -std=c++11 -I headers/ -c source/FinderCatalog.cpp -o build/FinderCatalog.o
g++ -std=c++11 -I headers/ -c source/Background.cpp -o build/Background.o
g++ -std=c++11 -I headers/ -c source/BG_Builder.cpp -o build/BG_Builder.o
g++ -std=c++11 -I headers/ -c source/Game.cpp -o build/Game.o
g++ -std=c++11 -I headers/ -c source/main.cpp -o build/main.o

g++ -std=c++11 build/main.o build/Cell.o build/Background.o build/Turret.o build/ObjectsStorage.o build/FinderCatalog.o build/BG_Builder.o build/Enemy.o \
build/Game.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
