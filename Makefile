CC = gcc
CXX = g++
RM = rm -f

# INCLUDE BASE DIRECTORY AND BOOST DIRECTORY FOR HEADERS
LDFLAGS = -I/usr/local/Cellar/boost/1.66.0/include -I/opt/local/include

# INCLUDE BASE DIRECTORY AND BOOST DIRECTORY FOR LIB FILES
LLIBFLAGS = -L/usr/local/Cellar/boost/1.66.0/

# SPECIFIY LINK OPTIONS
LINKFLAGS = -llibboost_date_time

result : utiltime.o sha256.o hash.o mining.o block.o main.o
	$(CXX) -o result utiltime.o sha256.o hash.o mining.o block.o main.o

utiltime.o : utiltime.cc
	$(CXX) -c -o utiltime.o utiltime.cc

sha256.o : crypto/sha256.cc
	$(CXX) -c -o sha256.o crypto/sha256.cc

hash.o : hash.cc
	$(CXX) -c -o hash.o hash.cc

mining.o : mining.cc
	$(CXX) -c -o mining.o mining.cc

block.o : block.cc
	$(CXX) $(LDFLAGS) $(LLIBFLAGS) $(LINKFLAGS) -c -o block.o block.cc

main.o : main.cc
	 $(CXX) -c -o main.o main.cc

clean : 
	$(RM) *.o result
