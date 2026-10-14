package map;

import model.Student;

import java.util.*;

import static java.lang.Math.round;

public class MyMap {

    private static class CheieComparator implements Comparator<Integer>
    {
        @Override
        public int compare(Integer o1, Integer o2) {
            return o2.compareTo(o1);
        }
    }

    private Map<Integer, List<Student>> map = new TreeMap<>(new CheieComparator());

    public void add(Student student)
    {
        int key = Math.round(student.getMedia());
        if (!map.containsKey(key))
            map.put(key,new ArrayList<>());

        map.get(key).add(student);
    }


    public Set<Map.Entry<Integer,List<Student>>> getEntries()
    {
        return map.entrySet();
    }
}
