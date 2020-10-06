import java.util.Scanner;

public class InsertionSort {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the No of Elements:");
		int n = s.nextInt();
		int[] intarray = new int[n];
		System.out.print("Enter the elements:" );
		for(int i=0;i<n;i++) {
			intarray[i] = s.nextInt();
		}
//Insertion sort Algorighm
		for (int unsortedindex=1;unsortedindex<intarray.length;unsortedindex++) {
			int newelement = intarray[unsortedindex];
			
			int i;
			for(i=unsortedindex; i>0 && intarray[i-1]>newelement;i--) {
				intarray[i] = intarray[i-1];
			}
			intarray[i] = newelement;
// You can remove these comments and watch the iterations for better understanding of this Algorithm			
//			for(int j =0;j<intarray.length;j++) {
//				System.out.print(intarray[j]+ "  ");
//			}
//			System.out.println();
		}
		System.out.println("\n");
		for(int i=0;i<intarray.length;i++) {
			System.out.print(intarray[i]+ " ");
		}
		
		s.close();
	}
	public static void swap(int[] array,int i,int j) {
		if(i==j) return;
		int temp=array[i];
		array[i]=array[j];
		array[j]=temp;
	}

}
