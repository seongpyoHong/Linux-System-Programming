#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;
int main(){
    long fd;
    int ret;
    fd = open("./preadTest.txt",O_RDWR);
    ret = ftruncate(fd,10);
    return 0;
}