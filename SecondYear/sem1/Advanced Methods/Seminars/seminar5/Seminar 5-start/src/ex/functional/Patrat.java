package ex.functional;

public class Patrat {

    private double latura;

    public Patrat(double latura){
        this.latura = latura;
    }

    public double getLatura() {
        return latura;
    }

    @Override
    public String toString() {
        return "Patrat{latura=" + latura + "}";
    }
}
