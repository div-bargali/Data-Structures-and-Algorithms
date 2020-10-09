import java.util.Scanner;

public class SelectionSort {

	
	public static void main(String[] args) {
		
		
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the No of Elements:");
		int n = s.nextInt();
		int[] intarray = new int[n];
		System.out.print("Enter the elements:" );
		for(int i=0;i<n;i++) {
			intarray[i] = s.nextInt();
		}
//Selection Sort Algorithm		
		for(int unsoretedarrayindex=intarray.length-1; unsoretedarrayindex>0;unsoretedarrayindex-- ) {
			
			int largest=0;
			
			for(int i=1;i<=unsoretedarrayindex;i++) {
				if(intarray[i]>intarray[largest]) {
					largest=i;
				}
				swap(intarray, largest,unsoretedarrayindex);
				
			}
// You can remove these comments and watch the iterations for better understanding of this Algorithm			
//			for(int i =0;i<intarray .length;i++) {
//				System.out.print(intarray[i]+ "  ");
//			}
//			System.out.println();
		}
		//System.out.println("\n");
		for(int i =0;i<intarray .length;i++) {
			System.out.print( intarray[i]+ "  ");
		}
		s.close();

	}
	public static void swap(int[] array, int i ,int j) {
		
		if(i==j) return;
		int temp= array[i];
		array[i]=array[j];
		array[j]=temp;
	}

}
