#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;
int main(){
    long fd;
    char* buf;
    ssize_t count=10;
    ssize_t ret;
    fd = open("./preadTest.txt",O_RDONLY);
    ret = pread(fd,buf,count,40);
    cout<<buf<<endl;
    return 0;
}