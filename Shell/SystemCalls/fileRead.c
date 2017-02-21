#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFMAX 1000


int main() {
    char from_file[100];
    printf("Enter the filename to read from ::\n");
    scanf("%s",from_file);
    int fd_from = open(from_file,O_RDONLY);
    char buf[BUFMAX];
    size_t size;
    while(size = read(fd_from,buf,BUFMAX))
        puts(buf);
    close(fd_from);
}
