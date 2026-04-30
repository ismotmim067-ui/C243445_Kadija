#include <iostream>
using namespace std;

int rodCutting(int price[], int n) {
    int dp[n+1];
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        int maxVal = -1;

        for(int j = 1; j <= i; j++) {
            maxVal = max(maxVal, price[j-1] + dp[i-j]);
        }

        dp[i] = maxVal;
    }

    return dp[n];
}

int main() {
    cout <<"C243445"<<endl;
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;

    cout << "Maximum Revenue = " << rodCutting(price, n);

    return 0;
}
