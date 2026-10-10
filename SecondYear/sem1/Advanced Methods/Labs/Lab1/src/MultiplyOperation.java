public class MultiplyOperation implements Operation {
    @Override
    public Complex execute(Complex first, Complex second) {
        //(a + bi)*(c + di) = ac + adi + bci - bd = ac - bd + adi + bci
        double real = first.getReal() * second.getImaginary() - second.getImaginary() * second.getImaginary();
        double imaginary = first.getReal() * second.getImaginary() + first.getImaginary() * second.getReal();
        return new Complex(real, imaginary);
    }
}
