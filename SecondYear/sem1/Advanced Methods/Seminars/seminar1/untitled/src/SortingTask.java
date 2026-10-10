import java.util.Arrays;

public class SortingTask extends Task {
    private int[] numbers;
    private AbstractSorter sorter;
    public SortingTask(String taskID, String descriere, int[] numbers)
    {
        super(taskID,descriere);
        this.numbers = numbers;
    }


    @Override
    public void execute() {
        sorter.sort(numbers);
    }
}
