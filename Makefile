all:unnamed_pipe simple_fork_example


simple_fork_example: simple_fork_example.cpp 
	g++ -o simple_fork_example  simple_fork_example.cpp -lpthread -lrt 
	
unnamed_pipe: unnamed_pipe.cpp 
	g++ -o unnamed_pipe unnamed_pipe.cpp -lpthread -lrt

clean:
	rm -f unnamed_pipe simple_fork_example
