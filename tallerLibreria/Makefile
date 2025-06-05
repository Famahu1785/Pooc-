CXX=g++
ARGS=-std=c++11 -Wall
INCLUDES=-I./include
SRC=src/*.cpp

build:
	mkdir -p build

compile: build 
	$(CXX) $(ARGS) $(INCLUDES) -o build/main $(SRC) main.cpp

run: build
	./build/main

all: compile run

clean:
	rm -rf build