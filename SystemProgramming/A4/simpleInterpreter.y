%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}
%token INTEGER
%token FLOAT
%token IDENTIFIER
%left '-' '+'
%left '*' '/'
%left '(' ')'
%%
line:
        line expr '\n'         { printf("  result %d\n", $2); }
        | 
        ;
expr:
        INTEGER                   { $$ = $1; printf("num: %d",$$);}        
        | expr '+' expr           { $$ = $1 + $3; }
        | expr '-' expr           { $$ = $1 - $3; }
        | expr '*' expr           { $$ = $1 * $3; }
        | expr '/' expr           { $$ = $1 / $3; }
        | '(' expr ')'            { $$ = $2 ;}
        ;
%%
void yyerror(char *s) {
    printf("Invalid String");
}
int main(void) {
    yyparse();
    return 0;
}