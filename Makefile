CC = gcc
CXX = g++ -std=c++11
RM = rm -f

# INCLUDE BASE DIRECTORY AND BOOST DIRECTORY FOR HEADERS
LDFLAGS = -I/usr/local/Cellar/boost/1.66.0/include -I/opt/local/include

FLAGS = -L/usr/local/lib/ -lboost_system


result : client.o server.o utiltime.o sha256.o hash.o mining.o block.o main.o
	$(CXX) $(FLAGS) -o result client.o server.o utiltime.o sha256.o hash.o mining.o block.o main.o

server.o : src/udp/server.cpp
	$(CXX) -c -o server.o src/udp/server.cpp

client.o : src/udp/client.cpp
	$(CXX) -c -o client.o src/udp/client.cpp

utiltime.o : src/util/utiltime.cc
	$(CXX) -c -o utiltime.o src/util/utiltime.cc

sha256.o : src/crypto/sha256.cc
	$(CXX) -c -o sha256.o src/crypto/sha256.cc

hash.o : src/hash.cc
	$(CXX) -c -o hash.o src/hash.cc

mining.o : src/mining.cc
	$(CXX) -c -o mining.o src/mining.cc

block.o : src/block.cc
	$(CXX) $(LDFLAGS) -c -o block.o src/block.cc

main.o : src/main.cc
	 $(CXX) -c -o main.o src/main.cc

clean :
	$(RM) *.o result
