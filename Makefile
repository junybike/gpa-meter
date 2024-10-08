RUN: main.o Files.o Helper.o Course.o UI.o ScenarioControl.o
	g++ -Wall main.o Files.o Helper.o Course.o UI.o ScenarioControl.o -o RUN

TEST: Testground.o Files.o Helper.o Course.o 
	g++ -Wall Testground.o Files.o Helper.o Course.o -o TEST

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

UI.o: UI.hpp UI.cpp
	g++ -Wall -c UI.cpp

ScenarioControl.o: ScenarioControl.hpp ScenarioControl.cpp
	g++ -Wall -c ScenarioControl.cpp

clean:
	rm -f *.o *.gch