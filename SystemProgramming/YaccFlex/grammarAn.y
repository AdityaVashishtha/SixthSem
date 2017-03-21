%{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(char *);
%}
%token A
%start S
%%
S:      'a' 'a' 'a' 'a' 'a' 'a' 'a' 'a' 'a' E
E:      'a' E
        | 'b'
        ;
%%
void yyerror(char *s) {
    printf("String not accepted due to :: %s \n",s);
    exit(0);
}
int main() {
    printf("Enter String :: ");
    yylex();
    yyparse();    
    printf("String is accepted\n");
}