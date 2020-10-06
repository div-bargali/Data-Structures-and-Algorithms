import java.util.Scanner;

public class MergeSort {

	public static void main(String[] args) {
		
		
		//int[] intarray = { 55, -20, 1, 35, 18, -7, 44};
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the No of Elements:");
		int n = s.nextInt();
		int[] intarray = new int[n];
		System.out.print("Enter the elements:" );
		for(int i=0;i<n;i++) {
			intarray[i] = s.nextInt();
		}
		mergeSort(intarray,0,intarray.length);
		System.out.println("\n");
		for(int i=0;i<intarray.length;i++) {
			System.out.print(intarray[i]+ "  ");
		}
		s.close();
	}
//Merge Sorting Algorightm
	private static void mergeSort(int[] input, int start, int end) {
		
		if(end - start < 2) {
			return;
		}
		
		int mid= (start+end)/2;
		mergeSort(input,start,mid);
		mergeSort(input,mid,end);
		merge(input,start,mid,end);
	}

	private static void merge(int[] input, int start, int mid, int end) {
		
		
		if(input[mid-1] <= input[mid]) {
			return;
		}
		
		int i=start;
		int j = mid;
		int tempIndex = 0;
		
		int[] temp = new int [end-start];
		
		while(i<mid && j< end) {
			temp[tempIndex++] = input[i] <= input[j] ? input[i++] : input[j++];
		}
		
		System.arraycopy(input, i, input, start + tempIndex, mid-i);
		
		System.arraycopy(temp, 0, input, start, tempIndex);
	}

}
