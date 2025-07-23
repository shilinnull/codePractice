all: server client

server: Server.cc
	g++ -o server Server.cc -lpthread -std=c++17
client: Client.cc
	g++ -o client Client.cc -lpthread -std=c++17

.PHONY:clean
clean:
	rm -f server client