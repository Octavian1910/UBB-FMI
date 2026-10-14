import map.MyMap;
import model.Student;

import java.util.*;

public class Main {
    public static List<Student> getList() {
        List<Student> l = new ArrayList<Student>();
        l.add(new Student("1", 9.7f));
        l.add(new Student("2", 7.3f));
        l.add(new Student("3", 6f));
        l.add(new Student("4", 6.9f));
        l.add(new Student("5", 9.5f));
        l.add(new Student("6", 9.9f));
        return l;
    }

    public static void main(String[] args) {
        Student s1 = new Student("Dan", 4.5f);
        Student s2 = new Student("Ana", 8.5f);
        Student s3 = new Student("Dan", 4.5f);

        System.out.println("HASHSET");
        Set<Student> studenti = new HashSet<>();
        studenti.add(s1);
        studenti.add(s2);
        studenti.add(s3);

        for (Student s : studenti) {
            System.out.println(s);
        }

        Comparator<Student> comparatorDupaNume = new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return o1.getNume().compareTo(o2.getNume());
            }
        };

        System.out.println("TREESET");
        Set<Student> studentiTreeSet = new TreeSet<>(comparatorDupaNume);
        studentiTreeSet.add(s1);
        studentiTreeSet.add(s2);
        studentiTreeSet.add(s3);

        Iterator<Student> iterator = studentiTreeSet.iterator();
        while (iterator.hasNext()) {
            Student student = iterator.next();
            System.out.println(student);
        }

        System.out.println("HASHMAP");
        Map<String, Student> hashMap = new HashMap<>();
        hashMap.put(s1.getNume(), s1);
        hashMap.put(s2.getNume(), s2);
        hashMap.put(s3.getNume(), s3);

        for (Map.Entry<String, Student> entry : hashMap.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }

        System.out.println("TREEMAP");
        Map<String, Student> treeMap = new TreeMap<>();
        treeMap.put(s1.getNume(), s1);
        treeMap.put(s2.getNume(), s2);
        treeMap.put(s3.getNume(), s3);

        for (Map.Entry<String, Student> entry : treeMap.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }

        System.out.println("MYMAP");
        MyMap myMap = new MyMap();
        for (Student s : getList()) {
            myMap.add(s);
        }

        for (Map.Entry<Integer, List<Student>> entry : myMap.getEntries()) {
            System.out.println("Media " + entry.getKey() + ": " + entry.getValue());
        }
    }
}