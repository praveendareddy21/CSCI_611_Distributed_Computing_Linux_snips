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


vector<vector< char > > readMapFromFile(char * mapFile, int &golds){
  vector<vector< char > > mapVector;
  vector< char > temp;
  string line;
  char c;
  ifstream mapStream(mapFile);
  mapStream >>golds;
  mapStream.get(c);

  while(getline(mapStream,line))
  {
     for(int i=0; i < line.length(); i++){
       temp.push_back(line[i]);
     }
     mapVector.push_back(temp);
     temp.clear();
  }
  //cout<<"ve size "<<mapVector.size()<<" col "<<mapVector[0].size()<<endl;;
  return mapVector;
}


int main(){

  char * file_name = "mymap_test.txt";
  int fd1, golds;
  char buf [100];
  vector<vector< char > > mapVector =readMapFromFile(file_name, golds) ;

  cout<<"golds "<<golds<<endl;

  for(unsigned i=0;i<mapVector.size();i++){
    for(unsigned j=0;j<mapVector[i].size();j++){
      cout<<mapVector[i][j];
    }
    cout<<endl;
  }

  /*
  fd1 = open ( file_name, O_RDONLY );
  read ( fd1, buf, 100 );
  printf ( "read from fifo as :%s|", buf );
  close (fd1);
  */

	return 0;
}
