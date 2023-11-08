#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    bool static comp(Item a, Item b)
    {
        return a.weight < b.weight;
    }

    int knapsack(int W, vector<Item> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                if (arr[i - 1].weight > w)
                {
                    dp[i][w] = dp[i - 1][w];
                }
                else
                {
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - arr[i - 1].weight] + arr[i - 1].value);
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
    cout << "Enter the value and weight of each item:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    Solution obj;
    int ans = obj.knapsack(weight, arr);
    cout << "The maximum value is: " << ans << endl;

    return 0;
}