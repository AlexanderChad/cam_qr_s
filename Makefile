all: CB_on_T

CB_on_T.o: CB_on_T.cpp
	g++ -c CB_on_T.cpp

QRScaner.o: QRScaner.cpp
	g++ -c QRScaner.cpp -lpthread

CB_on_T: CB_on_T.o QRScaner.o
	g++ -o CB_on_T CB_on_T.o QRScaner.o -lpthread

clean:
	rm -rf *.o CB_on_T