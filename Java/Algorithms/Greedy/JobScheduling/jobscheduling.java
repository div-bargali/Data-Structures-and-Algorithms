package Practical_3;
import java.util.*;
 
class jobScheduling{
	String id;
	int deadline,profit;
	public jobScheduling() {}
	public jobScheduling(String id,int deadline,int profit) {
		this.id=id;
		this.deadline=deadline;
		this.profit=profit;
	}
	public String toString() {
		return id+" "+deadline+" "+profit;
	}
}
 
public class practical_3 {
	public static void main(String args[]) {
		Scanner s =new Scanner(System.in);
		System.out.println("Enter no of elements");
		int n=s.nextInt();
		jobScheduling job=null;
		jobScheduling j[]=new jobScheduling[n];
		System.out.println("Enter job id,deadline and profit");
		for(int i=0;i<n;i++) {
				String id=s.next();
				int deadline=s.nextInt();
				int profit=s.nextInt();
				job=new jobScheduling(id,deadline,profit);
				j[i]=job;
		}
		//		Sorting according to profit(in decreasing order)
		 for (int i = 0; i < j.length; i++) {     
		            for (int j1 = i+1; j1 < j.length; j1++) {     
		               if(j[i].profit < j[j1].profit) {    
		                   jobScheduling temp = j[i];    
		                   j[i] = j[j1];    
		                   j[j1] = temp;    
		               }     
		            }     
		        } 
		
		
		//		Creating Deadline array
		
		int max=j[0].deadline;
		for(int i=1;i<n;i++) {
			if(j[i].deadline>max);
			max=j[i].deadline;
		}
		jobScheduling deadLineArray[]=new jobScheduling[max];
		for(int i=0;i<max;i++) {
			deadLineArray[i]=null;
		}
		
		//     allocating slots for respective deadline
		
		for(int i=0;i<n;i++) {
			int deadLine=j[i].deadline;
			if(deadLineArray[deadLine-1]==null) {
				deadLineArray[deadLine-1]=j[i];
			
		}
		else {
		for(int j1=deadLine-2;j1>=0;j1--) {
		if(deadLineArray[j1]==null) {
		deadLineArray[j1]=j[i];
		
		}
		}
		}
		}
		System.out.println("The Complete Deadline array considering the maximum    profit  after traversing the job scheduling array is : ");
		String ans="";
		int maxProfit=0;
		for(int i=0;i<max;i++) {
		System.out.println(deadLineArray[i]);
		ans=ans+deadLineArray[i].id;
		maxProfit=maxProfit+deadLineArray[i].profit;
		
		}
		System.out.println("The correct sequence is : "+ans);
		System.out.println("The maximum profit is : "+maxProfit);
		
	
	
	}
}

