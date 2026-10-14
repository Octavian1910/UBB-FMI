import java.util.Locale;
import java.util.Objects;

public class Student extends Entity<Long> {
    private String nume;
    private float media;

    public Student(Long id,String nume, float media) {
        super(id);
        this.nume = nume;
        this.media = media;
    }

    public String getNume() {
        return nume;
    }

    public float getMedia() {
        return media;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + getId() +
                ", nume='" + nume + '\'' +
                ", media=" + media +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o .getClass()) return false;
        Student student = (Student) o;
        return Float.compare(media,student.media) == 0 &&
                Objects.equals(nume,student.nume);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nume,media);
    }
}
