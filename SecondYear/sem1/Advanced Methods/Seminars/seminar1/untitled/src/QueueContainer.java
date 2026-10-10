public class QueueContainer implements Container {

    private Task[] tasks;
    private int size;

    public QueueContainer() {
        tasks = new Task[10];
        size = 0;
    }

    @Override
    public void add(Task task) {
        tasks[size++] = task;
    }

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

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }
}