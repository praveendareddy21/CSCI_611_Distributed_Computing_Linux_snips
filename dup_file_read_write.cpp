// praveen dareddy   007380777ss
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string>
#include <limits.h>
#include <sys/time.h>
#include <float.h>
#include<iostream>


using namespace std;


#define P2C_READ_END 0
#define P2C_WRITE_END 1

#define C2P_READ_END 0
#define C2P_WRITE_END 1


int main(){

	int p2c[2],c2p[2]; // file descriptors  for pipes

	pid_t parent_pid, child_pid;

	char  msg [] ="h";

	pipe(p2c);
	pipe(c2p);

	parent_pid = getpid();

	child_pid = fork();
	if(child_pid > 0 ){ // parent process
		cout<<"in parent process : parent pid :"<<parent_pid<<" child pid : "<<child_pid<<endl;

		// closing useless pipe ends
		close(p2c[P2C_READ_END]);
		close(c2p[C2P_WRITE_END]);

		//cin>>msg;
		//write(p2c[P2C_WRITE_END],"hello\0",6);

		dup2(p2c[P2C_WRITE_END], 0);



	}
	else{ // child process
		child_pid = getpid();
		cout<<"in child process : parent pid :"<<parent_pid<<" child pid : "<<child_pid<<endl;

		// closing useless pipe ends
		close(p2c[P2C_WRITE_END]);
		close(c2p[C2P_READ_END]);

		char msg2[6];

		read(p2c[P2C_READ_END],msg2,6);
		cout<<"message read in child as : "<<msg2;

	}


	if(getpid() == child_pid)
	{
		close(p2c[P2C_READ_END]);
		close(c2p[C2P_WRITE_END]);
		exit(0);
	}

	if(getpid() == parent_pid)
	{
		int status;
		close(p2c[P2C_WRITE_END]);
		close(c2p[C2P_READ_END]);
		if( wait(&status) )
		{

		}
		exit(0);
	}



	cout<<"out";

	return 0;
}
