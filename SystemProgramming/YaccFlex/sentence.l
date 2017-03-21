conj for|and|but|nor|yet|so|or
space [" "]
%{
    int flag = 0;    
%}
%%
{space}{conj}{space}  { flag=1; }
.|\n       {}
%%
int yywrap() {
    return 1;
}
int main() {
    yylex();
    if(flag == 0)
        printf("Simple Sentence. \n");
    else
        printf("Compound Sentence. \n");
}