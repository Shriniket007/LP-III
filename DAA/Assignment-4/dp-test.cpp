#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int profit;
    int weight;
};

class Solution
{
public:
    static bool comp(Item a, Item b)
    {
        double r1 = (double)a.profit / (double)a.weight;
        double r2 = (double)b.profit / (double)b.weight;
        return r1 > r2;
    }

    int knapsack(int W, vector<Item> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int w = 1; w <= W; w++)
            {
                if (arr[i - 1].weight <= w)
                {
                    dp[i][w] = max(arr[i - 1].profit + dp[i - 1][w - arr[i - 1].weight], dp[i - 1][w]);
                }
                else
                {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[n][W];
    }
};

int main()
{
    int n, weight;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity: ";
    cin >> weight;

    vector<Item> arr(n);
    cout << "Enter the profit and weight of each item:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].profit >> arr[i].weight;
    }

    Solution obj;
    int ans = obj.knapsack(weight, arr);
    cout << "The maximum value is " << ans << endl;

    return 0;
}
