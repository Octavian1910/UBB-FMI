import java.io.Serializable;

public class Entity<E> implements Serializable {
    private E id;

    public Entity() {

    }

    public Entity(E id) {
        this.id = id;
    }

    public E getId() {
        return id;
    }

    public void setId(E id) {
        this.id = id;
    }
}


