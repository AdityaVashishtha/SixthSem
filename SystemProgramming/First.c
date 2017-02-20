#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char p[10][20];
char result[100];
int count=0;
int num;
char EPS='#';

int checkSmall(char a) {
    if (!(a>=65 && a <=90)) {
        return 1;
    }
    else if(a=='|'){
        return 0;
    }
     else {
        return 0;
    }
}

int checkEps(char a[]) {
    int i;
    for(i=0;i<strlen(a);i++){
        if(a[i]=='#')
            return 0;
    }
    return 1;
}


int firstOf(char a[]) {    
    char nt;    
    nt=a[0];
    int flag=0;
    int index = 3,i;
    EPS='\0';
    if(nt!=a[3]) {   
        while(a[index]!=0) {
            while(a[index]!='|') {
                int f = checkSmall(a[index]);
                if(f==1) {                    
                    //printf("%c ",a[index]);   
                    result[count++]=a[index];
                    flag=1;                                                     
                    break;                    
                }
                else {
                    for(i=0;i<num;i++){
                        if( p[i][0] == a[index]) {
                                firstOf(p[i]);
                                flag=1;                                
                                if(checkEps(p[i]))
                                    break;                                               
                                //printf("# ");   
                                result[count++]='#';                                          
                                continue;
                        }
                    }
                }
                index++;
            }
            if (flag==1)
            {
                while(a[index]!='|' && a[index]!=0) {
                    index++;
                }   
            }            
            flag=0;
            index++;
        }         
    } else {
        puts("Grammar is LEFT RECURSIVE\n");
    }    
    result[count]='\0';
  //  puts(result);
  //  puts("\n");
}

int main() {
    char nt;
    char b;
    char *r;
    char first[20];
    int index=3,i;
    printf("Number of Production : \n");
    scanf("%d",&num);
    printf("Enter the grammar without space\n");
    for(i=0;i<num;i++){
        scanf("%s",p[i]);
    }
    for(i=0;i<num;i++){
        EPS='\0';
        count=0;
        strcpy(result," ");
        printf("First(%s) ",p[i]);
        firstOf(p[i]);  
        puts(result)      ;
        puts("\n");
    }
}
