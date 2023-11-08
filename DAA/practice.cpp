#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit;
    int weight;
};

bool comp(Item a, Item b)
{
    return a.weight < b.weight;
}

int Knapsack(int W, vector<Item> &arr)
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
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - arr[i - 1].weight] + arr[i - 1].profit);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    vector<Item> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].profit >> arr[i].weight;
    }

    cout << Knapsack(capacity, arr);
    return 0;
}