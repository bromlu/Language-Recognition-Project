#include "lexer.c"
#include <stdio.h>
#include <stdlib.h>

extern void parseVerse();
extern void parseReference();

FILE *file;
int lineNumber = 1;
int error = 0;

void printError(char* msg) {
    error = 1;
    printf("Error (%d, %d): %s, found '%s'\n", lineNumber, charctorNumber, msg, value);
    while(lookahead != '\n' && lookahead != EOF) {
        lookahead = next(file);
    }
}

void parseOrdinal() {
    if(lookahead == D) {
        lookahead = next(file);
    }
}

void parseName() {
    if(lookahead == N) {
        lookahead = next(file);
    } else {
        printError("Book name expected");
    }
}

void parseBook() {
    parseOrdinal();
    parseName();
}

void parseChapter() {
    lookahead = next(file);
    if(lookahead == ':') {
        lookahead = next(file);
        parseVerse();
    }
}

void parseLength() {
    lookahead = next(file);
    if(lookahead == ',') {
        lookahead = next(file);
        parseVerse();
    } 
    if(lookahead == '-') {
        lookahead = next(file);
        if(lookahead == '-') {
            lookahead = next(file);
            if(lookahead == D) {
                parseReference();
            } else {
                printError("number expected");
            }
        } else {
            printError("'-' expected");
        }
    } 
}

void parseVerse() {
    if(lookahead == D) {
        parseLength();
    } else {
        printError("number expected");
    }
}

void parseReference() {
    if(lookahead == D) {
        parseChapter();
        if(lookahead == ';') {
            lookahead = next(file);
            parseReference();
        }
    }
}

void parseTranslation() {
    if(lookahead == '(') {
        lookahead = next(file);
        if(lookahead == N) {
            lookahead = next(file);
            if(lookahead == ')') {
                lookahead = next(file);
            } else {
                printError("closing bracket ')' expected");
            }
        } else {
            printError("single word expected");
        }
    }
}

void parseBibleReference() {
    parseBook();
    parseReference();
    parseTranslation();
    if(lookahead != '\n' && lookahead != EOF) {
        printError("unknown symbols at end of reference");
    } else if (error == 0) {
        printf("Valid Verse (%d)\n", lineNumber);
    }
}

int main(int argc, char *argv[]) {
    char* input_file = argv[1];

    if(input_file == NULL) {
        printf("Error: no file provided, please pass a valid file name as the first parameter to this pro lineNumber,gram.");
    }
    if((file = fopen(input_file, "r")) == NULL) {
        printf("Error: couldn't open %s, please try another file.\n", input_file);
        exit(1);
    }

    lookahead = next(file);
    if(lookahead == EOF) {
        printf("Error: empty file found, nothing to parse here.");
    } else {
        while(lookahead != EOF) {
            if(lookahead != '\n') {
                error = 0;
                parseBibleReference();
            }
            lookahead = next(file);
            lineNumber++;
        }
    }

    fclose(file);
}
