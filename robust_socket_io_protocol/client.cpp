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
#include"goldchase.h"
#include<iostream>
#include<string>

using namespace std;

int write_fd = -1;
int read_fd = -1;


int get_Write_Socket_fd(){
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

  printf("Connected to server.\n");
  return sockfd;

}

void send_Socket_Message(char PLR_MASK, string msg);
void send_Socket_Player(char PLR_MASK);
void send_Socket_Map(char PLR_MASK, string msg);


void send_Socket_Player(char PLR_MASK){

  char c=  'A'; //G_SOCKPLR | G_PLR0;
  WRITE<char>(write_fd, &c, 1);

  return;

}

void send_Socket_Message(char PLR_MASK, string msg){
  int msg_length = 0;
  char protocol_type = G_SOCKMSG;
  protocol_type &= PLR_MASK;

  char msg_cstring[100] = "Hello World!!";
  // = msg.c_str();
  msg_length = msg.size();
  printf("in client : msglen %d - msg - %s\n",msg_length, msg_cstring);

  WRITE <char>(write_fd, &protocol_type, sizeof(char));

  WRITE <int>(write_fd, &msg_length, sizeof(int));
  WRITE <char>(write_fd, msg_cstring, msg_length*sizeof(char));




}

void do_shit(){


}

int main()
{
  int write_fd = get_Write_Socket_fd();

  char protocol_type = ' ';

  while(1){
    if(write_fd != -1)
      break;
  }
do_shit();
char i, c=  'A'; //G_SOCKPLR | G_PLR0;
READ<char>(write_fd, &i, 1);
WRITE<char>(write_fd, &c, 1);

  //send_Socket_Player(protocol_type);

  //send_Socket_Message(protocol_type, "Hello World!!");

  printf("Exiting socket connection.\n");
  close(write_fd);
  return 1;








}
