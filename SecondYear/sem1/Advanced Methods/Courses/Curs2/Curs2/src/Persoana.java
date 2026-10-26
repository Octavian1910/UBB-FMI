import java.util.*;

public class Persoana implements Comparable<Persoana> {
    private final String nume;

    public Persoana(String nume){
        this.nume = nume;
    }

    @Override
    public int compareTo(Persoana other) {
        return this.nume.compareTo(other.nume);
    }
}


class ListaOrdonata<E extends Comparable<E>>{
    private final List<E> elemente = new ArrayList<>();

    public void adauga(E elem){
        elemente.add(elem);
        Collections.sort(elemente);

    }
}
