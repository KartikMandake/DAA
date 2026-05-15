#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

// Function for Matrix Chain Multiplication
int matrixChainMultiplication(vector<int>& p, int n)
{
    // DP table
    vector<vector<int>> dp(
        n, vector<int>(n, 0));

    // l = chain length
    for(int l = 2; l < n; l++)
    {
        for(int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;

            dp[i][j] = INT_MAX;

            // Try all possible places
            // to split the chain
            for(int k = i; k < j; k++)
            {
                int cost =
                    dp[i][k]
                    +
                    dp[k + 1][j]
                    +
                    p[i - 1] * p[k] * p[j];

                if(cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // Print DP Table
    cout << "\nDP Table:\n\n";

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(j < i)
                cout << setw(8) << "-";
            else
                cout << setw(8) << dp[i][j];
        }

        cout << endl;
    }

    return dp[1][n - 1];
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    // Dimension array
    vector<int> p(n + 1);

    cout << "Enter dimensions array:\n";

    for(int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    int result =
        matrixChainMultiplication(
            p, n + 1);

    cout << "\nMinimum number of multiplications is: "
         << result << endl;

    return 0;
}