/*
    파일 크기 확인
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char *argv[]){
    struct stat sb;
    int ret;

    if (argc <2){
        fprintf (stderr,
                "usage : %s <file>\n", argv[0]);
                return 1;
    }

    ret = stat (argv[1],&sb);
    if(ret){
        perror ("stat");
        return 1;
    }

    printf( "%s is %lld bytes\n",argv[1],sb.st_size);
    return 0;
}