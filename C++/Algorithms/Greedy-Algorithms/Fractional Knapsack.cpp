//Fractional Knapsack Problem-greedy method
#include <bits/stdc++.h>
using namespace std;
//Item structure that have value and weight
struct Item
{
    int value, weight;
 // Constructor
    Item(int value, int weight) : value(value), weight(weight)
    {}
};
// Compare function to sort Item according to val/weight ratio
bool compare(struct Item a, struct Item b)
{
    float i1 = (float)a.value / a.weight;
    float i2 = (float)b.value / b.weight;
    return i1 > i2;
}
// Greedy function to solve problem
float fractionalKnapsack(int W, struct Item a[], int n)
{
    //sorting Item on basis of ratio
    sort(a, a + n, compare);

    int current_weight = 0;
    float final_value = 0.0;

    for (int i = 0; i < n; i++)
    {
        // If adding Item won't overflow, add it completely and want to change it
        if (current_weight + a[i].weight <= W)
        {
            current_weight += a[i].weight;
            final_value += a[i].value;
        }

        // If we can't add  current Item totally, add fractional part of it
        else
        {
            int remaining_weight = W - current_weight;
            final_value += a[i].value * ((float) remaining_weight / a[i].weight);
            break;
        }
    }

    return final_value;
}

// driver program
int main()
{
    int W = 40;   //    Weight of knapsack
    Item a[] = {{50, 10}, {100, 20}, {120, 30}};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Maximum value we can get = "<< fractionalKnapsack(W, a, n);
    return 0;
}
