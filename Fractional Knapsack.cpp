#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, compare);

    double totalValue = 0.0;

    for(int i = 0; i < n; i++) {
        if(arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    cout<<"C243445"<<endl;
    Item arr[] = {
        {60, 10}, {100, 20}, {120, 30}
    };

    int W = 50;
    int n = sizeof(arr) / sizeof(arr[0]);

    double maxValue = fractionalKnapsack(W, arr, n);
    cout << "Maximum value: " << maxValue;
    return 0;
}
