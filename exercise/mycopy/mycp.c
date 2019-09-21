#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char *buf[1024];
    int fd_origin;
    int fd_copy;
    ssize_t r_byte;
    ssize_t w_byte;
    //both file open
    fd_origin = open(argv[1], O_RDONLY);
    fd_copy = open(argv[2], O_WRONLY);
    if (fd_origin == -1 || fd_copy == -1)
    {
        perror("open");
        return 0;
    }
    //read origin file
    r_byte = read(fd_origin, buf, 1024);
    if (r_byte == -1)
        perror("read");
    //check intermediate buffer
    printf("Intermediate Buffer: %s\n", &buf);
    //write to new file
    w_byte = write(fd_copy, buf, r_byte);
    if (w_byte == -1)
        perror("write");

    //close all file descriptor
    close(fd_origin);
    close(fd_copy);

    return 0;
}
