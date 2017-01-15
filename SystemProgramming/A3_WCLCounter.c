#include <stdio.h>
#include <string.h>

void fromfile() {
	FILE *f;
	int line_count=0, word_count=0, character_count=0;
 	char filename[20];
    int ch;
    printf("Enter filename:\n");
    scanf("%s", filename);
    f = fopen(filename,"r");
    if(f){
        while((ch=getc(f))!=EOF){
            if (ch!=' ' && ch!='\n')
                character_count++;
            if(ch==' ' || ch=='\n')
                word_count++;
            if (ch=='\n')
                line_count++;
        }
        if(character_count>0) { //for single letter word and line
            line_count++;
            word_count++;
        }
    }
    else {
            printf("Invalid File\n");
    }
    printf("Number of Characters: %d\n",character_count);
    printf("Number of Words: %d\n",word_count-1);
    printf("Number of Lines: %d\n",line_count-1);    
    fclose(f);
}

void fromterminal() {
    char inputtext[100];
	int size,i;    
    int line_count=0, word_count=0, character_count=0;
    printf("Enter text (enter tab key to end):\n");
    scanf("%[^\t]",inputtext);
    printf("%s",inputtext);
    size=strlen(inputtext)-1;
    for(i=0;i<size;i++){
        if (inputtext[i]!=' ' && inputtext[i]!='\n')
            character_count++;
        if(inputtext[i]==' ' || inputtext[i]=='\n')
            word_count++;
        if (inputtext[i]=='\n') 
            line_count++;
    }
    if(character_count>0) { //for single letter word and line
            line_count++;
            word_count++;
    }
    printf("Number of Characters: %d\n",character_count+1);
    printf("Number of Words: %d\n",word_count-1);
    printf("Number of Lines: %d\n",line_count-1); 
}

int main()
{
	int ch;    
	printf("Enter your choice,\n");
	printf("1. Take input from file\n");
    printf("2. Input from terminal\n");
	scanf("%d",&ch); 	
    switch(ch){
        case 1: fromfile();
                break;
        case 2:	fromterminal();
                break;							
        default: printf("Wrong Choice!\n");
                break;
    }	   
}
