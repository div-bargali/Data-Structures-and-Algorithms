
import java.util.*;
public class heapSort {
	public static void heapify(int[] arr,int n,int i) {
		int large=i;
		int x,l=2*i+1;
		int r=2*i+2;
		if(l < n && arr[l] > arr[large])
			large=l;
		if(r < n && arr[r] > arr[large])
			large=r;
		if(large!=i) {
			x=arr[large];
			arr[large]=arr[i];
			arr[i]=x;
			heapify(arr,n,large);
		}
	}
	public static void sort(int[] arr) {
		int i,n=arr.length;
		for(i=n/2-1;i>=0;i--) {
			heapify(arr,n,i);
		}
		for(i=n-1;i>0;i--) {
			int temp=arr[0];
			arr[0]=arr[i];
			arr[i]=temp;
			heapify(arr,i,0);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[]= {5,0,2,7,9,1,3,8,4};
		sort(arr);
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
	}

}
