#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;
int main(){
    long fd;
    const char* buf ="it is pwrite";
    ssize_t count=75;
    ssize_t ret;
    fd = open("./preadTest.txt",O_WRONLY);
    ret = pwrite(fd,buf,count,10);
    cout<<buf<<endl;
    return 0;
}