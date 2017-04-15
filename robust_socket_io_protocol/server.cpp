//Socket server
#include <sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h> //for read/write
#include<string.h> //for memset
#include<stdio.h> //for fprintf, stderr, etc.
#include<stdlib.h> //for exit
#include<errno.h>
#include"fancyRW.h"
#include"goldchase.h"
#include<iostream>
#include<string>

using namespace std;


int write_fd = -1;
int read_fd = -1;


void socket_Communication_Handler();
void process_Socket_Message(char protocol_type);
void process_Socket_Player(char protocol_type);
void process_Socket_Map(char protocol_type);

void process_Socket_Message(char protocol_type){

  int msg_length = 0;
  char msg_cstring[100];

  READ <int>(write_fd, &msg_length, sizeof(int));
  READ <char>(write_fd, msg_cstring, msg_length*sizeof(char));

  printf("in server : msglen %d - msg - %s\n",msg_length, msg_cstring);

}

void process_Socket_Player(char protocol_type){

}

void process_Socket_Map(char protocol_type){

}


int get_Read_Socket_fd(){
  int sockfd; //file descriptor for the socket
 int status; //for error checking


 //change this # between 2000-65k before using
 const char* portno="42424";
 struct addrinfo hints;
 memset(&hints, 0, sizeof(hints)); //zero out everything in structure
 hints.ai_family = AF_UNSPEC; //don't care. Either IPv4 or IPv6
 hints.ai_socktype=SOCK_STREAM; // TCP stream sockets
 hints.ai_flags=AI_PASSIVE; //file in the IP of the server for me

 struct addrinfo *servinfo;
 if((status=getaddrinfo(NULL, portno, &hints, &servinfo))==-1)
 {
   fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
   exit(1);
 }
 sockfd=socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

 /*avoid "Address already in use" error*/
 int yes=1;
 if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))==-1)
 {
   perror("setsockopt");
   exit(1);
 }

 //We need to "bind" the socket to the port number so that the kernel
 //can match an incoming packet on a port to the proper process
 if((status=bind(sockfd, servinfo->ai_addr, servinfo->ai_addrlen))==-1)
 {
   perror("bind");
   exit(1);
 }
 //when done, release dynamically allocated memory
 freeaddrinfo(servinfo);

 if(listen(sockfd,1)==-1)
 {
   perror("listen");
   exit(1);
 }

 printf("Blocking, waiting for client to connect\n");

 struct sockaddr_in client_addr;
 socklen_t clientSize=sizeof(client_addr);
 int new_sockfd;
 if((new_sockfd=accept(sockfd, (struct sockaddr*) &client_addr, &clientSize))==-1)
 {
   perror("accept");
   exit(1);
 }
 printf("Connected to client.\n");
 return new_sockfd;

}

void socket_Communication_Handler(){
  char protocol_type = ' ' ;

  printf("Attempted to read.\n");

  char c, i = 'I' ;

  WRITE<char>(read_fd, &i, 1);
  READ<char>(read_fd, &c, 1);

printf("Read in Server as c-%c.\n",c);

  if (protocol_type&G_SOCKPLR ){
    printf("read protocol_type - Socket_Player from client.\n");
    process_Socket_Player(protocol_type);

  }
  else if (protocol_type&G_SOCKMSG ){
    printf("read protocol_type - Socket_Message from client.\n");
    process_Socket_Message(protocol_type);

  }
  else if (protocol_type ){
    printf("read protocol_type - Socket_Map from client.\n");
    process_Socket_Map(protocol_type);

  }


  //}   //end of while



}

int main()
{
  read_fd = get_Read_Socket_fd();
  socket_Communication_Handler();

  printf("Exiting socket connection.\n");
  close(read_fd);
}
