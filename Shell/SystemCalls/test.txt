#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    char a[10];
    printf("$$");
    scanf("%[^\t]s",a);
    char path[20] = "/bin/";
    strcat(path,a);
    execl(path,a,0);
}