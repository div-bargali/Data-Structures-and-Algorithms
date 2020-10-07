import java.util.Scanner;

public class KMPPatternSearching {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		// Input for pattern to search
		String pat=s.next();
		// Input for original string
		String str=s.next();
		KMP(pat, str);
		

	}
	public static void KMP(String pat, String str)
	{
		int M=pat.length();
		int N=str.length();
		// lps array keeps track of longest prefix suffix value(lps) 
		int lps[]= calLPS(pat);
		int j=0;
		int i=0;
		
		while(i<N)
		{
			if(pat.charAt(j)==str.charAt(i))
			{
				i++;
				j++;
			}
			if(j==M)
			{
				System.out.println("Pattern is found at:"+(i-j));
				j=lps[j-1];
			}
			// mismatch after j matches 
			else if(i<N && pat.charAt(j)!=str.charAt(i))
			{
				// Do not match lps[0..lps[j-1]] characters, 
                // they will match anyway
				if(j!=0)
				{
					j=lps[j-1];
				}
				else
				{
					i=i+1;
				}
			}
		}
		
	}
	// callLPS calculates the Longest Prefix Suffix (lps) array
	public static int[] calLPS(String str)
	{
		int n=str.length();
		int lps[]= new int[n];
		int i=1;
		int len=0;
		lps[0]=0;
		// the loop calculates lps[i] for i = 1 to M-1 
		while(i<n)
		{
			if(str.charAt(i)==str.charAt(len))
			{
				len++;
				lps[i]=len;
				i++;
			}
			// (pat[i] != pat[len]) 
			else
			{
				 // This is tricky. Consider the example. 
                // AAACAAAA and i = 7. The idea is similar 
                // to search step.
				if(len!=0)
				{
					len=lps[len-1];
				}
				else
				{
					lps[i]=0;
					i++;
				}
			}
			
		}
		return lps;
	}

}
