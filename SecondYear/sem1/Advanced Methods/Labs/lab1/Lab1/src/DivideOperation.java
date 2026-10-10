public class DivideOperation implements Operation {
    @Override
    public Complex execute(Complex first, Complex second) {
        // (a + bi)/(c + di) = ((ac + bd) + (bc - ad)i) / (c^2 + d^2)
        double denominator = second.getReal() * second.getReal() + second.getImaginary() * second.getImaginary();
        if (denominator == 0) {
            throw new ArithmeticException("Impartire la zero!");
        }
        double real = (first.getReal() * second.getReal() + first.getImaginary() * second.getImaginary()) / denominator;
        double imaginary = (first.getImaginary() * second.getReal() - first.getReal() * second.getImaginary()) / denominator;
        return new Complex(real, imaginary);

    }
}
