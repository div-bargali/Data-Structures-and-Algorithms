public class QuickSort {

    static int partition(int[] arr, int low, it high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; i < high; j++) {
            if (arr[j] < pivot) {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;

    }

    void sort(int[] arr, int low, int high) {
        if (low < high) {

            int p = partition(arr, low, high);

            sort(arr, low, p - 1);
            sort(arr, p + 1, high);
        }

    }

}
