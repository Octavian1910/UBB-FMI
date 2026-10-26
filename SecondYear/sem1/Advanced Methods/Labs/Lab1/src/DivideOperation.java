public class DivideOperation implements Operation {
    @Override
    public Complex execute(Complex first, Complex second) {
         /*
            (a + bi) / (c + di) = (a+bi)*(c-di) / (c+di)*(c-di) = ( ac - adi + bci + bd ) / ( c^2 + d^2 ) =
                                = ( ac + bd + i*(bd - ad ) ) / ( c^2 + d^2 ) = ( ac + bd ) / ( c^2 + d^2 ) + i * ( (bd - ad )  / ( c^2 + d^2 ) )
        * */

        double denominator = second.getReal() * second.getReal() + second.getImaginary() * second.getImaginary();
        if (denominator == 0) {
            throw new ArithmeticException("Impartire la zero!");
        }
        double real = (first.getReal() * second.getReal() + first.getImaginary() * second.getImaginary()) / denominator;
        double imaginary = (first.getImaginary() * second.getReal() - first.getReal() * second.getImaginary()) / denominator;
        return new Complex(real, imaginary);

    }
}
