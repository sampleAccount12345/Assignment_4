#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <ctime>
#define MAXLINE 4096 /*max text line length*/
#define SERV_PORT 80 /*port*/
#define LISTENQ 8 /*maximum number of client connections*/
using namespace std;
int main (int argc, char **argv)
{
 int listenfd, connfd, n;
 pid_t childpid;
 socklen_t clilen;
 char buf[MAXLINE];
 struct sockaddr_in cliaddr, servaddr;
   alarm(300);

 //Create a socket for the socket
 //If sockfd<0 there was an error in the creation of the socket
 if ((listenfd = socket (AF_INET, SOCK_STREAM, 0)) <0) {
  	perror("Problem in creating the socket");
  	exit(2);
 }

 //preparation of the socket address
 servaddr.sin_family = AF_INET;
 servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
 servaddr.sin_port = htons(atoi(argv[1]));

 //bind the socket
 bind (listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

 //listen to the socket by creating a connection queue, then wait for clients
 listen (listenfd, LISTENQ);

 printf("%s\n","Server running...waiting for connections.");
ofstream moifile;
   
    char *wengerball;
    wengerball = argv[4];
    moifile.open(argv[4]);
 for ( ; ; ) {
  clilen = sizeof(cliaddr);
  //accept a connection

  connfd = accept (listenfd, (struct sockaddr *) &cliaddr, &clilen);
  printf("%s\n","Received request...");

  if ( (childpid = fork ()) == 0 ) {	//if itâ€™s 0, itâ€™s child process
    	printf ("%s\n","Child created for dealing with client requests");
    	//close listening socket
    	close (listenfd);
time_t now = time(0);
        	char* dt = ctime(&now);
    	while ( (n = recv(connfd, buf, MAXLINE,0)) > 0)  {
      printf("My process ID : %d\n", getpid());
      cout << "The local date and time is: " << dt << endl;
     	printf("%s","String received from and resent to the client:");
     	puts(buf);
      char buf2[MAXLINE];
      strcpy(buf2, buf);
    
      system(buf);
      memset(buf, 0, 255);
     	send(connfd, buf, n, 0);
      /*
      
      */
     }
     if (n < 0)
      	printf("%s\n", "Read error");
     exit(0);
  }
  moifile.close();
  //close socket of the server
  close(connfd);
 }
}



