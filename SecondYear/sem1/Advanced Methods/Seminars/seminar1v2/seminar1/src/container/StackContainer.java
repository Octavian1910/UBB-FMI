package container;

public class StackContainer extends AbstractContainer {

    @Override
    public Task remove() {
        if (isEmpty())
            return null;

        return tasks[--size];
    }
}