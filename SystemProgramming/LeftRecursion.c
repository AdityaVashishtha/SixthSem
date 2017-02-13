#include<stdio.h>  
#include<string.h>  

int main () {  
       char nt;  
       char b;  
       char first[20];
       int num;  
       char p[10][20];  
       int index=3; 
       printf("Number of Production : \n");  
       scanf("%d",&num);  
       printf("Enter the grammar without space\n");  
       for(int i=0;i<num;i++){  
            scanf("%s",p[i]);  
       }  
       for(int i=0;i<num;i++){  
            printf("%s\n",p[i]);  
            nt=p[i][0];  
            if(nt==p[i][index]) {                   
                 first[index-3]=p[i][index+1];
                 printf("This Grammar is left recursive.\n");  
                 while(p[i][index]!=0 && p[i][index]!='|')  {
                     first[index-3]=p[i][index+1];
                     index++;                     
                 }                      
                 first[index-4]='\0';
                 if(p[i][index]!=0) {  
                     b=p[i][index+1];  
                      printf("After Removing Left recursion:\n");  
                      printf("%c->%c%c\'",nt,b,nt);  
                      printf("\n%c\'->%s%c\'|\u03B5\n",nt,first,nt);  
                 }  
                 //else  
                      //printf(" can't be reduced\n");  
            }  
            else  
                 printf("This Grammer is not left recursive.\n");  
            index=3;  
       }  
 }  