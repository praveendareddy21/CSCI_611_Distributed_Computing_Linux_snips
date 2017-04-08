all: client server

client: client.cpp
	g++ -o client client.cpp -lpthread -lrt

server: server.cpp
	g++ -o server server.cpp -lpthread -lrt
clean:
	rm -f client server
