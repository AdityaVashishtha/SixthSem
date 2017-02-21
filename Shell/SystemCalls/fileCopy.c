#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFMAX 4096

int main() {
    char to_file[100],from_file[100];
    printf("Enter the filename to read from ::\n");
    scanf("%s",from_file);
    printf("Enter the filename to write to ::\n");
    scanf("%s",to_file);
    printf("Enter content to write to file \n");
    char buf[BUFMAX];
    int fd_to,fd_from;
    fd_from = open(from_file,O_RDONLY);    
    fd_to=open(to_file,O_WRONLY|O_CREAT|O_TRUNC);    
    size_t size;
    while( size = read(fd_from,buf,BUFMAX)) {       
        write(fd_to,buf,strlen(buf));            
    }    
}