import org.antlr.v4.runtime.*;

public class Test {
    public static void main(String[] args) throws Exception {
        CharStream input = CharStreams.fromFileName("inputs/test.txt");
        BibleVerseLexer lexer = new BibleVerseLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        BibleVerseParser parser = new BibleVerseParser(tokens);

        parser.prog(); // parse the input stream!
    };
}