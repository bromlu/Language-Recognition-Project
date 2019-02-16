// lexical analyzer suitable for Scripture Reference Parser assignment
//
// returns tokens D (sequence of digits), N (sequence of letters), EOF
// individual characters ';', ':', ','. '(', ')', '-'
// also return '\n' and '\r'
// all other characters do not fit grammar and are returned as ERR

#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>

int lookahead;


int next() {
    int t;
    t = getchar();
    if (t != EOF) {
        while(t==' ' || t=='\t') t = getchar();
	if((t>='A')&&(t<='Z') || (t>='a')&&(t<='z')) {
	  // have N - get rest
	  t=getchar();
	  while((t>='A')&&(t<='Z') || (t>='a')&&(t<='z')) t=getchar();
	  ungetc(t,stdin);
	  return N;
	}
	if((t>='0')&&(t<='9')) {
	  t=getchar();
	  while((t>='0')&&(t<='9')) t=getchar();
	  ungetc(t,stdin);
	  return D;
	}
	if (t==';' || t==':' || t==',' || t=='(' || t==')' || t=='-' ||
	          t=='\n' || t=='\r') return t;
	return ERR;


    }
    else return EOF;

} 

// main function for testing only - remove before use

int main() {
  int lookahead;

  while((lookahead=next())!=EOF) {
    if(lookahead==D) printf("D");
    else {
      if(lookahead==N) printf("N");
      else {
        if(lookahead==ERR) printf("*ERR*");
	else printf("%c",lookahead);
      }
    }

  }
  printf("\n");
}



