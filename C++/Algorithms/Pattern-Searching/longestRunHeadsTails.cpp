//To find the longest run of heads or tails from sequence of heads and tails
//a text file is provided
//data.txt-
//HTHHTTTHHTHHHTHTHTHHHHHTTHHHHHHHHHHHHTTTTTTTTTH

#include<iostream>
#include<fstream>
using namespace std; 

// function to find out the maximum repeating 
// character in given string 
void longestRun(ifstream &infile) 
{ 
    char str[100];
    int counth=0,countt=0;
    
    int s=0;
    while(!infile.eof())
    {
        infile >> str[s];
        if(str[s]=='T')
        countt++;
        else
        counth++;
        s++;
    }
    
	int len = s-1;
	int count = 0; 

	// Find the maximum repeating character 
	// starting from str[i] 
	char res = str[0]; 
	for (int i=0; i<len; i++) 
	{ 
		int cur_count = 1; 
		for (int j=i+1; j<len; j++) 
		{ 
			if (str[i] != str[j]) 
				break; 
			cur_count++; 
		} 

		// Update result if required 
		if (cur_count > count) 
		{ 
			count = cur_count; 
			res = str[i]; 
		} 
	} 
	cout<<"Longest sequnece is of "<<res<<"("<<count<<")"<<endl;
    cout<<"Maximum occurence is of: ";
    if(countt > counth)
    cout<<'T';
    else if(counth > countt)
    cout<<'H';
    else cout<<"B";
} 

// Driver code 
int main() 
{ 
	ifstream fin;
	fin.open("data.txt");
	
	longestRun(fin); 
	return 0; 
} 
