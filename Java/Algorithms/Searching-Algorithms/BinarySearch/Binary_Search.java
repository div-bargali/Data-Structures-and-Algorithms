import java.util.Scanner;

public class searching {
    public static void main (String [] arhs) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array = ");
        int n = sc.nextInt();
        String a [] = new String[n];
        String b [] = new String[n];

        System.out.print("Enter values of A string : ");

        for (int k =0; k<a.length; k++) {
            a[k] = sc.next();
        }
        System.out.print("Enter values of B string : ");
        for (int k =0; k<b.length; k++) {
            b[k] = sc.next();
        }

        int result = match(a,b);

        System.out.println(result + " words found to be same" );
    }

    static int match (String a[], String b[]) {
        int s =0;
        for (int i =0; i<a.length; i++) {
            for (int j=0; j<b.length; j++) {
                if (a[i] == " ")
                    break;
                else if (a[i].equals(b[j]))
                    s = s+1;
            }
        }
        return s;
    }
}
