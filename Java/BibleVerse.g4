grammar BibleVerse;

prog: (bibleVerseReference NEWLINE)* bibleVerseReference EOF;

bibleVerseReference : ordinal? name reference? translation?;

ordinal : DIGIT ;

name : WORD ;

reference   : x
            | x ';' reference
            | x ';'
            | span
            | span ';' reference ;

span : nolengthx '-' nolengthx ;

nolengthx : chapter
          | chapter ':' nolengthverse ;

nolengthverse : DIGIT
              | DIGIT ',' DIGIT ;

x   : chapter
    | chapter ':' verse ;

chapter : DIGIT ;

verse   : length
        | length','verse ;

length  : DIGIT
        | DIGIT '-' DIGIT ;

translation : '('WORD')' ;

DIGIT   : [0-9]+ ;
WORD  : [a-zA-Z]+ ;
NEWLINE : '\r'? '\n' ;
WS      : [ \t]+ -> skip ;