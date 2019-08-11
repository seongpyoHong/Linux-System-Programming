#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <sys/uio.h>
using namespace std;
int main(){
    char foo[10],bar[10],baz[10];
    struct iovec iov[3];
    ssize_t nr;
    int fd;

    fd = open("writev_test.txt",O_RDONLY);
    if(fd==-1)
    {
        perror("open");
        return 1;
    }

    //iov 구조체 초기화
    iov[0].iov_base = foo;
    iov[0].iov_len = sizeof(foo);
    iov[1].iov_base = bar;
    iov[1].iov_len = sizeof(bar);
    iov[2].iov_base = baz;
    iov[2].iov_len = sizeof(baz);

    //기존의 read와는 달리 readv는 한 번의 호출로 여러개의 문자열을 읽을 수 있다.
    nr = readv(fd,iov,3);
    if (nr ==-1)
    {
        perror("readv");
        return 1;
    }

    for(int i=0;i<3;i++){
        printf("%d : %s",i,(char*) iov[i].iov_base);
    }
    return 0;
}