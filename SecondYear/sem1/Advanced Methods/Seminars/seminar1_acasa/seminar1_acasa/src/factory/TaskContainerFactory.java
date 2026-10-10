package factory;

import container.Container;
import container.QueueContainer;
import container.StackContainer;

public class TaskContainerFactory implements Factory {
    private static TaskContainerFactory instance = null;

    private TaskContainerFactory() { //constructor privat blocheaza apelul cu new din alte clase ; trb sa existe doar un singur factory nu are sens sa existe mai multe
    }

    public static TaskContainerFactory getInstance() {
        if (instance == null)
            instance = new TaskContainerFactory();
        return instance;
    }

    @Override
    public Container createContainer(Strategy strategy) {
        if (strategy == Strategy.LIFO)
            return new StackContainer();
        else if (strategy == Strategy.FIFO) {
            return new QueueContainer();
        }
        return null;
    }
}
