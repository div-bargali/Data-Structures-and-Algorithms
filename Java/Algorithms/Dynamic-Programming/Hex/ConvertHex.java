import java.util.Scanner;

//Function that decodes hex messages
class ConvertHex {
    public static void main(String[] args) {

        //Scan for hex message
        Scanner myObj = new Scanner(System.in);
        System.out.println("What is your hex input?");
        String hex = myObj.nextLine();

        StringBuilder finalMessage = new StringBuilder();

        //Checks each hex digit and converts to ASCII character
        for (int i = 0; i < hex.length(); i += 2) {
            String str = hex.substring(i, i+2);
            finalMessage.append((char)Integer.parseInt(str, 16));
        }

        //Prints decoded message
        System.out.println("Here is your message: " + finalMessage);
    }
}
