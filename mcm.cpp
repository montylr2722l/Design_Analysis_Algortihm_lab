#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int>& arr)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int length = 2; length < n; length++)
    {
        for(int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + arr[i - 1] * arr[k] * arr[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;

    cout << "Enter number of dimensions: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter dimensions: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int answer = matrixChainMultiplication(arr);

    cout << "Minimum scalar multiplications = "
         << answer << endl;

    return 0;
}
