%{
    #include "y.tab.h"
    #include <stdlib.h>
    void yyerror(char *);
%}
%%
[ab]      return *yytext;
.         yyerror("invalid string");
\n        return 0;
%%
int yywrap(void){
    return 1;
}