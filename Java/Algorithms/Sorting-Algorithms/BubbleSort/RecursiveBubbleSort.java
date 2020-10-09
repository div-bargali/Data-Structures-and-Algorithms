public class Program {
    public static void main(String[] args) {
        int[] arr = bubbleSort(new int[] { 64, 34, 25, 12, 22, 11, 90 });
        for (int i = 0; i < arr.length; System.out.println(arr[i++]))
            ;

    }

    public static int[] bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            try {
                int num = arr[i];
                if (arr[i + 1] < num) {
                    arr[i] = arr[i + 1];
                    arr[i + 1] = num;
                    bubbleSort(arr);
                }
            } catch (IndexOutOfBoundsException e) {
                continue;
            }
        }
        return arr;
    }
}
