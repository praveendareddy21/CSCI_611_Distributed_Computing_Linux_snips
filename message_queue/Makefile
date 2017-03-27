all: read_queue write_queue

read_queue: read_queue.cpp
	g++ -o read_queue read_queue.cpp -lpthread -lrt

write_queue: write_queue.cpp
	g++ -o write_queue write_queue.cpp -lpthread -lrt
clean:
	rm -f read_queue write_queue
