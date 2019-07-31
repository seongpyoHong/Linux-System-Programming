#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;
int main(){
    int fd;
    fd = open("./testText",O_RDWR);
    if(fd==-1)
        perror("open");
    int offset;
    //fd의 offset을 현재 파일의 끝으로 설정
    offset = lseek(fd,0,SEEK_END);
    if(offset == (off_t)-1)
        perror("lseek");
    else 
        cout<<offset<<endl;
    return 0;
}