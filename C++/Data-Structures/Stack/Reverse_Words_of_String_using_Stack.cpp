
#include<bits/stdc++.h>
using namespace std;

//function to reverse the words
//of the given string without using strtok(). 
void reverse(string s)
{
//create an empty string stack
stack<string> stc;

//create an empty temporary string
string temp="";

//traversing the entire string
for(int i=0;i<s.length();i++)
{
	if(s[i]==' ')
	{
	
	//push the temporary variable into the stack
	stc.push(temp); 
	
	//assigning temporary variable as empty
	temp="";		 
	}
	else
	{
	temp=temp+s[i];
	}

}

//for the last word of the string
stc.push(temp);

while(!stc.empty()) {

	// Get the words in reverse order 
	temp=stc.top();
	cout<<temp<<" ";
	stc.pop();
}
cout<<endl;
}

int main()
{
string s;
getline(cin,s);
reverse(s); 
return 0;
}

