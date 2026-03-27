#include <iostream>
#include <algorithm>
using namespace std;
struct Activity {
    int start, finish;
};
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(Activity arr[], int n) {
    sort(arr, arr + n, compare);

    cout << "Selected activities:\n";
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")\n";
    for(int j = 1; j < n; j++) {
        if(arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")\n";
            i = j;
        }
    }
}
int main() {
    cout<<"C243445"<<endl;
    Activity arr[] = {
        {1, 3}, {2, 5}, {4, 6},
        {6, 7}, {5, 8}, {8, 9}
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    activitySelection(arr, n);
    return 0;
}
