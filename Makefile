Main:  Main0001.o Option.o BinomialModel.o 
	g++ Main0001.o Option.o BinomialModel.o -o Main

Main0001.o : Main0001.cpp
	g++ -c Main0001.cpp

Option.o : Option.cpp Option.h
	g++ -c Option.cpp

BinomialModel.o : BinomialModel.cpp BinomialModel.h
	g++ -c BinomialModel.cpp

clean:
	rm *.o Main
