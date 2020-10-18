//Program to remove values that are more than two standard deviations away from average
//the values will be stored in a text file "numbers.txt"
//Each number is in a separate line

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main
{
    public static void main (String[] args) throws FileNotFoundException
    {
        //open the text file
        Scanner File = new Scanner(new File("numbers.txt"));

        //create ArrayList
        ArrayList<Double> numbers = new ArrayList<Double>();
        
        //variables for sum, average,count
        double sum=0,average,sd=0;
        int count=0;
        
        //input numbers in the array list
        while(File.hasNextLine()){
            String line = File.nextLine();
            
            Scanner scanner = new Scanner(line);
            scanner.useDelimiter("\n");
            while(scanner.hasNextDouble()){
                numbers.add(scanner.nextDouble());
            }
            scanner.close();
        }

        //Loop ArrayList using Iterator 
        Iterator<Double> it = numbers.iterator(); 
        
        //calculate sum and count the numbers
        while (it.hasNext()) 
        {
            count++;
            Double n = it.next();
            sum = sum + n;
        }
         
        //compute average
        average = sum/count;
        System.out.println("Average is:" + average );
        
        it = numbers.iterator();
        
        //compute standard deviation
        while (it.hasNext()) 
        {
            Double n = it.next();
            sd += Math.pow(n - average, 2);
        }
        
        sd = Math.sqrt(sd/count);
        
        //print standard deviation
        System.out.println("standard deviation is:" + sd + "\n" );
        
        Iterator<Double> it2 = numbers.iterator();
        
        //remove values that are more than two standard deviations away from average
        while(it2.hasNext())
        {   
            Double num = it2.next();
            
            if (num > (average + 2*sd) || num < (average - 2*sd) )
            it2.remove();
        }
        
        //new variables for sum, average, count
        int count2 = 0;
        int sum2 = 0, avg2;
        
        //print the new list
        //compute new sum
        for (double num:numbers){
            count2++;
            
            System.out.print(num + " ");
            sum2 += num;
        }
    
        //compute new average
        avg2 = sum2/count2;
        
        //dsiplay new average
        System.out.println("\nNew average is " + avg2);
        
        //close the file
        File.close();

    }
}
