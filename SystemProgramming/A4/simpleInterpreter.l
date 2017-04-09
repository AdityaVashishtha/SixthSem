%{
    #include "y.tab.h"
    #include <stdlib.h>
    #include <string.h>
    void yyerror(char *);
%}
%%
[0-9]+\.[0-9]+      {
                yylval = strtod(yytext,NULL);
                return INTEGER;
            }
[-+*/)(\n]      return *yytext;
[ \t]       ; 
.           yyerror("invalid character");

%%
int yywrap(void) {
    return 1;
}