package ex.functional;

public class Cerc {
    private double raza;

    public Cerc(double raza){
        this.raza = raza;
    }

    public double getRaza() {
        return raza;
    }

    public static double arie(Cerc c){
        return Math.PI * c.getRaza() * c.getRaza();
    }

    @Override
    public String toString() {
        return "Cerc{raza=" + raza + "}";
    }
}
