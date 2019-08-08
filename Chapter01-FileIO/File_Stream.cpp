#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main(){
    FILE *in,*out;
    struct pirate{
        char name[100];
        unsigned long booty;
        unsigned int beard_len;
    }p, blackbeard = {"Edward Teach",950,48};

    out = fopen("/Users/seongpyo/Desktop/SystemProgramming/test.txt","w");
    if(!out){
        perror("fopen");
        return 1;
    }

    if(!fwrite (&blackbeard, sizeof (struct pirate),1,out)){
        perror("fwrite");
        return 1;
    }
    if(fclose(out)){
        perror("fclose");
        return 1;
    }
    in = fopen("/Users/seongpyo/Desktop/SystemProgramming/test.txt","r");
    if(!in){
        perror ("fopen");
        return 1;
    }

    if(!fread(&p,sizeof(struct pirate),1,in)){
        perror("fread");
        return 1;
    }

    if(fclose(in)){
        perror("fclose");
        return 1;
    }

    printf("name=\"%s\" booty=%lu beard_len=%u\n",p.name,p.booty,p.beard_len);

    return 0;
}