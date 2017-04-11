#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>

int getRAM() {
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if(meminfo == NULL)
        printf("ERROR OCCURED\n");

    char line[256];
    while(fgets(line, sizeof(line), meminfo))
    {
        int ram,freeRam,cache;
        if(sscanf(line, "MemTotal: %d kB", &ram) == 1) {            
            printf("Total Ram: %d\n",ram);            
        }         
        if(sscanf(line, "MemFree: %d kB", &freeRam) == 1) {            
            printf("Free Ram: %d\n",freeRam);            
        }
        if(sscanf(line, "Cached: %d kB", &cache) == 1) {            
            printf("Cache: %d\n",cache);            
        }        
    }

    // If we got here, then we couldn't find the proper line in the meminfo file:
    // do something appropriate like return an error code, throw an exception, etc.
    fclose(meminfo);
    return -1;
}

void printPath(char *pid) {
    char path[256]="\0";
    //strcpy(path,);    
    char *linkpath;
    strcpy(linkpath,"/proc/");
    strcat(linkpath,pid);
    strcat(linkpath,"/exe");
    readlink(linkpath, path, sizeof(path));
    printf("PATH(%s):: %s\n",pid,path);    
}

int printDE(const char *p) {    
    //strcpy(path,);        
    char Mpath[256];
    strcpy(Mpath,"/proc/");    
    strcat(Mpath,p);    
    strcat(Mpath,"/statm");    
    FILE *prinfo = fopen(Mpath, "r");    
    if(prinfo == NULL)
        printf("ERROR OCCURED\n");

    char line[256];
    int ram, residentRam,temp,dirty,shared;
    fscanf(prinfo, "%d %d %d %d %d %d %d",&ram,&residentRam,&shared,&temp,&temp,&temp,&dirty)  ;  
    printf("RAM Size:: %d\n",ram);
    printf("Resident in RAM:: %d\n",residentRam);
    printf("Shared Pages:: %d\n",shared);
    printf("Dirty Page:: %d\n",dirty);
    // If we got here, then we couldn't find the proper line in the meminfo file:
    // do something appropriate like return an error code, throw an exception, etc.
    fclose(prinfo);
    return -1;
}

int cpuInfo() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
    if(cpuinfo == NULL)
        printf("ERROR OCCURED\n");

    char line[256];
    int i=0;
    while(fgets(line, sizeof(line), cpuinfo))
    {        
        float ram;
        if(sscanf(line, "cpu MHz : %f kB", &ram) == 1) {            
            printf("CPU Clock Freq Core(%d):: %f\n",++i,ram);            
        }              
    }

    // If we got here, then we couldn't find the proper line in the meminfo file:
    // do something appropriate like return an error code, throw an exception, etc.
    fclose(cpuinfo);
    return -1;
}
int uptime() {
    FILE *uptimeinfo = fopen("/proc/uptime", "r");
    if(uptimeinfo == NULL)
        printf("ERROR OCCURED\n");

    char line[256];    
    float up,a;
    fscanf(uptimeinfo, "%f %f",&up,&a)  ;  
    printf("System Up time:: %f sec\n",up);
    printf("System Idle time:: %f sec\n",a);
    // If we got here, then we couldn't find the proper line in the meminfo file:
    // do something appropriate like return an error code, throw an exception, etc.
    fclose(uptimeinfo);
    return -1;
}

void showTemp() {
    int status = system("sensors");
}

int main() {        
    int s=187;
    char *pid;
    while(s!=0) {
        printf("\n-------------------------------------------------\n");
        printf("\tPlease select from MENU exit(0)\n");
        printf("-------------------------------------------------\n");
        printf("\t1. Show RAM details \n");
        printf("\t2. Print details from PID \n");
        printf("\t3. Show CPU info \n");
        printf("\t4. System UPtime \n");
        printf("\t5. Print path of program from pid \n");
        printf("\t6. Temprature of CPU \n");
        printf("-------------------------------------------------\n");
        scanf("%d",&s);
        switch(s) {
            case 1: getRAM(); ;
            break;
            case 2: scanf("%s",pid); 
                    printDE(pid);
            break;
            case 3: cpuInfo();            
            break;
            case 4: uptime();
            break;            
            case 6: showTemp();
            break;
            case 5: scanf("%s",pid); 
                    printPath(pid);
            break;
            case 0: break;
            default: printf("INVALID OPTION \n");
        }
    }           
    //printDE("2607");
    // cpuInfo();    
    // uptime();
    //printPath("2607");
    
    return 0;
}