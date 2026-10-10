import container.Task;
import factory.Strategy;

public class SortingTask extends Task {

    private int[] vector;
    private Strategy strategy;

    public SortingTask(String taskID, String description,
                       int[] vector, Strategy strategy){
        super(taskID,description);

        this.vector = vector;
        this.strategy = strategy;
    }

    @Override
    public void execute()
    {
        strategy.sort(vector); //nu stie daca sorteaza cu quick sau bubble
    }
}
