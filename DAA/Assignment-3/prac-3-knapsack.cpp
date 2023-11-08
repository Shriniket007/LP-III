// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Item
// {
//     int weight;
//     int profit;
// };

// bool compareByRatio(const Item &a, const Item &b)
// {
//     return (double)a.profit / a.weight > (double)b.profit / b.weight;
// }

// double fractionalKnapsack(vector<Item> &items, int capacity)
// {
//     sort(items.begin(), items.end(), compareByRatio);

//     double maxValue = 0.0;

//     for (const Item &item : items)
//     {
//         if (capacity <= 0)
//             break;

//         if (item.weight <= capacity)
//         {
//             maxValue += item.profit;
//             capacity -= item.weight;
//         }
//         else
//         {
//             double fraction = (double)capacity / item.weight;
//             maxValue += fraction * item.profit;
//             capacity = 0;
//         }
//     }

//     return maxValue;
// }

// int main()
// {
//     vector<Item> items = {{60, 10}, {100, 20}, {120, 30}}; // (weight, profit) for each item
//     int capacity = 50;                                     // Maximum capacity of the knapsack

//     double max_value = fractionalKnapsack(items, capacity);

//     cout << "Maximum value: " << max_value << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int profit;
};

bool compareByRatio(const Item &a, const Item &b)
{
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}

double fractionalKnapsack(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end(), compareByRatio);

    double maxValue = 0.0;

    for (const Item &item : items)
    {
        if (capacity <= 0)
            break;

        double fraction = min(1.0, (double)capacity / item.weight);
        maxValue += fraction * item.profit;
        capacity -= fraction * item.weight;
    }

    return maxValue;
}

int main()
{
    vector<Item> items = {{18, 25}, {15, 24}, {10, 15}}; // (weight, profit) for each item
    int capacity = 20;                                   // Maximum capacity of the knapsack

    double max_value = fractionalKnapsack(items, capacity);

    cout << "Maximum value: " << max_value << endl;

    return 0;
}
