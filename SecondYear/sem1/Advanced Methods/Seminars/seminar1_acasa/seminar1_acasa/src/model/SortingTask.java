package model;

import container.AbstractSorter;
import container.BubbleSort;
import container.QuickSort;

import java.util.Arrays;

public class SortingTask extends Task{
    private int[] numbers;
    private AbstractSorter sorter;

    public SortingTask(String taskId, String description, int[] numbers, SortingStrategy strategy) {
        super(taskId,description);
        this.numbers = numbers;
        if (strategy == SortingStrategy.QUICK_SORT){
            this.sorter = new QuickSort();
        }else if (strategy == SortingStrategy.BUBBLE_SORT){
            this.sorter = new BubbleSort();
        }
    }

    @Override
    public void execute() {
        sorter.sort(numbers);
        System.out.println("SortingTask " + getTaskID() + " executat. Rezultat: " + Arrays.toString(numbers));
    }
}
