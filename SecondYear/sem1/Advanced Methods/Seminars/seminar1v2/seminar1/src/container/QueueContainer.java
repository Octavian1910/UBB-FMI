package container;

public class QueueContainer extends AbstractContainer {

    @Override
    public Task remove() {
        if (isEmpty())
            return null;

        Task result = tasks[0];

        for (int i = 0; i < size - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        size--;

        return result;
    }
}