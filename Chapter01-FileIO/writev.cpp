#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <sys/uio.h>
using namespace std;
int main(){
struct iovec iov[3];
ssize_t nr;
int fd;
char *buf[] = {
    "string 1\n","string 2\n","string 3\n"
};

fd = open ("writev_test.txt",O_WRONLY | O_TRUNC | O_CREAT);
if(fd ==-1){
    perror ("open");
    return 1;
}

//구조체에 값을 채운다.
for(int i=0;i<3;i++){
    iov[i].iov_base = buf[i];
    iov[i].iov_len = strlen(buf[i])+1;
}

//기존의 write와 다르게 writev는 한 번의 호출로 여러 string의 값을 파일에 쓸 수 있다.
nr = writev(fd,iov,3);
if(nr==-1){
    perror("writev");
    return 1;
}
//nr : 쓴 byte 수
printf ("wrote %d bytes\n",nr);
return 0;
}