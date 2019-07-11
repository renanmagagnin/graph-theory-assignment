output: main.o Graph.o InputHandler.o
	g++ main.o Graph.o InputHandler.o -o output

main.o: main.cpp
	g++ -c main.cpp

Graph.o: Data\ Types/Graph.cpp Data\ Types/Graph.hpp
	g++ -c Data\ Types/Graph.cpp

InputHandler.o: Modules/InputHandler.cpp Modules/InputHandler.hpp
	g++ -c Modules/InputHandler.cpp

clean:
	rm *.o output