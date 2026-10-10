public class OperationFactory {
    public static Operation createOperation(String symbol) {
        if (symbol == null)
            return null;

        switch (symbol) {
            case "+":
                return new AddOperation();
            case "-":
                return new SubtractOperation();
            case "*":
                return new MultiplyOperation();
            case "/":
                return new DivideOperation();
            default:
                return null;

        }
    }
}
