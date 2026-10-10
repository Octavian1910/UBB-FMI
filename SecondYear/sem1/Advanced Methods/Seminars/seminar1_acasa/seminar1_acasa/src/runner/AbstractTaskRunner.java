package runner;
import model.Task;


public abstract class AbstractTaskRunner implements TaskRunner {
    protected TaskRunner taskRunner = null;

    public AbstractTaskRunner(TaskRunner taskRunner)
    {
        this.taskRunner = taskRunner;
    }

    @Override
    public void addTask(Task t) {
        taskRunner.addTask(t);
    }

    @Override
    public boolean hasTask() {
        return taskRunner.hasTask();
    }

    @Override
    public void executeAll() {
        while (hasTask()){
            executeOneTask(); //se apeleaza metoda din clasa copil
        }
    }
}
