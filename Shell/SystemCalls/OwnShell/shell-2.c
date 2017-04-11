#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<signal.h>

#define start "\e[92m"
#define end "\x1b[0m"


void quit(){
  printf("Process Killed. Exiting!!\n");
  exit(0);
}
int main() {
	while(1) {

			char str[80] = "";
			printf(start ">" end);
			//scanf("%s",str);
			gets(str);
			if(strcmp(str,"exit") == 0) {
				//printf("Not equal");
				break;
			}
			//const char s[2] = " ";
			char *token,*tokens[10],*tokens2[10];
			char *outFile = NULL, *inFile = NULL;
			int i=0,k=0;
			token = strtok(str," ");
			int outputR = 0;
			int inputR = 0;
			int fd,flag=0,bp=0;

			while( token != NULL ) 
			{				
				// printf( "%s\n", token );  
				if(strcmp(token,"|")==0){
					tokens[i]=NULL;
					flag=1;					
				}
				else if(outputR == 1 ) {
					outFile = token;
					outputR = 0;
				}
				else if(strcmp(token,">") == 0) {
					outputR = 1;
				} 
				else if(inputR == 1 ) {
					inFile = token;
					inputR = 0;
				}
				else if(strcmp(token,"<") == 0) {
					inputR = 1;
				} 				
				else {
					if(flag==0)
					tokens[i++] = token;
					if(flag==1)
					tokens2[k++]=token;					
				}
				token = strtok(NULL," ");      
			}
			
			if(flag==1){
				tokens2[k]=NULL;
				//printf("%s %s",tokens[0],tokens2[0]);
				int j=fork();
				if(j==0){
					int fd[2];
					pipe(fd);
					int l=fork();
					
					if(l==0){
						close(fd[0]);
						int save_out = dup(fileno(stdout));			
						dup2(fd[1], fileno(stdout));
						close(fd[1]);
						execvp(tokens[0],tokens);														
					}
					else{
						close(fd[1]);
						int save_in = dup(fileno(stdin));			
						dup2(fd[0], fileno(stdin));
						close(fd[0]);
						execvp(tokens2[0],tokens2);
					}
				}
				else{
					wait();
				}
				flag=0;
			}
			// printf("%s",outFile);
			else if(outFile != NULL) {
				int out = open(outFile, O_RDWR|O_CREAT|O_APPEND, 0777);
				if (-1 == out) { perror("opening File error"); return 255; }				

				int save_out = dup(fileno(stdout));				

				if (-1 == dup2(out, fileno(stdout))) { perror("cannot redirect stdout"); return 255; }				

				int j=0;
				int id = fork();   
				if(id==0) {	   			   		
						
						tokens[i]=NULL;	   		
						execvp(tokens[0],tokens);
				} else {
						wait();
				}	

				fflush(stdout); close(out);				
				dup2(save_out, fileno(stdout));				
				close(save_out);				
			}

			else if(inFile != NULL) {
				int in = open(inFile, O_RDWR|O_CREAT|O_APPEND, 0777);
				if(-1 == in) { perror("opening File error"); return 255; }				
				
				int read_from = dup(fileno(stdin));
				if (-1 == dup2(in, fileno(stdin))) { perror("cannot redirect stdin"); return 255; }				

				int j=0;
				int id = fork();   
				if(id==0) {	   			   		
						// char cmd[100] = "/usr/bin/";
						// strcat(cmd,tokens[0]);
						tokens[i]=NULL;	   		
						execvp(tokens[0],tokens);
				} else {
						wait();
				}	

				fflush(stdout); close(in);				
				dup2(read_from, fileno(stdin));				
				close(read_from);
				
			}

			// execvp(tokens[0]);	   
			else
				{
				int j=0;
				int id = fork(); 
				if(strcmp(tokens[i-1],"&")==0){
					tokens[i-1]=NULL;
					bp=1;
				}
				else{
					tokens[i]=NULL;	   		
				}
				
				if(id==0) {	   						
						execvp(tokens[0],tokens);
				} else {
						if(bp==0){							
							wait();							
						}
						else{
							printf("Process sent in background\n");
						}						
				}	
			}
			signal(SIGINT,quit);
			signal(SIGQUIT,quit);
			
	}
	
}
