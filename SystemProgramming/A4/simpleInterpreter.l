number [0-9]+
float_number [0-9]
%{
  #include   <stdio.h>
  #include <yy.tab.h>
  void yyerror(char *);
%}
%%
%%