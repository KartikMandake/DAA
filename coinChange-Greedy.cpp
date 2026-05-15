#include<bits/stdc++.h>
using namespace std;

void greedyCoinChange(vector<int> &coins,int amount){
	sort(coins.begin(),coins.end(),greater<int>());
	
	vector<int> usedCoins;
	int count = 0;
	int n = coins.size();
	for(int i=0;i<n && amount>0;i++){
		while(amount>=coins[i]){
			amount -= coins[i];
			usedCoins.push_back(coins[i]);
			count++;
		}
	}
	if(amount != 0){
		cout<<"Can not make the target amount using given coins ";
		cout<<endl;
	}else{
		cout<<"\n\nCoins used are : ";
		for(int coins : usedCoins){
			cout<<coins<<" ";
		}
		cout<<"\n\nNumber of coins used are : "<<count<<endl;
	}	
}

int main(){
	int n,amount;
	
	cout<<"Enter the number of coins :";
	cin>>n;
	vector<int> coins(n);
	cout<<"\n\nEnter the coin Values : ";
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	
	cout<<"\n\nEnter the amount : ";
	cin>>amount;
	
	greedyCoinChange(coins,amount);
	
	return 0;
}