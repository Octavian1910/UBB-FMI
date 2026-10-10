public abstract class AbstractTaskRunner implements TaskRunner {

    protected TaskRunner runner;

    public AbstractTaskRunner(TaskRunner runner) {
        this.runner = runner;
    }
}