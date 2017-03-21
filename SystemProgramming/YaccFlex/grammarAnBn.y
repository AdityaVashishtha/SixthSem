%{
    #include <stdio.h>
    #include <stdlib.h>
    int flag = 0;
    void yyerror(char *);
%}
%%
line: S
      ; 
S:    'a' S 'b'     
    | 'a' 'b'       
    |               
    ;         
%%
void yyerror(char *s) {
    printf("String not accepted due to :: %s \n",s);
    exit(0);
}
int main() {
    printf("Enter String :: ");
    yyparse();    
    printf("String is accepted\n");
}