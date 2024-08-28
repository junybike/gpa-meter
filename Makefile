TG: Testground.o Files.o Helper.o Course.o 
	g++ -Wall Testground.o Files.o Helper.o Course.o -o TESTGROUND

main.o: main.cpp
	g++ -Wall -c main.cpp

Testground.o: Testground.cpp 
	g++ -Wall -c Testground.cpp

Files.o: Files.hpp Files.cpp
	g++ -Wall -c Files.cpp

Helper.o: Helper.hpp Helper.cpp
	g++ -Wall -c Helper.cpp

Course.o: Course.hpp Course.cpp
	g++ -Wall -c Course.cpp

clean:
	rm -f *.o *.gch