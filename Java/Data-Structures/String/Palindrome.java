// This code will check for palindrome strings

/** Palindrome String : A string that is spelt same even if reversed is called palindrome string.
 * example : madam , civic , kayak , refer , reviver etc.
 *
 * Algorithm for checking palindrome strings :
 * 1. Take a string as input
 * 2. Convert all the characters to lower case
 * 3. Reverse the string
 * 4. Now check if the reversed string and original strings are equal using 'equals()' method or simply '==' sign
 * 5. If equal then print "Palindrome" else print "Not Palindrome"
 */


import java.util.Scanner;
public class Palindrome
{
    public static void main(String []args)
    {
        // Using Scanner class to take input form the user
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the string : ");

        // .next() method is used for taking a single string as input in java Scanner class
        String word = sc.next();

        // using .toLowerCase() method to convert the string to lower case
        String lowerword = word.toLowerCase();

        //Now lowerword contains the lowercase form of the string word

        String reverse = "";     // String to store the reverse

        // Reversing the string using for loop that runs from string.length()-1 to 0
        for(int i = lowerword.length()-1;i>=0;i--)
        {
            char ch = lowerword.charAt(i);
            reverse = reverse + ch;
        }

        // Now lets check for the equality of the string and its reverse

        if(lowerword.equals(reverse))
            System.out.println("Palindrome");
        else
            System.out.println("Not Palindrome");
    }
}



/** TEST CASES
 * Test Case 1 :
 * Input : Madam
 * Output : Palindrome
 *
 * Test Case 2 :
 * Input : acquire
 * Output : Not Palindrome
 */

/**
 * Time Complexity : O(length of word)
 * Auxiliary Space Complexity : O(1)
 */
