#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    long fd;
    fd = open("./testText",O_WRONLY);
    const char* buf = "My ship is solid!";
    ssize_t nr;
    /*buf에 들어있는 문자열을 'fd'에 기록 */
    nr = write(fd,buf,strlen(buf));
    if(nr==-1)
        perror("write");
}