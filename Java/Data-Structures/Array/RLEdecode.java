//Program to decode RLE data

public class Main
{
	public static void main(String[] args) {
	
	//the data that has to be decoded
	byte data[] = {3,15,6,4};
	
	//the decoded data
	//calling method decodeRLE()
	byte decoded[] = decodeRLE(data);
	
	//print the decoded data
	for(int i=0;i<decoded.length;i++){
      System.out.println(decoded[i]);
	 }
   
	}

    //method decodedRLE
    public static byte[] decodeRLE(byte[] rleData){
    
    //size of the data that has to be decoded
    int n = rleData.length;
    
    //array to store the numbers which represent the repeating data
    byte repeats[] = new byte[n/2];
    
    //array to store the numbers that have to be repeated
    byte data2[] = new byte[n/2];
    
    //size of the new decoded array
    int size = 0;
    
    int j = 0;
    
    //find the repeats
    for(int i=0;i<n;i+=2){
       repeats[j] = rleData[i];
       size += repeats[j];
       j++;
    }
    
    j=0;

    //find the numbers that have to be repeated
    for(int i=1;i<n;i+=2){
       data2[j] = rleData[i];
       j++;
    }
	
	//create new array to store the decoded data
	byte decode[] = new byte[size];
	
	int l=0;
	
	//decode the data
	//use two for loops
	for (int i=0;i<n/2;i++){
	    for(byte k=0;k<repeats[i];k++){
	        decode[l] = data2[i];
	        l++;
	    }
	}
	
	//return the decode array
	return decode;
  }

}
