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
int charctorNumber = 0;

int next(FILE *file) {
  int t;
  int ctr=0;
  t = fgetc(file);
  charctorNumber++;
  if (t != EOF) {
    while(t==' ' || t=='\t') {
      t = fgetc(file);
      charctorNumber++;
    }
    if(isalpha(t)) {
      // have N - get rest
      value[ctr++]=t;
      t=fgetc(file);
      charctorNumber++;
      while(isalpha(t)) {
        value[ctr++]=t;
        t=fgetc(file);
        charctorNumber++;
      }  
      value[ctr]='\0';
      ungetc(t,file);
      charctorNumber--;
      return N;
    }
    if(isdigit(t)) {
      value[ctr++]=t;
      t=fgetc(file);
      charctorNumber++;
      while(isdigit(t)) {
        value[ctr++]=t;
        t=fgetc(file);
        charctorNumber++;
      }
      value[ctr]='\0';
      ungetc(t,file);
      charctorNumber--;
      return D;
    }
    if (t==';' || t==':' || t==',' || t=='(' || t==')' || t=='-' ||
    t=='\n' || t=='\r') {
      if(t == '\n' || t == '\r') {
        charctorNumber = 0;
      }
      value[ctr++] = t;
      value[ctr] = '\0';
      return t;
    }
    return ERR;
  }
  else return EOF;
} 



