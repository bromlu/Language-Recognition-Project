# Language-Recognition-Project

Three different parsers that parse valid Bible references.

## Example Input

```bash
1 John 1:2-4
Ps 12:1,3-4 (ESV)
Matt 2:3-4;3:2
Matt 2:3-3:1 (NASB)
1 John 1:2-
```

## Method 1: C Lexer and Recursive Decent Parser

### Example Output

```bash
Valid Verse (1)
Valid Verse (2)
Valid Verse (3)
Valid Verse (4)
Error (5, 12): number expected, found '-'
```

### Build

```bash
$ make
```

### Run

```bash
$ ./recursiveDescentParser <inputFile.txt>
```

## Method 2: Perl with Regex

```bash
(1) Valid
(2) Valid
(3) Valid
(4) Valid
(5) Invalid
```

### Run

```bash
$ perl perlRegex.pl <inputFile.txt>
```

## Method 3: Java + Antlr

### Example Output

```bash
line 30:10 mismatched input '-' expecting WORD
```

### Run

I used IntelliJ with the Antlr plugin to run this. After installing the plugin [Antlr IntelliJ plugin](https://plugins.jetbrains.com/plugin/7358-antlr-v4-grammar-plugin) simply right click on the grammar and hit "generate Antlr Recognizer." Then mark the "gen" folder as source, then go ahead and run the InfixTranslator file. The translated input file will appear in the console.

Currently the input file location is hard coded in the Java file as "../test-values.txt". Make sure to change that to an existing input file on your system.

### Dependency

You will need to download the Antlr runtime in order to run this project. Here is a link to their website: [Antlr](https://www.antlr.org/).
