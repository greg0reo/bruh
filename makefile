all: predictors

predictors: driver.o work.o
	g++ driver.o work.o -o predictors

driver.o: driver.cpp
	g++ -g -c driver.cpp

work.o: work.cpp work.h
	g++ -g -c work.cpp

clean:
	rm -f *.o driver
