#include<bits/stdc++.h>
using namespace std;

#define MAX 256

void badCharHeurastic(string pattern,int m,vector<int> &badchar){
	for(int i=0;i<MAX;i++){
		badchar[i] = -1;
	}
	for(int i=0;i<m;i++){
		badchar[(int)pattern[i]] = i;
	}
}

void boyerMooreSearch(string text,string pattern){
	int n = text.length();
	int m = pattern.length();
	
	vector<int> badchar(MAX);
	badCharHeurastic(pattern,m,badchar);
	
	int shift = 0;
	
	while(shift<=(n-m)){
		int j = m-1;
		while(j>=0 && pattern[j] == text[shift+j]){
			j--;
		}
			if(j<0){
				cout<<"Pattern found at index : "<<shift<<endl;
				
				shift += (shift+m < n) ? m-badchar[text[shift+m]] : 1; 
			}else{
   					shift += max(1,
                         j - badchar[text[shift + j]]);			
			}
		}
}

int main() {
    string text,pattern;

    cout << "Enter Text: ";
    cin >> text;

    cout << "Enter Pattern: ";
    cin >> pattern;

    clock_t start = clock();

    boyerMooreSearch(text, pattern);

    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time taken (seconds): " << time_taken << endl;
    cout << "Time taken (microseconds): " << time_taken * 1e6 << endl;

    return 0;
}