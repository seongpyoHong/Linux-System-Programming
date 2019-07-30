/*
현재 파일 offset에서 len byte만큼 fd에서 읽어 word에 기록
모든 len byte를 읽거나, EOF에 도달할 때까지 루프 수행
0보다 크지만 len보다 작게 읽었을 경우, len에서 읽은 바이트만큼 빼고 다시 수행
error가 -1이지만 errno이 ENITR일 경우에도 다시 수행
ENITR이 아닌 경우, perror로 표준 에러 출력 
 */
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;
int main(){
    long fd;
    long word;
    ssize_t len=8;
    ssize_t ret;
    fd = open("./testText",O_RDONLY);

    while (len != 0 && (ret = read(fd,&word,len)) != 0){
        if(ret == -1){
            if (errno == EINTR)
                continue;
            cout<<"read"<<endl;
            break;
        }

        len -= ret;
        word += ret;
    }
}