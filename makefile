pass: driver.o
	g++ -o pass driver.o

driver.o: driver.cpp helpers.h
	g++ -c driver.cpp

clean:
	rm *.o pass