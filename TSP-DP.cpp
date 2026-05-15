#include<bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> dist,int n){

    int totalMask = 1 << n;

    vector<vector<int>> dp(totalMask, vector<int>(n, INT_MAX));

    dp[1][0] = 0;

    for(int mask = 1; mask < totalMask; mask++){

        for(int u = 0; u < n; u++){

            if(!(mask & (1 << u)))
                continue;

            if(dp[mask][u] == INT_MAX)
                continue;

            for(int v = 0; v < n; v++){

                if(mask & (1 << v))
                    continue;

                int newMask = mask | (1 << v);

                dp[newMask][v] =
                    min(dp[newMask][v],
                        dp[mask][u] + dist[u][v]);
            }
        }
    }

    int fullMask = totalMask - 1;

    int ans = INT_MAX;
    int lastCity = -1;

    for(int i = 1; i < n; i++){

        if(dp[fullMask][i] != INT_MAX){

            int cost = dp[fullMask][i] + dist[i][0];

            if(cost < ans){

                ans = cost;
                lastCity = i;
            }
        }
    }

    // Path reconstruction
    vector<int> path;

    int mask = fullMask;
    int curr = lastCity;

    while(curr != 0){

        path.push_back(curr);

        int prevCity = -1;

        for(int prev = 0; prev < n; prev++){

            if(prev == curr)
                continue;

            int prevMask = mask ^ (1 << curr);

            if((prevMask & (1 << prev)) &&
               dp[mask][curr] ==
               dp[prevMask][prev] + dist[prev][curr]){

                prevCity = prev;
                break;
            }
        }

        mask = mask ^ (1 << curr);
        curr = prevCity;
    }

    path.push_back(0);

    reverse(path.begin(), path.end());

    cout << "\nTour Path : ";

    for(int city : path)
        cout << city << " -> ";

    cout << "0";

    return ans;
}

int main(){

    int n;

    cout << "Enter number of cities : ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    cout << "\nEnter distance matrix : \n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }

    cout << "\nMinimum Tour Cost : ";
    cout << tsp(dist, n);

    return 0;
}