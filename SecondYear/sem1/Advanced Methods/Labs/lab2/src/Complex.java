public class Complex {
    private final double real;
    private final double imaginary;

    public Complex(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public double getImaginary() {
        return imaginary;
    }

    public double getReal() {
        return real;
    }

    @Override
    public String toString() {
        if (real == 0 && imaginary == 0) {
            return "0";
        }

        if (imaginary == 0) {
            return String.valueOf(real);
        }

        if (real == 0) {
            return imaginary + "*i"; // dacă e negativ, păstrează automat minusul (ex: -3.0*i)
        }

        if (imaginary > 0) {
            return real + " + " + imaginary + "*i";
        } else {
            return real + " - " + Math.abs(imaginary) + "*i";
        }
    }
}
