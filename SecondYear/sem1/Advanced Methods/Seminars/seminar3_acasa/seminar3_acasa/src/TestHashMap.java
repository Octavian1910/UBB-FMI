import java.util.HashMap;
import java.util.Map;

public class TestHashMap {
    public static void  main(String[] args)
    {
        Student s1 = new Student("Dan",4.5f);
        Student s2 = new Student("Dan",4.5f);
        Student s3 = new Student("Ana",8.5f);

        Map<Student,String> map = new HashMap<>();
        map.put(s1,"Grupa 221");
        map.put(s2,"Grupa 222"); //cheie duplicata
        map.put(s3,"Grupa 223");

        System.out.println("Dimensiunea HashMap: " + map.size());
        for (Map.Entry<Student,String> entry: map.entrySet()){
            System.out.println(entry.getKey() + "->" + entry.getValue());
        }
    }
}
