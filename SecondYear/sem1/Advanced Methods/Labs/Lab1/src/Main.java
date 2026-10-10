public class Main {
    public static void main(String[] args) {
        // Daca nu se dau argumente in terminal, rulam testele
        if (args.length == 0) {
            System.out.println("Nu s-au detectat argumente. Se ruleaza testele unitare...");
            Tests.runTests();
            return;
        }

        // Verificam daca expresia este valida
        if (!ExpressionParser.isValidExpression(args)) {
            System.out.println("Eroare: Expresia furnizata nu respecta formatul cerut (n1 op n2 op ... op nk cu acelasi operator)!");
            return;
        }

        // Calculam si afisam rezultatul
        Complex result = ExpressionParser.evaluate(args);
        System.out.println("Rezultat: " + result);
    }
}