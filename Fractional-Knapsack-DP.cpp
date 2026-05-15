#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> value,vector<int> weight,int capacity){
	int n = weight.size();
	
	vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=capacity;j++){
			if(weight[i-1]<=j){
				int include = value[i-1]+dp[i-1][j-weight[i-1]];
				int exclude = dp[i-1][j];
				
				dp[i][j] = max(include,exclude);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	int i=n;
	int j=capacity;
	cout << "\nItems used are : \n";
	while(i>0 && j>0){
		if(dp[i][j]==dp[i-1][j]){
			i--;
		}else{
			cout<<"\nWeight : "<<weight[i-1]<<"\t\tValue : "<<value[i-1]<<endl;
			j = j-weight[i-1];
			i--;
		}
	}
	return dp[n][capacity];
}

int main(){
    int n, capacity;
    cout << "Enter number of items : ";
    cin >> n;
    vector<int> wt(n), val(n);
    cout << "\nEnter weight and value : \n";
    for(int i = 0; i < n; i++){
        cout << "Item "
             << i + 1
             << " (weight value): ";
        cin >> wt[i] >> val[i];
    }
    cout << "\nEnter knapsack capacity : ";
    cin >> capacity;

    int ans = knapsack(val, wt, capacity);

    cout << "\nMaximum Value = "
         << ans
         << endl;

    return 0;
}