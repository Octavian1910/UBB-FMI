import java.util.*;

public class MyMap {
    private static class DescendingIntegerComparator implements Comparator<Integer>{
        @Override
        public int compare(Integer o1, Integer o2) {
            return o2.compareTo(o1); //inversam ordinea pt descrescator
        }
    }

    private Map<Integer, List<Student>> map;

    public MyMap(){
        this.map = new TreeMap<>(new DescendingIntegerComparator());
    }

    public void add(Student student){
        if (student == null)
            return;

        int roundedGrade = Math.round(student.getMedia());
        if (!map.containsKey(roundedGrade)){
            map.put(roundedGrade,new ArrayList<>());
        }

        map.get(roundedGrade).add(student); //intoarce lista si ii adauga un obicet de tip student
    }

    public Set<Map.Entry<Integer, List<Student>>> getEntries() {
        return map.entrySet();
    }
}
