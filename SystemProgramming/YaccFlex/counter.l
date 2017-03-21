    int char_count,word_count,line_count,space_count;
%%
[' '] word_count++; space_count++;
\n word_count++; line_count++; 
. char_count++;
%%
int yywrap(void) {
    return 1;
}

int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "r");
    yylex();
    printf("char count :: %d \n",char_count);
    printf("word count :: %d \n",word_count);
    printf("space count :: %d \n",space_count);
    printf("line count :: %d \n",line_count);
}