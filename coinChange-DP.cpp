#include<bits/stdc++.h>
using namespace std;

int minCoinReq(vector<int> coins, int amount){
    int n = coins.size();
    vector<vector<int>> req(n, vector<int>(amount+1, INT_MAX));

    for(int i = 0; i < n; i++) req[i][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= amount; j++){
            if(i == 0){
                if(j % coins[i] == 0)
                    req[i][j] = j / coins[i];
            } else {
                int exclude = req[i-1][j]; // don't use coin i

                int include = INT_MAX;
                if(coins[i] <= j && req[i][j - coins[i]] != INT_MAX)
                    include = 1 + req[i][j - coins[i]]; // use coin i

                req[i][j] = min(include, exclude);
            }
        }
    }

    // Traceback
    int i = n-1, j = amount;
    cout << "Coins used are : ";
    while(i >= 0 && j > 0){
        if(i > 0 && req[i][j] == req[i-1][j])
            i--;
        else {
            cout << coins[i] << " ";
            j -= coins[i];
        }
    }

    return req[n-1][amount];
}

int main(){
    int n, amount;
    cout << "Enter the no of coins : ";
    cin >> n;
    vector<int> coins(n);
    cout << "\n\nEnter the coin values : ";
    for(int i = 0; i < n; i++) cin >> coins[i];
    cout << "\n\nEnter the amount : ";
    cin >> amount;

    cout << "\n\nMinimum No of coins required is : ";
    cout << minCoinReq(coins, amount);
}