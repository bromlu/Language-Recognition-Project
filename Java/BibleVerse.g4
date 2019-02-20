grammar BibleVerse;

prog: bibleVerseReference EOF;

bibleVerseReference : ordinal? name reference? translation?;

ordinal : DIGIT ;

name : WORD ;

reference   : x
            | x';'reference
            | reference '--' reference;

x   : chapter
    | chapter':'verse ;

chapter : DIGIT ;

verse   : length
        | length','verse ;

length  : DIGIT
        | DIGIT '--' DIGIT ;

translation : '('WORD')' ;

DIGIT   : [0-9]+ ;
WORD  : [a-zA-Z]+ ;
NEWLINE : '\r'? '\n' ;
WS      : [ \t]+ -> skip ;