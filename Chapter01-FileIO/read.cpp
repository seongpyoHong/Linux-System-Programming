#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;
int main(){
    long fd;
    long word;
    ssize_t nr;
    fd = open("./testText",O_RDONLY);
    nr=read(fd,&word,sizeof(long));
    cout<<"nr"<<nr<<endl;
    cout<<sizeof(long)<<endl;
    return 0;
}
/*
문제점 : 1.len byte만큼 모든 데이터를 읽지 못할 가능성
         2. 점검 후 처리 과정이 빠져있기 때문에 에러가 발생할 가능성 */