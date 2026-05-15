#include<bits/stdc++.h>
using namespace std;

int coinChangeWays(vector<int> coins,int amount){
	int n = coins.size();
	
	vector<vector<int>> amnt(n,vector<int>(amount+1,0));
	
	for(int i=0;i<n;i++){
		amnt[i][0] = 1;
	}
	
	for(int i=0;i<n;i++){
		for(int j=1;j<=amount;j++){
			if(i==0){
				if(j%coins[i] == 0){
					amnt[i][j] = 1;
				} 
			}else{
				if(coins[i] <= j){
    				amnt[i][j] = amnt[i-1][j] + amnt[i][j-coins[i]];
				}else{
    				amnt[i][j] = amnt[i-1][j];
				}
			}
		}
	}
	return amnt[n-1][amount];
}

int main(){
	int n,amount;
	
	cout<<"Enter the number of coins : ";
	cin>>n;
	vector<int> coins(n);
	cout<<"Enter the coin values : ";
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	
	cout<<"\n\nEnter the amount : ";
	cin>>amount;
	
	cout<<"No of ways to make amount : ";
	cout<<coinChangeWays(coins,amount);
	
	return 0;
}