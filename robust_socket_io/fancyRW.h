/*
 * write template functions that are guaranteed to read and write the
 * number of bytes desired
 */

#ifndef fancyRW_h
#define fancyRW_h

#include <sys/types.h>
#include<sys/socket.h>
#include<unistd.h> //for read/write
#include<netdb.h>
#include<string.h> //for memset
#include<stdio.h> //for fprintf, stderr, etc.
#include<stdlib.h> //for exit
#include<errno.h>

template<typename T>
int READ(int fd, T* obj_ptr, int count)
{
  char* addr=(char*)obj_ptr;
  //loop. Read repeatedly until count bytes are read in
}

template<typename T>
int WRITE(int fd, T* obj_ptr, int count)
{
  char* addr=(char*)obj_ptr;
  //loop. Write repeatedly until count bytes are written out
}
#endif

//Example of a method for testing your functions shown here:
//opened/connected/etc to a socket with fd=7
//
/*

int count=write(7, "Todd Gibson", 11);
cout << count << endl;//will display a number between 1 and 11
int count=write(7, "d Gibson", 8);
//
//How to test your READ template. Read will be: READ(7, ptr, 11);
write(7, "To", 2);
write(7, "DD ", 3);
write(7, "Gibso", 5);
write(7, "n", 1);


*/
//
//
