#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the text: ";
    string text;
    getline(cin, text);

    cout << "Enter the pattern: ";
    string pattern;
    getline(cin, pattern);

    vector<int> pos;

    int n = text.length(), m = pattern.length();

    for(int i = 0; i <= n - m; i++) {
        int j = 0;

        while(j < m && text[i + j] == pattern[j]) {
            j++;
        }

        if(j == m) {
            pos.push_back(i);
        }
    }

    if(pos.empty()) {
        cout << "Pattern not found\n";
    } else {
        cout << "Pattern found at indexes:\n";
        for(int p : pos) {
            cout << p << endl;
        }
    }

    return 0;
}