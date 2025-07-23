all: client server

client: Client.cc
	g++ -o $@ $^ -std=c++17 -ljsoncpp

server: Server.cc
	g++ -o $@ $^ -std=c++17 -ljsoncpp
.PHONY:clean
clean:
	rm -f server client