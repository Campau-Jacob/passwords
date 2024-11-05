pass: driver.o
	g++ -o pass driver.o -lssl -lcrypto

driver.o: driver.cpp
	g++ -c driver.cpp

clean:
	rm *.o pass