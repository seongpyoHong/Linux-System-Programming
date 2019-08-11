#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
int main(int argc, char *argv[]){
    struct stat sb;
    off_t len;
    char *p;
    int fd;

    if(argc<2){
        fprintf(stderr,"usage : %s <file>\n",argv[0]);
        return 1;
    }
    //파일 열기
     fd = open(argv[1],O_RDONLY);
     if(fd==-1){
         perror("open");
         return 1;
     }
     //파일의 정보를 가져온다.
     if (fstat(fd,&sb)==-1){
         perror("fstat");
         return 1;
     }
     //파일이 디렉토리인지 디바이스 파일인지 일반 파일인지 검사
     if(!S_ISREG(sb.st_mode)){
        fprintf(stderr,"%s is not a file\n",argv[1]);
     }
     //mapping
     p= mmap(0,sb.st_size,PROT_READ,MAP_SHARED,fd,0);

    //mapping이 실패했을 경우
     if(p==MAP_FAILED){
         perror("mmap");
         return 1;
     }
     
     //파일 닫기
     if(close (fd) ==-1){
         perror("close");
         return 1;
     }

    //fd를 닫은 후에도 mapping 되어있기 때문에 접근 가능
     for(len =0;len<sb.st_size;len++){
         putchar (p[len]);
     }

    //파일 매핑 해제
     if(munmap(p,sb.st_size)==-1){
         perror("munmap");
         return 1;
     }
     return 1;
}