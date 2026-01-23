all: derle bagla calistir
derle: 
	g++ -c -I "./include" ./src/arac.cpp -o ./lib/arac.o
	g++ -c -I "./include" ./src/otopark.cpp -o ./lib/otopark.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o

bagla:
	g++ ./lib/main.o ./lib/arac.o ./lib/otopark.o -o ./bin/program

calistir:
	./bin/program


	