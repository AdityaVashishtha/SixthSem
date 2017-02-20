#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char p[10][20];
char resultFirst[10][20];
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

void attachToResult(char ch,char nt) {
    int i,flag=0;
    for(i=0;i<num;i++)
        if( p[i][0] == nt) 
            break;
    int index = i;     
    i=0;                   
    while(resultFirst[index][i] != 0) {
        if(resultFirst[index][i] == ch ) {
            flag=1;
            break;
        }            
        i++;
    }        
    if(flag ==0) {
        resultFirst[index][i]=ch;
        resultFirst[index][++i]='\0';
    }    
}

char * firstOf(char a[]) {    
    char nt,fch='\0'; 
    char * localresult;  
    char str[10]={""}; 
    int k=0;
    nt=a[0];
    int flag=0;
    int index = 3,i;
    EPS='\0';
    if(nt!=a[3]) {   
        while(a[index]!=0) {
            while(a[index]!='|') {
                int f = checkSmall(a[index]);
                if(f==1) {
                    //attachToResult(a[index],a[0]);                    
                    //printf("%c, ",a[index]);   
                    str[k++]=a[index];
                    strcat(localresult,str);
                    flag=1;                                                     
                    break;                    
                }
                else {
                    for(i=0;i<num;i++){
                        if( p[i][0] == a[index]) {
                                
                                //attachToResult(fch,a[0]);                              
                                strcat(str,firstOf(p[i]));
                                if(checkEps(p[i]))
                                    return '\0';
                                //attachToResult('#',a[0]);
                                fch = '#';                                                                
                                k = strlen(str)-1;
                                str[k++]=fch;
                                strcat(localresult,str);
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
    return localresult;
}

int main() {
    char nt;
    char b;
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
        printf("First(%s) ",p[i]);
        
        printf("%s \n",firstOf(p[i]));
        //puts("\n");
    }
}
