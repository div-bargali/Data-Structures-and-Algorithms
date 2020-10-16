//use of vector

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //creating three vector objects of type int
    vector<int> vec1 = vector<int>();     //default constructor
    vector<int> vec2 = vector<int>(5);    //one parameter constructor
    vector<int> vec3 = vector<int>(5,9);  //two parameter constructor
    
    
    //diplaying size and capacity
    cout<<"Testing default constructor\n";
    cout<<"size:"<<vec1.size()<<" capacity:"<<vec1.capacity()<<endl;
    cout<<"Testing empty member function"<<endl;
    if(vec1.empty())
    cout<<"v is empty"<<endl;
    
    //testing of one parameter constructor
    cout<<"\nTesting one parameter constructor"<<endl;
    cout<<"size:"<<vec2.size()<<" capacity:"<<vec2.capacity()<<endl;
    if(!vec2.empty())
    cout<<"v2 is not empty"<<endl;
    cout<<"Testing at function by diplaying contents of v2"<<endl;
    for(int i=0; i < vec2.size(); i++)
    cout << vec2.at(i) <<" ";
    
    //testing of two parameter constructor
    cout<<"\n\nTesting two parameter constructor"<<endl;
    cout<<"size:"<<vec3.size()<<" capacity:"<<vec3.capacity()<<endl;
    if(!vec3.empty())
    cout<<"v3 is not empty"<<endl;
    cout<<"Testing at function by diplaying contents of v3"<<endl;
    for(int i=0; i < vec3.size(); i++)
    cout<< vec3.at(i)<<" ";
    
    //using push_back on vec1
    cout<<"\n\nTesting push_back() function"<<endl;
    //print the values
    for(int i=0;i<10;i++)
    {
        vec1.push_back(i);
        cout<<"size:"<<vec1.size()<<" capacity:"<<vec1.capacity()<<endl;
    }
    
    //using pop_back on vec1
    cout<<"\nTesting pop_back() function"<<endl;
    vec1.pop_back();
    cout<<"size:"<<vec1.size()<<" capacity:"<<vec1.capacity()<<endl;
    vec1.pop_back();
    cout<<"size:"<<vec1.size()<<" capacity:"<<vec1.capacity()<<endl;
    
    //using front and back on vec1
    cout<<"Testing front and back functions"<<endl;
    cout<<"front:"<<vec1.front()<<" back:"<<vec1.back()<<endl;
    
    //using insert on vec1
    cout<<"\nTesting insert() function by inserting at position 5"<<endl;
    vector<int>::iterator it;
    it = vec1.begin();
    vec1.insert(vec1.begin() + 5,100);
    for(int i=0; i < vec1.size(); i++)
    cout<< vec1.at(i)<<" ";
    
    
    //using erase on vec1
    cout<<"\n\nTesting erase() function by erasing position 6"<<endl;
    vec1.erase(vec1.begin()+6);
    for(int i=0; i < vec1.size(); i++)
    cout<< vec1.at(i)<<" ";
    
    //using resize on vec1
    cout<<"\nTesting resize() function (one parameter)"<<endl;
    vec1.resize(20);
    cout<<"size: "<<vec1.size()<<" capacity: "<<vec1.capacity()<<endl;
    for(int i=0; i < vec1.size(); i++)
    cout<< vec1.at(i)<<" ";
    
    vec1.resize(10);
    cout<<"\nsize: "<<vec1.size()<<" capacity: "<<vec1.capacity()<<endl;
    for(int i=0; i < vec1.size(); i++)
    cout<< vec1.at(i)<<" ";
    
    cout<<"\nTesting resize() function (two parameter)";
    vec1.resize(20,101);
    cout<<"\nsize: "<<vec1.size()<<" capacity: "<<vec1.capacity()<<endl;
    for(int i=0; i < vec1.size(); i++)
    cout<< vec1.at(i)<<" ";
    
    vec1.resize(10);
    cout<<"\nsize: "<<vec1.size()<<" capacity: "<<vec1.capacity()<<endl;
    for(int i=0; i < vec1.size(); i++)
    cout<< vec1.at(i)<<" ";
    
    //using assign on vec1
    cout<<"\n\nTesting assign() function"<<endl;
    vec1.assign(5,102);
    cout<<"size: "<<vec1.size()<<" capacity: "<<vec1.capacity()<<endl;
    for(int i=0; i < vec1.size(); i++)
    cout<< vec1.at(i)<<" ";
    
    //using clear on vec1
    cout<<"\nTesting clear function"<<endl;
    vec1.clear();
    cout<<"size: "<<vec1.size()<<" capacity: "<<vec1.capacity()<<endl;
    
    return 0;
    
}
