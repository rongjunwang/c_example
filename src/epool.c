#include <stdio.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char** argv){

  int port = atoi(argv[1]);
  int lfd = socket(AF_INET, SOCK_STREAM, 0);
  printf("%s\n", argv[1]);
  printf("%d\n", getpid());
  
  while(1){

  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  if( 0 > bind(lfd, (struct sockaddr*)&addr, sizeof(addr)) ){
    printf("%s\n","bind error");
  }
  listen(lfd, 5);

  int efd = epoll_create(10);

  struct epoll_event re;
  re.events = EPOLLIN;
  re.data.fd = lfd;

  epoll_ctl(efd, EPOLL_CTL_ADD, lfd, &re);

  struct epoll_event events[100];

  while(1){
    int ret = epoll_wait(efd, events, 100, -1);
    printf("======================wait=======\n");
    if(ret == -1){
      perror("epoll_wait");
      exit(1);
    }

    for(int i = 0; i < ret; ++i){
      if(events[i].data.fd == lfd){
        int cfd = accept(lfd, NULL, NULL);

        int flags = fcntl(cfd, F_GETFL);
        flags |= O_NONBLOCK;
        fcntl(cfd, F_SETFL, flags);
    
        struct epoll_event re;
        re.events = EPOLLIN | EPOLLET;
        re.data.fd = cfd;
        epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &re);
        break;
      }
      char buf[3];

      int ret;
      while((ret = recv(events[i].data.fd, buf, sizeof buf, 0)) > 0){
        write(STDOUT_FILENO, buf, ret);
      }

      char sendbuf[] = "hello";
      send(events[i].data.fd, sendbuf, sizeof sendbuf, 0);
      
      if(ret == 0){
        epoll_ctl(efd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
        close(events[i].data.fd);
        printf("client disconnetn");
      }
      else if(ret == -1 && errno == EAGAIN){
        printf("read overn");  
      }
    }
  }
}