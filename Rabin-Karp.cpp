#include<bits/stdc++.h>
using namespace std;

#define d 256

void rabinKarp(string text, string pattern, int q) {

    int n = text.length();
    int m = pattern.length();

    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // Calculate h = pow(d, m-1) % q
    for(int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate initial hash values
    for(int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide pattern over text
    for(int i = 0; i <= n - m; i++) {

        // If hash values match
        if(p == t) {

            int j;

            // Check characters one by one
            for(j = 0; j < m; j++) {
                if(text[i + j] != pattern[j])
                    break;
            }

            // Pattern found
            if(j == m) {
                cout << "Pattern Found at index : " << i << endl;
            }
        }

        // Calculate next window hash
        if(i < n - m) {

            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Convert negative hash to positive
            if(t < 0)
                t = t + q;
        }
    }
}

int main() {

    string text, pattern;

    cout << "Enter Text: ";
    cin >> text;

    cout << "Enter Pattern: ";
    cin >> pattern;

    int q = 101;

    clock_t start = clock();

    rabinKarp(text, pattern, q);

    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time taken (seconds): " << time_taken << endl;

    cout << "Time taken (microseconds): "
         << time_taken * 1e6 << endl;

    return 0;
}