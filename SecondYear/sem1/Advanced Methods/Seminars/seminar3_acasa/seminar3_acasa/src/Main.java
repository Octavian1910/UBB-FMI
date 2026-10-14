import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Student s1 = new Student("Dan", 4.5f);
        Student s2 = new Student("Ana", 8.5f);
        Student s3 = new Student("Dan", 4.5f);
        Set<Student> students = new HashSet<>();
        students.add(s1);
        students.add(s2);
        students.add(s3);


        System.out.println("Numar studenti in HashSet: " + students.size());
        for (Student s : students) {
            System.out.println(s);
        }

        Set<Student> treeSet = new TreeSet<>(new StudentNameComparator());
        treeSet.add(s1);
        treeSet.add(s2);
        treeSet.add(s3);

        System.out.println("TreeSet ordonat dupa nume");
        for (Student s : treeSet) {
            System.out.println(s);
        }
    }
}