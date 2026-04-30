#include <iostream>
using namespace std;

#define d 256  // number of characters

void rabinKarp(string txt, string pat, int q) {
    int n = txt.length();
    int m = pat.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // The value of h = pow(d, m-1) % q
    for(i = 0; i < m-1; i++)
        h = (h * d) % q;

    // Calculate initial hash values
    for(i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text
    for(i = 0; i <= n - m; i++) {

        // Check hash values
        if(p == t) {
            // Check characters one by one
            for(j = 0; j < m; j++) {
                if(txt[i+j] != pat[j])
                    break;
            }

            if(j == m)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate next window hash
        if(i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            // Handle negative hash
            if(t < 0)
                t = t + q;
        }
    }
}

int main() {
    cout <<"C243445"<<endl;
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    int q = 101; // a prime number

    rabinKarp(txt, pat, q);

    return 0;
}
