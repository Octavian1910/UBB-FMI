package container;
import model.Task;
public class QueueContainer extends AbstractContainer {
    //FIFO

    @Override
    public Task remove() {
        if (isEmpty())
            return null;

        Task removed = tasks[0];
        for (int i = 0; i < size - 1; ++i)
            tasks[i] = tasks[i + 1];
        tasks[--size] = null;
        return removed;
    }
}
