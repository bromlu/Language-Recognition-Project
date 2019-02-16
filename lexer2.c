// lexical analyzer suitable for Scripture Reference Parser assignment
//
// returns tokens D (sequence of digits), N (sequence of letters), EOF
// individual characters ';', ':', ','. '(', ')', '-'
// also return '\n' and '\r'
// all other characters do not fit grammar and are returned as ERR

#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int lookahead;
char value[20];

int next() {
    int t;
    int ctr=0;
    t = getchar();
    if (t != EOF) {
        while(t==' ' || t=='\t') t = getchar();
	if(isalpha(t)) {
	  // have N - get rest
	  value[ctr++]=t;
	  t=getchar();
	  while(isalpha(t)) {
            value[ctr++]=t;
            t=getchar();
          }  
          value[ctr]='\0';
	  ungetc(t,stdin);
	  return N;
	}
	if(isdigit(t)) {
	  value[ctr++]=t;
          t=getchar();
	  while(isdigit(t)) {
            value[ctr++]=t;
            t=getchar();
          }
          value[ctr]='\0';
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
    if(lookahead==D) printf("D{%s}",value);
    else {
      if(lookahead==N) printf("N{%s}",value);
      else {
        if(lookahead==ERR) printf("*ERR*");
	else printf("%c",lookahead);
      }
    }

  }
  printf("\n");
}



