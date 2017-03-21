%{
    int comment_count;
%}
%s C_COMMENT
%s C_SINGLE_COMMENT
%%
"//"                    { BEGIN(C_SINGLE_COMMENT); }
<C_SINGLE_COMMENT>.     { }
<C_SINGLE_COMMENT>\n    {++comment_count; BEGIN(INITIAL);}
"/*"                    { BEGIN(C_COMMENT); }
<C_COMMENT>"*/"         {++comment_count; BEGIN(INITIAL); }
<C_COMMENT>\n           { }
<C_COMMENT>.            { }
%%
int yywrap(void){
    return 1;
}
int main(){
    char out_file[100],in_file[100];
    printf("Input file :: ");
    scanf("%s",in_file);
    printf("Output File :: ");
    scanf("%s",out_file);
    yyin = fopen(in_file,"r");    
    yyout = fopen(out_file,"w");
    yylex();
    printf("Done Parsing Total :: %d comments\n",comment_count);
    return 0;
}