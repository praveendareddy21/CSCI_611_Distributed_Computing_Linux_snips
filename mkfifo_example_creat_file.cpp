// praveen dareddy   007380777ss
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <string>
#include <limits.h>
#include <sys/time.h>
#include <float.h>
#include<iostream>

#include<iostream>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;


int main(){

	pid_t parent_pid, child_pid;
	char * testMap ="***\n* *\n* *";

	char * file_name = "mymap_test.txt";

    mkfifo(file_name, S_IRUSR | S_IWUSR);
    int fd = open(file_name, O_WRONLY );

    write(fd, testMap, strlen(testMap));
    close(fd);


    unlink(file_name);
	cout<<"out";

	return 0;
}
