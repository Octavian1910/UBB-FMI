public class Main {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("0 argumente deci se ruleaza testele");
            Tests.runTests();
            return;
        }

        if (!ExpressionParser.isValidExpression(args)) {
            System.out.println("Expresia furnizata nu respecta formatul cerut (n1 op n2 op ... op nk cu acelasi operator)!");
            return;
        }

        Complex result = ExpressionParser.evaluate(args);
        System.out.println("Rezultat: " + result);
    }
}