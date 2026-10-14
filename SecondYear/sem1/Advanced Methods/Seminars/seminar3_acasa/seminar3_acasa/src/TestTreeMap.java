import java.util.Map;
import java.util.TreeMap;

public class TestTreeMap {
    public static void main(String args[]){
        Student s1 = new Student("Dan",4.5f);
        Student s2 = new Student("Ana",8.5f);
        Student s3 = new Student("Dan",4.5f);

        Map<Student,String> treeMap = new TreeMap<>(new StudentNameComparator());
        treeMap.put(s1,"Grupa 221");
        treeMap.put(s2,"Grupa 216");
        treeMap.put(s3,"Grupa 215");

        System.out.println("Dimensiunea TreeMap:" + treeMap.size());
        for (Map.Entry<Student,String> entry: treeMap.entrySet()){
            System.out.println(entry.getKey()+ " -> "+ entry.getValue());
        }
    }
}
