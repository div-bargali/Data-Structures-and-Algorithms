public class Agnosticbinarysearch {
  public static void main(String [] args){
        // In agnostic binary search we don't know array is sorted in ascending order or descending order

        int [] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 19};
        int t = 1;
        int ans = binarysearch(arr, t);
        System.out.println(ans);
    }
    static int binarysearch(int[] a, int t)
    {
        int start = 0;
        int end = a.length - 1;
        boolean isAsc = a[0] < a[end];
        while(start < end)
        {
            int mid = start + (end - start)/2;
            if(t == a[mid])
            {
                return mid;
            }
            if(isAsc)
            {
                // means array is in ascending order
                if(t < a[mid])
                {
                    end = mid - 1;
                }
                else if(t > a[mid])
                {
                    start = mid+1;
                }
            }
            else
            {
                // means array is in descending order
                if(t < a[mid])
                {
                    start = mid +1;
                }
                else if(t > a[mid]) {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
}
