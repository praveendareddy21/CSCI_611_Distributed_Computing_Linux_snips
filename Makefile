all:unnamed_pipe simple_fork_example dup_file_read_write dup2_ls_to_file_output mkfifo_example_creat_file


simple_fork_example: simple_fork_example.cpp 
	g++ -o simple_fork_example  simple_fork_example.cpp -lpthread -lrt 
	
unnamed_pipe: unnamed_pipe.cpp 
	g++ -o unnamed_pipe unnamed_pipe.cpp -lpthread -lrt

dup_file_read_write: unnamed_pipe.cpp 
	g++ -o dup_file_read_write dup_file_read_write.cpp -lpthread -lrt

dup2_ls_to_file_output: dup2_ls_to_file_output.cpp 
	g++ -o dup2_ls_to_file_output dup2_ls_to_file_output.cpp -lpthread -lrt
	


mkfifo_example_creat_file: mkfifo_example_creat_file.cpp 
	g++ -o mkfifo_example_creat_file mkfifo_example_creat_file.cpp -lpthread -lrt

clean:
	rm -f unnamed_pipe simple_fork_example dup_file_read_write dup2_ls_to_file_output mkfifo_example_creat_file
