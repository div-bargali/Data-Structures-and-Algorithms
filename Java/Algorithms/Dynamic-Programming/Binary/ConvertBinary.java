import java.util.Scanner;

public class ConvertBinary {

    //Function that decodes binary string messages
    public static void main(String[] args) {

        //Scan for binary message
        Scanner myObj = new Scanner(System.in);
        System.out.println("What is your binary input?");
        String binary = myObj.nextLine();

        StringBuilder finalMessage = new StringBuilder();

        //Checks each byte and converts to corresponding character
        for (int i = 0; i < binary.length(); i += 8) {
            String str = binary.substring(i, i+8);
            finalMessage.append((char)Integer.parseInt(str, 2));
        }

        //Prints decoded message
        System.out.println("Here is your message: " + finalMessage);
    }
}

