package container;

public class QuickSort extends AbstractSorter {
    @Override
    public void sort(int[] numbers) {
        if (numbers == null || numbers.length == 0) return;
        quickSort(numbers, 0, numbers.length - 1);
    }

    private void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

    private int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high ; ++j){
            if (arr[j] <= pivot){  //impinge spre stanga elementele mai mari decat pivotul
                ++i;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1]; //interschimbam pivotul sa fie fix dupa i adica la pozitia lui buna
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }
}
