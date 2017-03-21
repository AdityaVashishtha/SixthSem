digit     [0-9]
letter    [A-Za-z]
undscr    [_]
space     [" "]
%{
    int flag = 0;    
%}
%s STATE1
%s STATE2
%%
    /* match identifier */
^({letter})  { BEGIN(STATE1);}
<STATE1>({undscr}|{letter}|{digit})*    {BEGIN(STATE1);}
<STATE1>\n  { flag = 1; return 0;}
<STATE1>(.)    {BEGIN(STATE2);}
^({digit}|.)     {BEGIN(STATE2);}
\n {return 0;}
. { /**/}
%%
int yywrap(void) {
    return 1;
}
int main(void) {
    printf("Enter Variable name :: ");                
    yylex();        
    if(flag == 1)
        printf("Valid Variable \n");
    else
        printf("Invalid Variable \n");
}