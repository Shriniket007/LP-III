#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> w, vector<int> p, int n)
{
    int capacity = 20;
    vector<double> pr(0);
    double ratio = 0;
    for (int i = 0; i < n; i++)
    {
        ratio = p[i] / w[i];
        pr.push_back(ratio);
    }

    double profit = 0;

    sort(pr.begin(), pr.end());

    for (int i = 1; i <= n; i++)
    {
        if (capacity > 0)
        {
        }
    }
}

int main()
{
    vector<int> w = {18, 15, 20};
    vector<int> p = {25, 24, 15};
    int n = 3;

    cout << knapsack(w, p, n);
    return 0;
}