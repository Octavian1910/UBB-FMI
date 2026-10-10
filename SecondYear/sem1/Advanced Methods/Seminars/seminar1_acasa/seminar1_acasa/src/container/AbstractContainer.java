package container;
import model.Task;

public abstract class AbstractContainer implements Container {
    protected Task[] tasks;
    protected int size; //protected ca sa poata subclasele accesa direct vectorul si contorul
    private int capacity;

    public AbstractContainer() {
        this.size = 0;
        this.capacity = 10;
        this.tasks = new Task[10];
    }

    @Override
    public void add(Task task) {
        if (size == capacity) {
            capacity = capacity * 2;
            Task[] new_vector = new Task[capacity];
            for (int i = 0; i < tasks.length; ++i) {
                new_vector[i] = tasks[i];
            }
            tasks = new_vector;
        }
        tasks[size++] = task;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public abstract Task remove();
}
