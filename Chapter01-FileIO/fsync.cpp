#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    long fd;
    fd = open("./testText",O_WRONLY);
    int ret;
    
    ret = fsync(fd);
    if(ret==-1)
        perror("write");
    cout<<ret<<endl;
return 0;
}