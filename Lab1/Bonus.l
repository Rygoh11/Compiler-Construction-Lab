%{
#include<stdio.h>
int X=0;
%}


/* Rule Definition */
%%
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {printf("\n %s is a Keyword",yytext);}

[a-zA-Z]+|[0-9]+ {printf("\n %s is an Identifier",yytext);}

[+*/%=-] {printf("\n %s is an Operator",yytext);}

[(){}();,.&^%$#@!'":|\/?><] {X++;}

%% 

/* Driver Function*/
int main(void){
	yyin= fopen("program.txt","r");
	yylex();
	
} 
int yywrap(){
	return(1);
}