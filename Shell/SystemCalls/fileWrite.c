#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFMAX 1000

int main() {
    char to_file[100];
    printf("Enter the filename to read from ::\n");
    scanf("%s",to_file);
    printf("Enter content to write to file \n");
    char buf[BUFMAX];
    scanf("%[^\t]",buf);
    int fd_to;
    fd_to=open(to_file,O_RDWR|O_CREAT|O_TRUNC);    
    write(fd_to,buf,strlen(buf));
}