package ex.functional;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.List;

public class TestArie {

    public static <E> void printArie(List<E> figuri, Arie<E> arie){
        for (E figura : figuri){
            System.out.printf("%s -> aria: %.2f%n", figura, arie.calculeaza(figura));
        }
    }


    public  static void main(String[] args){
        List<Cerc> cercuri = Arrays.asList(
                new Cerc(1.0),
                new Cerc(2.5),
                new Cerc(4.0)
        );

        List<Patrat> patrate = Arrays.asList(
                new Patrat(2.0),
                new Patrat(3.5),
                new Patrat(5.0)
        );

        //cerc cu clasa anonima
        Arie<Cerc> arieAnonima = new Arie<Cerc>() {
            @Override
            public double calculeaza(Cerc figura) {
                return Math.PI * figura.getRaza() * figura.getRaza();
            }
        };
        printArie(cercuri, arieAnonima);

        //cerc cu expresie lambda
        Arie<Cerc> arieLambda = c ->Math.PI * c.getRaza() * c.getRaza();
        printArie(cercuri, arieLambda);

        // cerc cu referinta la metoda statica Cerc::arie
        printArie(cercuri,Cerc::arie);

        //lambda transmisa direct ca parametru;
        printArie(patrate, p -> p.getLatura() * p.getLatura());
    }
}
