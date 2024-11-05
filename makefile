pass: driver.o
	g++ -o pass driver.o

driver.o: driver.cpp
	g++ -c driver.cpp

clean:
	rm *.o pass