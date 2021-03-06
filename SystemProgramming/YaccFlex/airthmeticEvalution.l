%{
    #include "y.tab.h"
    #include <stdlib.h>
    void yyerror(char *);
%}
%%
[0-9]+      {
                yylval = atoi(yytext);
                return INTEGER;
            }
[-+*/)(\n]      return *yytext;
[ \t]       ; 
.           yyerror("invalid character");

%%
int yywrap(void) {
    return 1;
}