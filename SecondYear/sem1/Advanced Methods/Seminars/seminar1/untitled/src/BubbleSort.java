public class BubbleSort extends AbstractSorter{

    @Override
    public void sort(int[] numbers) {

        for (int i = 0; i < numbers.length - 1; i++) {

            for (int j = 0; j < numbers.length - i - 1; j++) {

                if (numbers[j] > numbers[j + 1]) {

                    int aux = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = aux;
                }
            }
        }
    }
}
