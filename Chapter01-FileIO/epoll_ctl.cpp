/*select와 poll은 실행마다 전체 file descriptor를 요구한다. 
이는 fd 리스트의 크기가 커지면 병목현상이 발생한다.
epoll은 검사할 fd를 등록하는 부분을 분리하여 병목현상을 회피한다.
*/
//epoll isn't supported in osx
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/epoll.h>
using namespace std;
int main(){
    struct epoll_event event;
    int ret;

    //나중에 반활될 fd
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLOUT;

    ret = epoll_ctl (edfd,EPOLL_CTL_ADD,fd,&event);
    if (ret)
    perror("epoll_ctl");
}