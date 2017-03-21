letter [A-Za-z]
digit   [0-9]
udscr   [_]
keyword [if|scanf|int|float|char|puts|gets|main|double|long|goto|break|continue|else|do|while|for]
%{
  int id_count;  
%}
%%

({letter})({letter}|{digit}|{udscr})*  { printf("%s\n",yytext);id_count++;}
({letter})({letter}|{digit}|{udscr})*".h"   { printf("%s\n",yytext);id_count++;}
{keyword}  { printf("%s\n",yytext);id_count++;}
"printf("(.)*")"    { id_count++;}
"scantf("(.)*")"    { id_count++;}
.|\n   { ; }
%%
int yywrap(void) {
    return 1;
}
int main() {
    printf("Enter file name :: ");
    char file_input[100];
    scanf("%s",file_input);
    yyin = fopen(file_input,"r");
    yylex();    
    printf("Total identifiers are :: %d \n",id_count);
}