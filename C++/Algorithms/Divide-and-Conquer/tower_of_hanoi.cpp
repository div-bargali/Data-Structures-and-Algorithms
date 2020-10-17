#include <iostream> 
using namespace std; 
  
void tower_of_hanoi(int n, char from_rod, char to_rod, char tmp_rod) {  
    if (n == 1) {  
        cout << "Move disk 1 from rod " << from_rod <<  " to rod " << to_rod << endl;  
        return;  
    }  
    tower_of_hanoi(n - 1, from_rod, tmp_rod, to_rod);  
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;  
    tower_of_hanoi(n - 1, tmp_rod, to_rod, from_rod);  
}  

int main() {  
    int n; // Number of disks  
    cout << "Enter the no. of disks : ";
    cin >> n;
    tower_of_hanoi(n, 'X', 'Z', 'Y'); 
    // 'X' - name of from_rod
    // 'Z' - name of to_rod
    // 'Y' - name of tmp_rod
    return 0;
}  