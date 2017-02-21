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


int main(){

	pid_t parent_pid, child_pid;

	parent_pid = getpid();

	child_pid = fork();
	if(child_pid > 0 ){ // parent process

		cout<<"in parent process : parent pid :"<<parent_pid<<" child pid : "<<child_pid<<endl;

	}
	else{ // child process
		child_pid = getpid();
		cout<<"in child process : parent pid :"<<parent_pid<<" child pid : "<<child_pid<<endl;

	}


	cout<<"out";

	return 0;
}
