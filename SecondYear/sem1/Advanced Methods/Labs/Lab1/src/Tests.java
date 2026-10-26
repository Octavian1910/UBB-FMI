public class Tests {
    private static final double EPSILON = 0.000001;

    public static void runTests() {
        testOperations();
        testParser();
        testValidation();
        testEvaluation();
        System.out.println("Toate testele au trecut cu succes!");
    }

    private static void testOperations() {
        Complex a = new Complex(2, 3);
        Complex b = new Complex(5, -6);

        Operation add = new AddOperation();
        Complex sum = add.execute(a, b);
        assert Math.abs(sum.getReal() - 7) < EPSILON;
        assert Math.abs(sum.getImaginary() - (-3)) < EPSILON;

        Operation sub = new SubtractOperation();
        Complex diff = sub.execute(a, b);
        assert Math.abs(diff.getReal() - (-3)) < EPSILON;
        assert Math.abs(diff.getImaginary() - 9) < EPSILON;

        Operation mul = new MultiplyOperation();
        Complex prod = mul.execute(a, b);
        assert Math.abs(prod.getReal() - 28) < EPSILON;
        assert Math.abs(prod.getImaginary() - 3) < EPSILON;

        Operation div = new DivideOperation();
        Complex quot = div.execute(a, b);
        assert Math.abs(quot.getReal() - (-8.0 / 61)) < EPSILON;
        assert Math.abs(quot.getImaginary() - (27.0 / 61)) < EPSILON;
    }

    private static void testParser() {
        Complex c1 = ComplexParser.parse("2+3*i");
        assert c1 != null && Math.abs(c1.getReal() - 2) < EPSILON && Math.abs(c1.getImaginary() - 3) < EPSILON;

        Complex c2 = ComplexParser.parse("5-6*i");
        assert c2 != null && Math.abs(c2.getReal() - 5) < EPSILON && Math.abs(c2.getImaginary() - (-6)) < EPSILON;

        Complex c3 = ComplexParser.parse("-2+i");
        assert c3 != null && Math.abs(c3.getReal() - (-2)) < EPSILON && Math.abs(c3.getImaginary() - 1) < EPSILON;

        Complex c4 = ComplexParser.parse("1-i");
        assert c4 != null && Math.abs(c4.getReal() - 1) < EPSILON && Math.abs(c4.getImaginary() - (-1)) < EPSILON;

        // Cazuri invalide
        assert ComplexParser.parse("abc") == null;
        assert ComplexParser.parse("5+5") == null; // lipseste i
        assert ComplexParser.parse("") == null;
        assert ComplexParser.parse("+3*i") == null;
    }

    private static void testValidation() {
        // Corect 2+3*i + 5-6*i + -2+i
        assert ExpressionParser.isValidExpression(new String[]{"2+3*i", "+", "5-6*i", "+", "-2+i"});

        // Gresit lungime para (lipseste un operand)
        assert !ExpressionParser.isValidExpression(new String[]{"2+3*i", "+"});

        // Gresit operatori diferiti (+ si *)
        assert !ExpressionParser.isValidExpression(new String[]{"2+3*i", "+", "5-6*i", "*", "-2+i"});

        // Gresit operator necunoscut
        assert !ExpressionParser.isValidExpression(new String[]{"2+3*i", "^", "5-6*i"});
    }

    private static void testEvaluation() {
        String[] expr = {"2+3*i", "+", "5-6*i", "+", "-2+i"};
        Complex res = ExpressionParser.evaluate(expr);
        assert res != null;
        assert Math.abs(res.getReal() - 5.0) < EPSILON;
        assert Math.abs(res.getImaginary() - (-2.0)) < EPSILON;
    }
}