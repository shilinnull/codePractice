all:reactor_server client

reactor_server:Main.cc
	g++ -o $@ $^ -std=c++17 -ljsoncpp

client:Client.cc
	g++ -o $@ $^ -std=c++17 -ljsoncpp

.PHONY:clean
clean:
	rm -f reactor_server client