#include<bits/stdc++.h>
using namespace std;

void constructLPS(string &pattern,vector<int> lps){
	int len = 0;
	lps[0] = 0;
	
	
	int i=1;
	while(i<pattern.length()){
		if(pattern[i]==pattern[len]){
			len++;
			lps[i] = len;
			i++;
		}else{
			if(len != 0){
				len = lps[len-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

vector<int> search(string &pattern,string &text){
	int n = text.length();
	int m = pattern.length();
	
	vector<int> lps(m);
	vector<int> res;
	
	constructLPS(pattern,lps);
	
	int i=0;
	int j=0;
	
	while(i<n){
		if(text[i]==pattern[j]){
			i++;
			j++;
			if(j==m){
				res.push_back(i-j);
				j = lps[j-1];
			}
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	return res;
}

int main(){
	string text;
	string pattern;
	cout<<"Enter the String text : ";
	getline(cin,text);
	cout<<"\n\nEnter the string pattern : ";
	getline(cin,pattern);
	cout<<endl;
	
	vector<int> res = search(pattern,text);
	cout<<"Pattern found at : ";
	for(int x : res){
		cout<<x<<" ";
	}
	
}