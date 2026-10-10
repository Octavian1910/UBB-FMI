public class AddOperation implements Operation {
    @Override
    public Complex execute(Complex first, Complex second) {
        return new Complex(first.getReal() + second.getReal(),
                first.getImaginary() + second.getImaginary());
    }
}
