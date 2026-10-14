import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class TestMyMap {
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

    public static void main(String args[])
    {
        MyMap myMap = new MyMap();
        for (Student s:getList()){
            myMap.add(s);
        }

        System.out.println("Gruparea pe medii rotunjite descrescator");
        for (Map.Entry<Integer,List<Student>> entry: myMap.getEntries()){
            Integer grade = entry.getKey();
            List<Student> students = entry.getValue();

            students.sort(new StudentNameComparator());
            System.out.println("Media rotunjita"+ grade + ": " + students);
        }
    }

}
