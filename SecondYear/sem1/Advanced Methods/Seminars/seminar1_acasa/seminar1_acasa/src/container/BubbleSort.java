package container;

import factory.Factory;

public class BubbleSort extends AbstractSorter{
    @Override
    public void sort(int[] numbers) {
        if (numbers == null) return;
        int n = numbers.length;
        boolean swapped;
        for (int i = 0 ; i < n - 1 ; ++i)
        {
            swapped = false;
            for (int j = 0 ; j < n - i - 1 ; ++j){
                if (numbers[j] > numbers[j + 1]){
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
}
