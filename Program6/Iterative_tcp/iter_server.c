#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include <arpa/inet.h>

void str_echo(int connfd)
{
      int n;
      int bufsize = 1024;
      char *buffer = malloc(bufsize);
	//printf("inside the function");
  again: while((n=recv(connfd, buffer, bufsize, 0))>0)	
	     send(connfd,buffer,n,0);
             //printf("%d n",n);
	 if(n<0)
            goto again;
	
}
int main()
{
  int cont,listenfd,connfd,addrlen,fd,pid;
  
  //char fname[256];
  struct sockaddr_in address;
  if ((listenfd = socket(AF_INET,SOCK_STREAM,0)) > 0) //sockfd
    printf("The socket was created\n");
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(15001);
    if (bind(listenfd,(struct sockaddr *)&address,sizeof(address)) == 0)
    printf("Binding Socket\n");
    listen(listenfd,3);
     printf("server is listening\n");
for(;;){
    addrlen = sizeof(struct sockaddr_in);
    connfd = accept(listenfd,(struct sockaddr *)&address,&addrlen);
    if (connfd > 0)
    {
            printf("The Client %s is Connected...\n",
            inet_ntoa(address.sin_addr) );
    }
     
	   str_echo(connfd);
	      
    close(connfd);}
    return 0 ;
}
