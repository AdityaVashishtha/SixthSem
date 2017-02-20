#include<stdio.h>
#include<string.h>

int main () {
       char nt;
       char b;
       char first[20];
       int num;
       char p[10][20];
       int index=3,i;
       printf("Number of Production : \n");
       scanf("%d",&num);
       printf("Enter the grammar without space\n");
       for(i=0;i<num;i++){
            scanf("%s",p[i]);
       }
       for(i=0;i<num;i++){
            printf("%s\n",p[i]);
            nt=p[i][0];
            //printf("%d\n",nt);
            if (!(nt>=65 && nt <=90)) {
                printf("This grammar is not left recursive since non-terminal is not Capital.\n");
                continue;
            }
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
                      printf("\n%c\'->%s%c\'|epsilon\n",nt,first,nt);
                 }
            }
            else
                 printf("This Grammar is not left recursive.\n");
            index=3;
       }
 }
