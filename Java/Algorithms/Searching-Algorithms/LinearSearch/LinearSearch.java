/**
 * Algorithm : Linear Search
 * Description: Given an array of integers and you need to find a key or a number. If you finds the key in the array, it returns TRUE otherwise FALSE
 * Time Complexity : O(n)
 */

import java.util.*;

public class LinearSearch {
    private static final String ERROR_STRING = "Please provide a valid integers";
    public static void main(String[] args) {
        try {
            Scanner scanner =new Scanner(System.in);
            System.out.println("Enter no of integers");
            int numIntegers =scanner.nextInt();

            System.out.println("Enter "+ numIntegers +" Integers");
            Integer[] array = new Integer[numIntegers];
            for (int index = 0; index < numIntegers ; index++) {
                array[index]=scanner.nextInt();
            }

            System.out.println("Enter the key you want to search");
            Integer keyToSearch = scanner.nextInt();


            List<Integer> listOfNumbers = new ArrayList<Integer>(Arrays.asList(array));
            InputOutputMethod(listOfNumbers, keyToSearch);
        }
        catch(Exception e) {
            System.out.println(ERROR_STRING);
        }
    }

    private static void InputOutputMethod(List<Integer> listOfNumbers, Integer keyToSearch) {
        if(listOfNumbers.size() >= 1){
            StringBuilder output = new StringBuilder();
            Boolean searched = linearSearch(listOfNumbers, keyToSearch);
            if(Boolean.TRUE.equals(searched)){
                System.out.println("Hey, I got the key in this set of integers");
            } else {
                System.out.println("Oops!, Not Found");
            }
        }else{
            System.out.println(ERROR_STRING);
        }
    }

    private static Boolean linearSearch(List<Integer> list, Integer keyToSearch) {
        Boolean answer = false;
        for (Integer number : list) {
            if(number == keyToSearch) {
                answer = true;
                break;
            }
        }
        return answer;
    }
}
