#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (wt[i - 1] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int profit[] = {25, 24, 15};
    int weight[] = {18, 15, 10};
    int W = 20;
    int n = sizeof(profit) / sizeof(profit[0]);

    vector<int> val(profit, profit + n);
    vector<int> wt(weight, weight + n);

    cout << "Maximum value: " << knapsack(W, wt, val, n) << endl;
    return 0;
}
