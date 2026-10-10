package container;
import model.Task;

public class StackContainer extends AbstractContainer {
    //LIFO last in first out

    public StackContainer() {
        super();
    }

    @Override
    public Task remove() {
        if (isEmpty()) {
            return null;
        }
        Task removed = tasks[--size];
        tasks[size] = null;
        return removed;
    }
}
