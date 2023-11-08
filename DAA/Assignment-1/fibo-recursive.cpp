#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fibo_recursive(int n)
{
    // base case
    if (n == 1 || n == 0)
    {
        return n;
    }

    // recursive call
    int next = fibo_recursive(n - 1) + fibo_recursive(n - 2);
    return next;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "The fibonacci series is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << fibo_recursive(i) << " ";
    }

    return 0;
}

// Time Complexity: O(2^n)
// Space Complexity: O(n) (due to the function call stack)