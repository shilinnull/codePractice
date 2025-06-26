.PHONY: all
all: Client Server

Client:Client.cc
	g++ -o Client Client.cc -std=c++17
Server:Server.cc
	g++ -o Server Server.cc -std=c++17

.PHONY: clean
clean:
	rm -f Client Server