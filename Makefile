## Name:  Chris Giuffrida
## Class:  Fundamentals of Computing Lab 8
## Makefile

CMP = g++ -std=c++11
CLASS = lifeboard
MAIN = life
EXEC = playlife

$(EXEC): $(CLASS).o $(MAIN).o
	$(CMP) $(CLASS).o $(MAIN).o -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c $(MAIN).cpp -o $(MAIN).o

clean:
	rm *.o
	rm $(EXEC)
