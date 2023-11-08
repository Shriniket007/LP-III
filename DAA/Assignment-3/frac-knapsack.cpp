#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> // Include this for the sort function

using namespace std;

struct Item
{
    int profit;
    int weight;
};

class Solution
{
public:
    bool static comp(Item a, Item b)
    {
        double r1 = (double)a.profit / (double)a.weight;
        double r2 = (double)b.profit / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, vector<Item> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);

        int curWeight = 0;
        double finalvalue = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                finalvalue += arr[i].profit;
            }
            else
            {
                int remain = W - curWeight;
                // finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                finalvalue += (double)remain * (arr[i].profit / (double)arr[i].weight);
                break;
            }
        }

        return finalvalue;
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
    double ans = obj.fractionalKnapsack(weight, arr);
    cout << "The maximum value is " << ans << endl;

    return 0;
}

// 25 18
// 24 15
// 15 10