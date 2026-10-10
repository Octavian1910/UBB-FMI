public class ExpressionParser {
    public static boolean isValidExpression(String[] args) {
        if (args == null || args.length == 0 || args.length % 2 == 0)
            return false;

        if (args.length == 1)
            return ComplexParser.parse(args[0]) != null;

        String expectedOp = args[1];
        if (OperationFactory.createOperation(expectedOp) == null)
            return false;

        for (int i = 0; i < args.length; i++) {
            if (i % 2 == 0) // mergem pe operanzi
            {
                if (ComplexParser.parse(args[i]) == null)  // trb sa fie un Complex valid
                {
                    return false;
                }
            } else {
                if (!args[i].equals(expectedOp)) // ceilalti operanzi trb sa fie identici cu cel initial
                    return false;
            }

        }
        return true;
    }

    public static Complex evaluate(String args[]) {
        if (!isValidExpression(args))
            return null;

        Complex accumulator = ComplexParser.parse(args[0]);
        if (args.length == 1)
            return accumulator;

        Operation op = OperationFactory.createOperation(args[1]);

        for (int i = 2; i < args.length; i += 2) {
            Complex nextOperand = ComplexParser.parse(args[i]);
            accumulator = op.execute(accumulator, nextOperand);
        }
        return accumulator;
    }
}