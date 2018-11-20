ArbolP.exe: nodo.o arbolP.o main.o
	g++ nodo.o arbolP.o main.o -o ArbolP.exe

nodo.o: nodo.cpp
	g++ -c -g nodo.cpp

arbolP.o: arbolP.cpp
	g++ -c -g arbolP.cpp

main.o: main.cpp
	g++ -c -g main.cpp

clean:
	rm *.o *~ core ArbolP.exe