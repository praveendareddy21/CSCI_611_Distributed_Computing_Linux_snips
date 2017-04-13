//Socket client
#include <sys/types.h>
#include<sys/socket.h>
#include<unistd.h> //for read/write
#include<netdb.h>
#include<string.h> //for memset
#include<stdio.h> //for fprintf, stderr, etc.
#include<stdlib.h> //for exit
#include<errno.h>
#include"fancyRW.h"



int main()
{
  int sockfd; //file descriptor for the socket
  int status; //for error checking

  //change this # between 2000-65k before using
  const char* portno="42424";

  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints)); //zero out everything in structure
  hints.ai_family = AF_UNSPEC; //don't care. Either IPv4 or IPv6
  hints.ai_socktype=SOCK_STREAM; // TCP stream sockets

  struct addrinfo *servinfo;
  //instead of "localhost", it could by any domain name
  if((status=getaddrinfo("localhost", portno, &hints, &servinfo))==-1)
  {
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    exit(1);
  }
  sockfd=socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

  if((status=connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen))==-1)
  {
    perror("connect");
    exit(1);
  }
  //release the information allocated by getaddrinfo()
  freeaddrinfo(servinfo);

  const char* message="One small step for (a) man, one large  leap for Mankind";
  int rows,cols;
  char initial_map[2010];

  READ<int>(sockfd, &rows, sizeof(int));
  READ<int>(sockfd, &cols, sizeof(int));
  printf("reading from server done. rows - %d cols - %d\n", rows,cols);

  READ<char>(sockfd, initial_map, (rows*cols + 1)*sizeof(char));

  printf("reading from server done map - %s\n", initial_map);
  close(sockfd);
  return 0;


  /*if((n=write(sockfd, message, strlen(message)))==-1)
  {
    perror("write");
    exit(1);
  }*/
  WRITE<char>(sockfd, "ToddGibson", 11);

  printf("client wrote %d characters\n", 11);

  int server_num;
  READ<int>(sockfd, &server_num, sizeof(int));


  printf("number from server is %d\n", server_num);
  close(sockfd);
  return 0;
}
