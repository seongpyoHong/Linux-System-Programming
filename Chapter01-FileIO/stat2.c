/* 
    파일의 link 정보 확인
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

    ret = stat(argv[1],&sb);
    if(ret){
        perror("stat");
        return 1;
    }

    printf("FileType : ");
    switch (sb.st_mode & S_IFMT){
        case S_IFBLK : 
        printf("block device node\n");
        break;
        case S_IFCHR:
        printf("character device node\n");
        break;
        case S_IFDIR:
        printf("directory\n");
        break;
        case S_IFIFO :
        printf("FIFO\n");
        break;
        default:
            printf("unknown\n");
            break;
    }
    return 0;
}