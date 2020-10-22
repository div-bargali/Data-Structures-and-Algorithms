//using linked list to store strings in an order	

#include <iostream>
using namespace std;

//class node
class node
{
public:
   //data members
   
   //stores string data
   string data;
   
   //pointer to next node
   node* next;
};

//class sortedList 
//the class keeps the nodes in descending order
class sortedList
{
private:

   //data members
   node* listData;
   int length;
   node* currentPos;

public:

   //all the functions will now with string data type
   //so the template brackets will be removed
   //return type and parameters will be changed to string as per requirement of the function
   sortedList();
   void makeEmpty();
   bool isFull();
   int getLength();

   bool findItem(string item);
   
   //function that will put items in descending order
   void putItem(string item);
   
   void deleteItem(string item);
   void resetList();
   string getNextItem();
   void printList();
   
   //functions that have to be added
   
   string findWordEndIn(char endAlphabet);
   string getNth(int n);
   void displayListBackwards();
};

sortedList::sortedList()
{
   length = 0;
   listData = NULL;
   currentPos = NULL;
}

void sortedList::makeEmpty()
{
   node* tempPtr;
   while (listData != NULL)
   {
       tempPtr = listData;
       listData = listData->next;
       delete tempPtr;
   }
   length = 0;

}

bool sortedList::isFull()
{
   node* location;
   try
   {
       location = new node;
       delete location;
       return false;
   }
   catch (std::bad_alloc exception)
   {
       return true;
   }

}

int sortedList::getLength()
{
   return length;
}

//type of item will be mentioned as string
bool sortedList::findItem(string item)
{
   bool moreToSearch;
   node* location;
   location = listData;
   moreToSearch = (location != NULL);

   bool found = false;

   while (moreToSearch && !found)
   {
       if (item == location->data)
       {
           found = true;
           break;
       }
       else if (item > location->data)
       {
           location = location->next;
           moreToSearch = (location != NULL);
       }
       else
       {
           moreToSearch = false;
           break;
       }

   }
  
   return found;
  
}

//this function is modified so that the nodes get inserted in descending order
void sortedList::putItem(string item)
{
    //item is of string data type
   node* newNode;
   node* prevLoc;
   node* location;

   bool moreToSearch;

   location = listData;
   prevLoc = NULL;
   moreToSearch = (location != NULL);

   while (moreToSearch)
   {
       if (item < location->data)
       {
           prevLoc = location;
           location = location->next;
           moreToSearch = (location != NULL);
       }
       else if (item > location->data)
       {
           moreToSearch = false;
           break;
       }
   }
   newNode = new node;
   newNode->data = item;
   if (prevLoc == NULL)
   {
       newNode->next = listData;
       listData = newNode;
   }
   else
   {
       newNode->next = location;
       prevLoc->next = newNode;
   }
   length++;  
}

//item will be of string data type
void sortedList::deleteItem(string item)
{
   node* tempLoc = NULL;
   node* prevLoc;
   node* location;

   location = listData;
   prevLoc = NULL;
   bool moreToSearch = (location != NULL);

   if (item == location->data)
   {
       tempLoc = location;
       listData = listData->next;
   }
   else
   {
       while (moreToSearch)
       {
           if (item == location->data)
           {
               moreToSearch = false;
               tempLoc = location;
               prevLoc->next = location->next;
           }
           else if (item > location->data)
           {
               prevLoc = location;
               location = location->next;
               moreToSearch = (location != NULL);
           }
           else
           {
               moreToSearch = false;
               break;
           }
       }
   }
   delete tempLoc;
   length--;

}

void sortedList::resetList()
{
   currentPos = NULL;
}


string sortedList::getNextItem()
{
   if (currentPos == NULL)
       currentPos = listData;
   else
       currentPos = currentPos->next;
   return currentPos->data;

}


void sortedList::printList()
{  
   //the item will of string data type
   string item;
   resetList();
   for (int i = 0; i < length; i++)
   {
       item = getNextItem();
       cout << item << " ";
   }
   cout << endl;

}


//this function finds the first word in the list
//that ends with a particular letter
string sortedList::findWordEndIn(char endAlphabet)
{
   //initlialize the word to "Not found"
   string word = "Not found";
   
   string item;
   resetList();
   
   //find the word 
   //by traversing the list
   for (int i = 0; i < length; i++)
   {
       item = getNextItem();
       int l = item.length();
      
       //compare the last letter with the letter in the parameter
       if ( endAlphabet == item[l-1])
       {
          //if it matches
          //update word
          //break from the loop
          word = item;
          break;
       }
   }
   
   //return the word
   return word;
}

//helper function, that finds a node at the nth position in the list
string sortedList::getNth(int n) 
{ 
    struct node* curr = listData; 
    for (int i=0; i<n-1 && curr != NULL; i++) 
       curr = curr->next; 
    return curr->data; 
} 

//this function prints the list in reverse manner
//it uses the function getNth()
void sortedList::displayListBackwards( ) 
{ 
    //get the last node
    //then the second last node and so on
    //print the data of the node
    for (int i=length; i>=1; i--) 
        cout<<getNth(i)<<" "; 
} 

int main()
{
    //create object of sortedList
    sortedList L;
    
    //put items in the sortedList object
    L.putItem("cart");
    L.putItem("mart");
    L.putItem("dart");
    L.putItem("part");
    L.putItem("art");
    
    cout<<"Contents of the list are as follows:\n";
    //print the list
    L.printList();
    
    cout<<"\nContents of the list in reverse order:\n";
    //print the list in reverse order
    L.displayListBackwards();
    
    cout<<"\n\nWord ending with 't':";
    //finding first word in the list that ends with 't'
    cout<<L.findWordEndIn('t');
    
    cout<<"\nWord ending with 'c':";
    //finding first word in the list that ends with 'c'
    cout<<L.findWordEndIn('c');
}
