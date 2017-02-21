all:unnamed_pipe

unnamed_pipe: unnamed_pipe.cpp 
	g++ unnamed_pipe.cpp -lpthread -lrt

clean:
	rm -f unnamed_pipe
