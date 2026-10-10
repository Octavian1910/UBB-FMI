package runner;

import model.Task;
import container.Container;
import factory.Strategy;
import factory.TaskContainerFactory;

public class StrategyTaskRunner implements TaskRunner {
    private Container container = null;

    public StrategyTaskRunner(Strategy strategy) {
        this.container = TaskContainerFactory.getInstance().createContainer(strategy);
    }

    @Override
    public void addTask(Task t) {
        container.add(t);
    }

    @Override
    public boolean hasTask() {
        return !container.isEmpty();
    }

    @Override
    public void executeOneTask() {
        if (hasTask()) {
            Task current_task = container.remove();
            current_task.execute();
        }
    }

    @Override
    public void executeAll() {
        while (hasTask()) {
            executeOneTask();
        }
    }
}
